//============================================================================
// Name        : image.h
// Author      : Rafid Ishrak Jahan
// Version     :
// Copyright   : Your copyright notice
// Description : Robbie Robot Shop in C++, Ansi-style
//============================================================================

#ifndef __IMAGE__
#define __IMAGE__

#include<string>
#include<FL/Fl.H>
#include<FL/Fl_Box.H>
#include<FL/Fl_Window.H>
#include<FL/Fl_Button.H>
#include<FL/Fl_Menu_Bar.H>
#include<FL/fl_ask.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include<FL/Fl_File_Chooser.H>
#include <FL/Fl_Text_Display.H>
#include<FL/Fl_Multiline_Output.H>
#include<FL/Fl_Box.H>
#include <FL/Fl_Shared_Image.H>
#include<FL/Fl_JPEG_Image.H>

using namespace std;

//Defining a class
class Image
{
private:
	//Data's of the class
	string address,i1,i2,i3,i4,i5,i6,i7,i8;

	

	//Functions of the class	
public:
	Image();
	void show_image(string a);
	

};
#endif



