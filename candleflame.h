/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/***************************************************************************
 *            candleflame.h
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
#ifndef _CANDLEFLAME_H
#define _CANDLEFLAME_H

#include <QLabel>
#include <QTimer>

class CandleFlame : public QLabel
{
  Q_OBJECT;
public:
  CandleFlame(QWidget *parent);
  ~CandleFlame();
  void startAnim();
  void stopAnim(int frame);
  void moveLeft(int frame);
  void moveRight(int frame);

public slots:
  void nextFrame();
  
signals:

private:
  QPixmap candle_right_frame1;
  QPixmap candle_right_frame2;
  QPixmap candle_right_frame3;
  QPixmap candle_right_frame4;
  QPixmap candle_right_frame5;
  QPixmap candle_right_frame6;
  QPixmap candle_left_frame1;
  QPixmap candle_left_frame2;
  QPixmap candle_left_frame3;
  QPixmap candle_left_frame4;
  QPixmap candle_left_frame5;
  QPixmap candle_left_frame6;
  QPixmap candle_ignite_frame1;
  QPixmap candle_ignite_frame2;
  QPixmap candle_ignite_frame3;
  QPixmap candle_ignite_frame4;
  QPixmap candle_flame_off;
  QPixmap candle_blowout_frame1;
  QPixmap candle_blowout_frame2;
  QPixmap candle_blowout_frame3;
  QPixmap candle_blowout_frame4;
  QPixmap candle_blowout_frame5;
  QPixmap candle_blowout_frame6;
  QPixmap candle_blowout_frame7;
  QPixmap candle_flame_frame1;
  QPixmap candle_flame_frame2;
  QPixmap candle_flame_frame3;
  QPixmap candle_flame_frame4;
  QPixmap candle_flame_frame5;
  QPixmap candle_flame_frame6;
  QPixmap candle_flame_frame7;
  QPixmap candle_flame_frame8;

  int curFrame;
  int curAnim;
  QTimer animTimer;

};

#endif // _CANDLEFLAME_H
