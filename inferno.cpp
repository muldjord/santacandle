/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/***************************************************************************
 *            inferno.cpp
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
#include "inferno.h"

#include <stdio.h>
#include <QTimer>

Inferno::Inferno(QWidget *parent) : QLabel(parent)
{
  candle_inferno_frame1.load(":candle_inferno_frame1.png");
  candle_inferno_frame2.load(":candle_inferno_frame2.png");
  candle_inferno_frame3.load(":candle_inferno_frame3.png");
  candle_inferno_frame4.load(":candle_inferno_frame4.png");
  candle_inferno_frame5.load(":candle_inferno_frame5.png");
  candle_inferno_frame6.load(":candle_inferno_frame6.png");

  animTimer.setInterval(100);
  animTimer.setSingleShot(true);
  connect(&animTimer, SIGNAL(timeout()), this, SLOT(nextFrame()));
}

Inferno::~Inferno()
{
}

void Inferno::nextFrame() {
  if (curFrame > 6) {
    curFrame = 1;
  }
  switch (curFrame) {
  case 1:
    setPixmap(candle_inferno_frame1);
    break;
  case 2:
    setPixmap(candle_inferno_frame2);
    break;
  case 3:
    setPixmap(candle_inferno_frame3);
    break;
  case 4:
    setPixmap(candle_inferno_frame4);
    break;
  case 5:
    setPixmap(candle_inferno_frame5);
    break;
  case 6:
    setPixmap(candle_inferno_frame6);
    break;
  default:
    break;
  }
  curFrame++;
  animTimer.start();
}

void Inferno::startAnim() {
  show();
  curFrame = 1;
  nextFrame();
}
