/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/***************************************************************************
 *            pixies.h
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
#ifndef _PIXIES_H
#define _PIXIES_H

#include <QLabel>
#include <QTimer>

class Pixies : public QLabel
{
  Q_OBJECT;
public:
  Pixies(QWidget *parent);
  ~Pixies();
  void startAnim(int flameY);

public slots:
  void nextFrame();
  
signals:

private:
  QPixmap pixie1_frame1;
  QPixmap pixie1_frame2;
  QPixmap pixie1_frame3;
  QPixmap pixie1_frame4;
  QPixmap pixie1_frame5;
  QPixmap pixie1_frame6;
  QPixmap pixie1_frame7;
  QPixmap pixie1_frame8;
  QPixmap pixie1_frame9;
  QPixmap pixie1_frame10;
  QPixmap pixie2_frame1;
  QPixmap pixie2_frame2;
  QPixmap pixie2_frame3;
  QPixmap pixie2_frame4;
  QPixmap pixie2_frame5;
  QPixmap pixie2_frame6;
  QPixmap pixie2_frame7;
  QPixmap pixie2_frame8;
  QPixmap pixie2_frame9;
  QPixmap pixie2_frame10;
  QPixmap pixie3_frame1;
  QPixmap pixie3_frame2;
  QPixmap pixie3_frame3;
  QPixmap pixie3_frame4;
  QPixmap pixie3_frame5;
  QPixmap pixie3_frame6;
  QPixmap pixie3_frame7;
  QPixmap pixie3_frame8;
  QPixmap pixie3_frame9;
  QPixmap pixie3_frame10;
  QPixmap pixie4_frame1;
  QPixmap pixie4_frame2;
  QPixmap pixie4_frame3;
  QPixmap pixie4_frame4;
  QPixmap pixie4_frame5;
  QPixmap pixie4_frame6;
  QPixmap pixie4_frame7;
  QPixmap pixie4_frame8;
  QPixmap pixie4_frame9;
  QPixmap pixie4_frame10;
  int curFrame;
  int curAnim;
  QTimer animTimer;

};

#endif // _PIXIES_H
