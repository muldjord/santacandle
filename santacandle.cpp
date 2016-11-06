/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/***************************************************************************
 *            santacandle.cpp
 *
 *  Sat Nov 24 14:02:00 CEST 2012
 *  Copyright 2012 Lars Muldjord
 *  muldjordlars@gmail.com
 ****************************************************************************/

/*
 *  This file is part of SantaCandle.
 *
 *  SantaCandle is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  SantaCandle is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with SantaCandle; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.
 */
#include "santacandle.h"
#include "about.h"

#include <stdio.h>
#include <QApplication>
#include <QDesktopWidget>
#include <QLabel>
#include <QApplication>
#include <QMessageBox>

SantaCandle::SantaCandle()
{
  settings = new QSettings("config.ini", QSettings::IniFormat);
  int burnDelay = settings->value("burn_delay", 470000).toInt();
  int flameLocation = settings->value("flame_location", 6).toInt();
  move(settings->value("candlex", QApplication::desktop()->width() / 2 - 250).toInt(), settings->value("candley", QApplication::desktop()->height() / 2 - 410).toInt());
  flameOldX = this->pos().x();
  if (!settings->contains("show_welcome"))
      settings->setValue("show_welcome", "true");

  QString showWelcome = settings->value("show_welcome", "true").toString();
  if (showWelcome == "true") {
    About about(settings, this);
    about.exec();
  }
  
  setFixedSize(500, 820);

  setAttribute(Qt::WA_TranslucentBackground);
  setWindowFlags(Qt::FramelessWindowHint|Qt::SubWindow);

  createActions();
  createTrayIcon();
  trayIcon->show();
  connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
	  this, SLOT(trayActivated(QSystemTrayIcon::ActivationReason)));

  pixies = new Pixies(this);
  pixies->setFixedSize(128, 200);

  candle = new QLabel(this);
  candle->setStyleSheet("background-image: url(:candle.png);"
                        "background-position: left bottom;");
  candle->setFixedSize(102, 517 - flameLocation);
  candle->move(199, 70 + flameLocation);

  flame = new CandleFlame(this);
  flame->setFixedSize(104, 159);
  flame->move(198, flameLocation + 4);

  candleBase.load(":base.png");

  QLabel *base = new QLabel(this);
  base->setPixmap(candleBase);
  base->setFixedSize(500, 302);
  base->move(0, 518);

  inferno = new Inferno(this);
  inferno->setFixedSize(500, 420);
  inferno->move(0, 350);

  connect(&burner, SIGNAL(timeout()), this, SLOT(burn()));
  burner.setInterval(burnDelay);
  burner.setSingleShot(true);
  burner.start();

  connect(&pixieTimer, SIGNAL(timeout()), this, SLOT(showPixie()));
  pixieTimer.setInterval((qrand() % 15000) + 5000);
  pixieTimer.start();

  connect(&physTimer, SIGNAL(timeout()), this, SLOT(flamePhysics()));
  physTimer.setInterval(100);
  physTimer.start();
}

SantaCandle::~SantaCandle()
{
  delete trayIcon;
}

