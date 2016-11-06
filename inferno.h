/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/***************************************************************************
 *            inferno.h
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
#ifndef _INFERNO_H
#define _INFERNO_H

#include <QLabel>
#include <QTimer>

class Inferno : public QLabel
{
  Q_OBJECT;
public:
  Inferno(QWidget *parent);
  ~Inferno();
  void startAnim();

public slots:
  void nextFrame();
  
signals:

private:
  QPixmap candle_inferno_frame1;
  QPixmap candle_inferno_frame2;
  QPixmap candle_inferno_frame3;
  QPixmap candle_inferno_frame4;
  QPixmap candle_inferno_frame5;
  QPixmap candle_inferno_frame6;
  int curFrame;
  int curAnim;
  QTimer animTimer;

};

#endif // _INFERNO_H
