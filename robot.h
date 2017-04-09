//============================================================================
// Name        : robot.h
// Author      : Rafid Ishrak Jahan
// Version     :
// Copyright   : Your copyright notice
// Description : Robbie Robot Shop in C++, Ansi-style
//============================================================================

#ifndef __ROBOT__
#define __ROBOT__

#include<string>
#include <FL/Fl.H>
#include <FL/Fl_Window.H> 
#include <FL/Fl_Box.H>
#include <FL/Fl_Shared_Image.H>
#include<FL/Fl_JPEG_Image.H>
#include "torso.h"
#include "locomotor.h"
#include "battery.h"
#include"arm.h"
#include"head.h"
using namespace std;

//Defining a class
class Robot
{
private:
	//Data's of the class
	string model_name;
	int model_number;
	double component_cost;
	double cost;
	string description;
	int count;
	string image_name;
	//unique data
	Arm arm1;
	Arm arm2;
	Head head1;
	Torso torso1;
	Locomotor locomotor1;

	//Functions of the class	
public:
	Robot();
	Robot(string n, int p, string d, Arm a1,Head h1, Torso t1, Locomotor l1);
	Robot(string n, int p, string d, Arm a1, Arm a2, Head h1, Torso t1, Locomotor l1);

	void show();
	void show_image();
	double get_component_cost();

	void set_picture(int n);
	string get_picture();


	void set_model_name(string n);
	string get_model_name();

	void set_model_number(int p);
	int get_model_number();

	void set_cost(double w);
	double get_cost();

	void set_description(string d);
	string get_description();

	void set_count(int u);
	int get_count();

	void set_head1(Head temp);
	void set_torso(Torso temp);
	void set_locomotor1(Locomotor temp);
	void set_arm1(Arm temp);
	void set_arm2(Arm temp);

	Arm get_arm1();
	Arm get_arm2();
	Head get_head1();
	Torso get_torso1();
	Locomotor get_locomotor1();

};
#endif