void SantaCandle::burn()
{
  // When flame reaches candle base, stop burning, ignite inferno
  if (flame->y() >= 510) { 
    burner.stop();
    pixieTimer.stop();
    inferno->startAnim();
    trayIconMenu->clear();
    trayIconMenu->addAction(aboutAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(quitAction);
    return;
  }

  settings->setValue("flame_location", flame->y());
  flame->move(flame->x(), flame->y() + 1);
  candle->setFixedSize(candle->width(), candle->height() - 1);
  candle->move(candle->x(), candle->y() + 1);
  burner.start();
}

void SantaCandle::mousePressEvent(QMouseEvent* event)
{
  if(event->type() == QEvent::MouseButtonDblClick)
    {
      showPixie();
    }
  if(event->button() == Qt::RightButton)
    {
      trayIconMenu->exec(QCursor::pos());
    }
  if(event->button() == Qt::LeftButton)
    {
      mMoving = true;
      mLastMousePosition = event->globalPos();
    }
}

void SantaCandle::mouseMoveEvent(QMouseEvent* event)
{
  if( event->buttons().testFlag(Qt::LeftButton) && mMoving)
    {
      this->move(this->pos() + (event->globalPos() - mLastMousePosition));
      mLastMousePosition = event->globalPos();
    }
}

void SantaCandle::mouseReleaseEvent(QMouseEvent* event)
{
  if(event->button() == Qt::LeftButton)
    {
      mMoving = false;
      settings->setValue("candlex", this->pos().x());
      settings->setValue("candley", this->pos().y());
    }
}

void SantaCandle::trayActivated(QSystemTrayIcon::ActivationReason reason)
{
  // If systray icon is dblclicked, show window
  if(reason == QSystemTrayIcon::DoubleClick) activateWindow();
}

void SantaCandle::createActions()
{
  igniteAction = new QAction(tr("&Ignite"), this);
  igniteAction->setIcon(QIcon(":icon_ignite.png"));
  igniteAction->setEnabled(false);
  connect(igniteAction, SIGNAL(triggered()), this, SLOT(ignite()));

  blowOutAction = new QAction(tr("&Blow out"), this);
  blowOutAction->setIcon(QIcon(":icon_blowout.png"));
  connect(blowOutAction, SIGNAL(triggered()), this, SLOT(blowOut()));

  aboutAction = new QAction(tr("&About..."), this);
  aboutAction->setIcon(QIcon(":icon_about.png"));
  connect(aboutAction, SIGNAL(triggered()), this, SLOT(aboutBox()));

  frontAction = new QAction(tr("&Bring to front"), this);
  frontAction->setIcon(QIcon(":icon_front.png"));
  connect(frontAction, SIGNAL(triggered()), this, SLOT(bringToFront()));

  quitAction = new QAction(tr("&Quit"), this);
  quitAction->setIcon(QIcon(":icon_quit"));
  connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
}

void SantaCandle::createTrayIcon()
{
  trayIconMenu = new QMenu(this);
  trayIconMenu->addAction(igniteAction);
  trayIconMenu->addAction(blowOutAction);
  trayIconMenu->addAction(frontAction);
  trayIconMenu->addSeparator();
  trayIconMenu->addAction(aboutAction);
  trayIconMenu->addSeparator();
  trayIconMenu->addAction(quitAction);

  trayIcon = new QSystemTrayIcon(this);
  QIcon icon(":icon.png");
  trayIcon->setToolTip("Santa Candle");
  trayIcon->setIcon(icon);
  trayIcon->setContextMenu(trayIconMenu);
}

void SantaCandle::blowOut()
{
  igniteAction->setEnabled(true);
  blowOutAction->setEnabled(false);
  flame->stopAnim(1);
  burner.stop();
}

void SantaCandle::ignite()
{
  igniteAction->setEnabled(false);
  blowOutAction->setEnabled(true);
  flame->startAnim();
  burner.start();
}

void SantaCandle::aboutBox()
{
  About about(settings, this);
  about.exec();
}

void SantaCandle::bringToFront()
{
  activateWindow();
}

void SantaCandle::showPixie()
{
  pixies->startAnim(flame->y());
  // At the most 5 minutes, at the least 1 minute between pixies
  pixieTimer.setInterval((qrand() % 240000) + 60000);
}

void SantaCandle::flamePhysics()
{
  int moveDistance = this->pos().x() - flameOldX;

  // Blow out the candle if you move it radically on the desktop.
  if (moveDistance < -200 || moveDistance > 200) {
    printf("DEBUG: Blowing out candle...\n");
    igniteAction->setEnabled(true);
    blowOutAction->setEnabled(false);
    flame->stopAnim(8);
    burner.stop();
  }

  // Make the flame flicker left or right when moved around the desktop.
  if (moveDistance > 100) {
    flame->moveRight(1);
  } else if (moveDistance > 80) {
    flame->moveRight(2);
  } else if (moveDistance > 60) {
    flame->moveRight(3);
  } else if (moveDistance > 40) {
    flame->moveRight(4);
  } else if (moveDistance > 20) {
    flame->moveRight(5);
  } else if (moveDistance > 0) {
    flame->moveRight(6);
  } else if (moveDistance < -100) {
    flame->moveLeft(1);
  } else if (moveDistance < -80) {
    flame->moveLeft(2);
  } else if (moveDistance < -60) {
    flame->moveLeft(3);
  } else if (moveDistance < -40) {
    flame->moveLeft(4);
  } else if (moveDistance < -20) {
    flame->moveLeft(5);
  } else if (moveDistance < 0) {
    flame->moveLeft(6);
  }
  flameOldX = this->pos().x();
}
