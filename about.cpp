/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/***************************************************************************
 *            about.cpp
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
#include "about.h"

#include <stdio.h>
#include <QApplication>
#include <QDesktopWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QTabWidget>
#include <QScrollArea>
#include <QFile>

About::About(QSettings *settings, QWidget *parent) : QDialog(parent)
{
  this->settings = settings;

  setFixedSize(450, 400);
  setWindowIcon(QIcon(":icon.png"));
  setWindowTitle("SantaCandle v."VERSION", www.santacandle.dk");

  move(QApplication::desktop()->width() / 2 - 225, QApplication::desktop()->height() / 2 - 200);
  // About tab
  QWidget *aboutWidget = new QWidget;
  QLabel *aboutText = new QLabel(tr("Merry Christmas! And welcome to your very own virtual christmas candle. This candle will help you count the days of December until we reach the 24th. It is now your responsibility to keep an eye out for the candle whenever it is lit. But be careful! If you forget to turn it off, the whole thing might catch fire!\n\n"
				   "Whenever you turn it off and later turn it back on again, it will come back just the way you left it. In other words, this candle works exactly the same way a real candle would.\n\n"
				   "Functions:\n- You can move the candle around your desktop by left-clicking and dragging.\n- Double-clicking the candle will annoy the gnomes.\n- Right-clicking the candle or the tray icon brings up a menu:\n  - Ignite: Re-ignite flame.\n  - Blow out: Blow out the candle.\n  - About: Show this about box.\n  - Quit: Blow out the candle and remove it from the desktop.\n\nIf your friends / colleagues become envious and would like a candle of their own, simply ask them to visit http://www.santacandle.dk and download it. You can also download the full source code in there if you like. This software is COMPLETELY FREE and OPEN SOURCE (GPLv3)."));
  aboutText->setWordWrap(true);
  aboutText->setMaximumWidth(400);

  QVBoxLayout *aboutLayout = new QVBoxLayout();
  aboutLayout->addWidget(aboutText);
  aboutWidget->setLayout(aboutLayout);

  QScrollArea *aboutScroll = new QScrollArea();
  aboutScroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  aboutScroll->setWidget(aboutWidget);

  // Author tab
  QWidget *authorWidget = new QWidget;
  QLabel *authorText = new QLabel(tr("Programming: Lars Muldjord\nGraphics: Lars Muldjord\n\nThe candle was programmed using the Qt framework (http://www.qt-project.org) and C++.\n\nBug reports, suggestions and / or comments can be emailed to me at:\nmuldjordlars@gmail.com.\n\nIf your friends / colleagues would like to get their own SantaCandle, tell them to visit:\n\nhttp://www.santacandle.dk\n\nIt's FREE and OPEN SOURCE (GPLv3), so there's absolutely no strings attached, just download away. You can also download the full source code in there if you like.\n\nCopyright 2012 Lars Muldjord. This software is distributed under the terms of the GNU General Public License. Be sure to read the license in the 'License' tab or check out the web page http://www.gnu.org/licenses/gpl-3.0.html."));
  authorText->setWordWrap(true);
  authorText->setMaximumWidth(400);

  QVBoxLayout *authorLayout = new QVBoxLayout();
  authorLayout->addWidget(authorText);
  authorWidget->setLayout(authorLayout);

  QScrollArea *authorScroll = new QScrollArea();
  authorScroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  authorScroll->setWidget(authorWidget);

  // License tab
  // Read COPYING data from file
  QFile file("COPYING.TXT");
  QByteArray gplText;
  if(file.open(QIODevice::ReadOnly)) {
    gplText = file.readAll();
    file.close();
  } else {
    printf("ERROR: Couldn't find COPYING file at the designated location.\n");
    gplText = "ERROR: File not found... This means that someone has been fiddling with the files of this software, and someone might be violating the terms of the GPL. Go to the following location to read the license: http://www.gnu.org/licenses/gpl-3.0.html";
  }

  QWidget *licenseWidget = new QWidget;
  QLabel *licenseText = new QLabel(gplText);
  licenseText->setWordWrap(true);
  licenseText->setMaximumWidth(400);

  QVBoxLayout *licenseLayout = new QVBoxLayout();
  licenseLayout->addWidget(licenseText);
  licenseWidget->setLayout(licenseLayout);

  QScrollArea *licenseScroll = new QScrollArea();
  licenseScroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  licenseScroll->setWidget(licenseWidget);


  //QWidget *authorWidget = new QWidget;
  //QWidget *licenseWidget = new QWidget;
  
  QTabWidget *tabWidget = new QTabWidget;
  tabWidget->addTab(aboutScroll, tr("About"));
  tabWidget->addTab(authorScroll, tr("Author"));
  tabWidget->addTab(licenseScroll, tr("License"));
  
  QPushButton *okButton = new QPushButton(tr("Ok"));
  connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));

  QCheckBox *showAgain = new QCheckBox(tr("Show this on startup"));
  connect(showAgain, SIGNAL(stateChanged(int)), this, SLOT(handleAgain(int)));
  if (settings->value("show_welcome") == "true")
    showAgain->setCheckState(Qt::Checked);

  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(tabWidget);
  layout->addWidget(showAgain);
  layout->addWidget(okButton);
  setLayout(layout);

}

About::~About()
{
}

void About::handleAgain(int state)
{
  if(state == Qt::Checked) {
    settings->setValue("show_welcome", "true");
  } else {
    settings->setValue("show_welcome", "false");
  }
}
