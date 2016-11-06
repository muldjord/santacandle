/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/***************************************************************************
 *            main.cpp
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
#include <QWidget>
#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QDir>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  
  QTranslator translator;
  translator.load("santacandle_" + QLocale::system().name());
  app.installTranslator(&translator);

  QDir::setCurrent(QApplication::applicationDirPath());

  SantaCandle candle;
  candle.show();
  return app.exec();
}
