//============================================================================
// Name        : image.cpp
// Author      : Rafid Ishrak Jahan
// Version     :
// Copyright   : Your copyright notice
// Description : Robbie Robot Shop in C++, Ansi-style
//============================================================================

#include "stdafx.h"
#include "image.h"

Image::Image()
{
	i1 = "1.jpg";
	i2 = "2.jpg";
	i3 = "3.jpg";
	i4 = "4.jpg";
	i5 = "5.jpg";
	i6 = "6.jpg";
	i7 = "7.jpg";
	i8 = "8.jpg";
	address = "";
}

void Image::show_image(string a)
{
	address = a;
	const char *b = address.c_str();
	const int x = 660;   const int y = 660;      const int border = 10;
	Fl_Window *win = new Fl_Window(x + 3 * border, y + 3 * border);
	Fl_Box *box = new Fl_Box(border, border, x + border, y + border);
	Fl_JPEG_Image *jpg = new Fl_JPEG_Image(b);
	box->image(*jpg);
	win->show();
}

