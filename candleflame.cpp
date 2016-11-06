/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/***************************************************************************
 *            candleflame.cpp
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
#include "candleflame.h"

#include <stdio.h>
#include <QTimer>

#define FLAME 0
#define BLOWOUT 1
#define IGNITE 2
#define LEFT 3
#define RIGHT 4

CandleFlame::CandleFlame(QWidget *parent) : QLabel(parent)
{
  //setStyleSheet("background-image: url(:candle_flame_frame1.png);");

  candle_right_frame1.load(":candle_right_frame1.png");
  candle_right_frame2.load(":candle_right_frame2.png");
  candle_right_frame3.load(":candle_right_frame3.png");
  candle_right_frame4.load(":candle_right_frame4.png");
  candle_right_frame5.load(":candle_right_frame5.png");
  candle_right_frame6.load(":candle_right_frame6.png");
  candle_left_frame1.load(":candle_left_frame1.png");
  candle_left_frame2.load(":candle_left_frame2.png");
  candle_left_frame3.load(":candle_left_frame3.png");
  candle_left_frame4.load(":candle_left_frame4.png");
  candle_left_frame5.load(":candle_left_frame5.png");
  candle_left_frame6.load(":candle_left_frame6.png");
  candle_ignite_frame1.load(":candle_ignite_frame1.png");
  candle_ignite_frame2.load(":candle_ignite_frame2.png");
  candle_ignite_frame3.load(":candle_ignite_frame3.png");
  candle_ignite_frame4.load(":candle_ignite_frame4.png");
  candle_flame_off.load(":candle_flame_off.png");
  candle_blowout_frame1.load(":candle_blowout_frame1.png");
  candle_blowout_frame2.load(":candle_blowout_frame2.png");
  candle_blowout_frame3.load(":candle_blowout_frame3.png");
  candle_blowout_frame4.load(":candle_blowout_frame4.png");
  candle_blowout_frame5.load(":candle_blowout_frame5.png");
  candle_blowout_frame6.load(":candle_blowout_frame6.png");
  candle_blowout_frame7.load(":candle_blowout_frame7.png");
  candle_flame_frame1.load(":candle_flame_frame1.png");
  candle_flame_frame2.load(":candle_flame_frame2.png");
  candle_flame_frame3.load(":candle_flame_frame3.png");
  candle_flame_frame4.load(":candle_flame_frame4.png");
  candle_flame_frame5.load(":candle_flame_frame5.png");
  candle_flame_frame6.load(":candle_flame_frame6.png");
  candle_flame_frame7.load(":candle_flame_frame7.png");
  candle_flame_frame8.load(":candle_flame_frame8.png");

  curFrame = 1;
  curAnim = FLAME;

  animTimer.setInterval(100);
  animTimer.setSingleShot(true);
  connect(&animTimer, SIGNAL(timeout()), this, SLOT(nextFrame()));
  animTimer.start();
}

CandleFlame::~CandleFlame()
{
}

void CandleFlame::nextFrame() {
  if(curAnim == LEFT) {
    if (curFrame > 6) {
      curAnim = FLAME;
    }
    switch (curFrame) {
    case 1:
      setPixmap(candle_right_frame1);
      break;
    case 2:
      setPixmap(candle_right_frame2);
      break;
    case 3:
      setPixmap(candle_right_frame3);
      break;
    case 4:
      setPixmap(candle_right_frame4);
      break;
    case 5:
      setPixmap(candle_right_frame5);
      break;
    case 6:
      setPixmap(candle_right_frame6);
      break;
    default:
      break;
    }
    curFrame++;
    animTimer.setInterval(100);
    animTimer.start();
  }

  if(curAnim == RIGHT) {
    if (curFrame > 6) {
      curAnim = FLAME;
    }
    switch (curFrame) {
    case 1:
      setPixmap(candle_left_frame1);
      break;
    case 2:
      setPixmap(candle_left_frame2);
      break;
    case 3:
      setPixmap(candle_left_frame3);
      break;
    case 4:
      setPixmap(candle_left_frame4);
      break;
    case 5:
      setPixmap(candle_left_frame5);
      break;
    case 6:
      setPixmap(candle_left_frame6);
      break;
    default:
      break;
    }
    curFrame++;
    animTimer.setInterval(100);
    animTimer.start();
  }

  if(curAnim == IGNITE) {
    if (curFrame > 4) {
      curAnim = FLAME;
    }
    switch (curFrame) {
    case 1:
      setPixmap(candle_ignite_frame1);
      break;
    case 2:
      setPixmap(candle_ignite_frame2);
      break;
    case 3:
      setPixmap(candle_ignite_frame3);
      break;
    case 4:
      setPixmap(candle_ignite_frame4);
      break;
    default:
      break;
    }
    curFrame++;
    animTimer.setInterval(100);
    animTimer.start();
  }

  if(curAnim == BLOWOUT) {
    if (curFrame > 7) {
      setPixmap(candle_flame_off);
      animTimer.stop();
    }
    switch (curFrame) {
    case 1:
      setPixmap(candle_blowout_frame1);
      break;
    case 2:
      setPixmap(candle_blowout_frame2);
      break;
    case 3:
      setPixmap(candle_blowout_frame3);
      break;
    case 4:
      setPixmap(candle_blowout_frame4);
      break;
    case 5:
      setPixmap(candle_blowout_frame5);
      break;
    case 6:
      setPixmap(candle_blowout_frame6);
      break;
    case 7:
      setPixmap(candle_blowout_frame7);
      break;
    default:
      break;
    }
    curFrame++;
    animTimer.setInterval(100);
    animTimer.start();
  }

  if(curAnim == FLAME) {
    curFrame = qrand() % 8;
    switch (curFrame) {
    case 1:
      setPixmap(candle_flame_frame1);
      break;
    case 2:
      setPixmap(candle_flame_frame2);
      break;
    case 3:
      setPixmap(candle_flame_frame3);
      break;
    case 4:
      setPixmap(candle_flame_frame4);
      break;
    case 5:
      setPixmap(candle_flame_frame5);
      break;
    case 6:
      setPixmap(candle_flame_frame6);
      break;
    case 7:
      setPixmap(candle_flame_frame7);
      break;
    case 8:
      setPixmap(candle_flame_frame8);
      break;
    default:
      break;
    }
    animTimer.setInterval((qrand() % 100) + 50);
    animTimer.start();
  }
}

void CandleFlame::startAnim()
{
  curFrame = 1;
  curAnim = IGNITE;
  animTimer.start();
}

void CandleFlame::stopAnim(int frame)
{
  curFrame = frame;
  curAnim = BLOWOUT;
}

void CandleFlame::moveLeft(int frame)
{
  if (curAnim == BLOWOUT) return;
  curFrame = frame;
  curAnim = LEFT;
}

void CandleFlame::moveRight(int frame)
{
  if (curAnim == BLOWOUT) return;
  curFrame = frame;
  curAnim = RIGHT;
}
