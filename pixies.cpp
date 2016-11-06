/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/***************************************************************************
 *            pixies.cpp
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
#include "pixies.h"

#include <stdio.h>
#include <QTimer>

#define PIXIE1 0
#define PIXIE2 1
#define PIXIE3 2
#define PIXIE4 3

Pixies::Pixies(QWidget *parent) : QLabel(parent)
{
  pixie1_frame1.load(":pixie1_frame1.png");
  pixie1_frame2.load(":pixie1_frame2.png");
  pixie1_frame3.load(":pixie1_frame3.png");
  pixie1_frame4.load(":pixie1_frame4.png");
  pixie1_frame5.load(":pixie1_frame5.png");
  pixie1_frame6.load(":pixie1_frame6.png");
  pixie1_frame7.load(":pixie1_frame7.png");
  pixie1_frame8.load(":pixie1_frame8.png");
  pixie1_frame9.load(":pixie1_frame9.png");
  pixie1_frame10.load(":pixie1_frame10.png");
  pixie2_frame1.load(":pixie2_frame1.png");
  pixie2_frame2.load(":pixie2_frame2.png");
  pixie2_frame3.load(":pixie2_frame3.png");
  pixie2_frame4.load(":pixie2_frame4.png");
  pixie2_frame5.load(":pixie2_frame5.png");
  pixie2_frame6.load(":pixie2_frame6.png");
  pixie2_frame7.load(":pixie2_frame7.png");
  pixie2_frame8.load(":pixie2_frame8.png");
  pixie2_frame9.load(":pixie2_frame9.png");
  pixie2_frame10.load(":pixie2_frame10.png");
  pixie3_frame1.load(":pixie3_frame1.png");
  pixie3_frame2.load(":pixie3_frame2.png");
  pixie3_frame3.load(":pixie3_frame3.png");
  pixie3_frame4.load(":pixie3_frame4.png");
  pixie3_frame5.load(":pixie3_frame5.png");
  pixie3_frame6.load(":pixie3_frame6.png");
  pixie3_frame7.load(":pixie3_frame7.png");
  pixie3_frame8.load(":pixie3_frame8.png");
  pixie3_frame9.load(":pixie3_frame9.png");
  pixie3_frame10.load(":pixie3_frame10.png");
  pixie4_frame1.load(":pixie4_frame1.png");
  pixie4_frame2.load(":pixie4_frame2.png");
  pixie4_frame3.load(":pixie4_frame3.png");
  pixie4_frame4.load(":pixie4_frame4.png");
  pixie4_frame5.load(":pixie4_frame5.png");
  pixie4_frame6.load(":pixie4_frame6.png");
  pixie4_frame7.load(":pixie4_frame7.png");
  pixie4_frame8.load(":pixie4_frame8.png");
  pixie4_frame9.load(":pixie4_frame9.png");
  pixie4_frame10.load(":pixie4_frame10.png");

  animTimer.setInterval(100);
  animTimer.setSingleShot(true);
  connect(&animTimer, SIGNAL(timeout()), this, SLOT(nextFrame()));
}

Pixies::~Pixies()
{
}

void Pixies::nextFrame() {
  if(curAnim == PIXIE1) {
    if (curFrame > 10) {
      animTimer.stop();
      hide();
      return;
    }
    switch (curFrame) {
    case 1:
      setPixmap(pixie1_frame1);
      break;
    case 2:
      setPixmap(pixie1_frame2);
      break;
    case 3:
      setPixmap(pixie1_frame3);
      break;
    case 4:
      setPixmap(pixie1_frame4);
      break;
    case 5:
      setPixmap(pixie1_frame5);
      break;
    case 6:
      setPixmap(pixie1_frame6);
      break;
    case 7:
      setPixmap(pixie1_frame7);
      break;
    case 8:
      setPixmap(pixie1_frame8);
      break;
    case 9:
      setPixmap(pixie1_frame9);
      break;
    case 10:
      setPixmap(pixie1_frame10);
      break;
    default:
      break;
    }
  }
  if(curAnim == PIXIE2) {
    if (curFrame > 10) {
      animTimer.stop();
      hide();
      return;
    }
    switch (curFrame) {
    case 1:
      setPixmap(pixie2_frame1);
      break;
    case 2:
      setPixmap(pixie2_frame2);
      break;
    case 3:
      setPixmap(pixie2_frame3);
      break;
    case 4:
      setPixmap(pixie2_frame4);
      break;
    case 5:
      setPixmap(pixie2_frame5);
      break;
    case 6:
      setPixmap(pixie2_frame6);
      break;
    case 7:
      setPixmap(pixie2_frame7);
      break;
    case 8:
      setPixmap(pixie2_frame8);
      break;
    case 9:
      setPixmap(pixie2_frame9);
      break;
    case 10:
      setPixmap(pixie2_frame10);
      break;
    default:
      break;
    }
  }
  if(curAnim == PIXIE3) {
    if (curFrame > 10) {
      animTimer.stop();
      hide();
      return;
    }
    switch (curFrame) {
    case 1:
      setPixmap(pixie3_frame1);
      break;
    case 2:
      setPixmap(pixie3_frame2);
      break;
    case 3:
      setPixmap(pixie3_frame3);
      break;
    case 4:
      setPixmap(pixie3_frame4);
      break;
    case 5:
      setPixmap(pixie3_frame5);
      break;
    case 6:
      setPixmap(pixie3_frame6);
      break;
    case 7:
      setPixmap(pixie3_frame7);
      break;
    case 8:
      setPixmap(pixie3_frame8);
      break;
    case 9:
      setPixmap(pixie3_frame9);
      break;
    case 10:
      setPixmap(pixie3_frame10);
      break;
    default:
      break;
    }
  }
  if(curAnim == PIXIE4) {
    if (curFrame > 10) {
      animTimer.stop();
      hide();
      return;
    }
    switch (curFrame) {
    case 1:
      setPixmap(pixie4_frame1);
      break;
    case 2:
      setPixmap(pixie4_frame2);
      break;
    case 3:
      setPixmap(pixie4_frame3);
      break;
    case 4:
      setPixmap(pixie4_frame4);
      break;
    case 5:
      setPixmap(pixie4_frame5);
      break;
    case 6:
      setPixmap(pixie4_frame6);
      break;
    case 7:
      setPixmap(pixie4_frame7);
      break;
    case 8:
      setPixmap(pixie4_frame8);
      break;
    case 9:
      setPixmap(pixie4_frame9);
      break;
    case 10:
      setPixmap(pixie4_frame10);
      break;
    default:
      break;
    }
  }
  curFrame++;
  animTimer.start();
}

void Pixies::startAnim(int flameY) {
  if (flameY + 75 >= 470) curAnim = (qrand() % 2) + 2;
  else curAnim = qrand() % 4;

  switch (curAnim) {
  case 0:
    move(72, flameY + 75 + (qrand() % (470 - (flameY + 75))));
    break;
  case 1:
    move(298, flameY + 75 + (qrand() % (470 - (flameY + 75))));
    break;
  case 2:
    move(70, 417);
    break;
  case 3:
    move(293, 398);
    break;
  default:
    break;
  }
  show();
  curFrame = 1;
  nextFrame();
}
