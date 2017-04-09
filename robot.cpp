//============================================================================
// Name        : robot.cpp
// Author      : Rafid Ishrak Jahan
// Version     :
// Copyright   : Your copyright notice
// Description : Robbie Robot Shop in C++, Ansi-style
//============================================================================

#include "stdafx.h"
#include "robot.h"
#include <iostream>
using namespace std;

Robot::Robot()
{
	model_number = 0;
	component_cost = 0;
}

Robot::Robot(string n, int p, string d, Arm a1, Head h1, Torso t1, Locomotor l1)
{
	model_name = n;
	model_number = p;
	component_cost = 0;
	cost = 0;
	description = d;
	arm1 = a1;
	head1 = h1;
	torso1 = t1;
	locomotor1 = l1;
}

Robot::Robot(string n, int p, string d, Arm a1, Arm a2, Head h1, Torso t1, Locomotor l1)
{
	model_name = n;
	model_number = p;
	cost = 0;
	description = d;
	arm1 = a1;
	arm2 = a2;
	head1 = h1;
	torso1 = t1;
	locomotor1 = l1;
}

void Robot::show()
{
	cout << "Robot Name: " << model_name << ", Model Number: " << model_number << ", Cost: $" << cost << " (" << description << ")\n";
	cout << "    Head name: " << head1.get_name() << ", Torso name: " << torso1.get_name() << ", Locomotor:" << locomotor1.get_name() << endl;
	cout << "    Arm1 name: ";
	cout << arm1.get_name();
	if (arm2.get_part_number() != 0)
	{ 
		cout << ", Arm2 name: ";
		cout << arm2.get_name() << endl << endl;
	}
}

void Robot::show_image()
{

	const int x = 660;   const int y = 660;      const int border = 10;
	// initialize the image library // initialize the image library  
	//fl_register_images();     // Create a window and enclosed box // Create a window and enclosed box
	Fl_Window *win = new Fl_Window(x + 3 * border, y + 3 * border);
	Fl_Box *box = new Fl_Box(border, border, x + border, y + border);
	Fl_JPEG_Image *jpg = new Fl_JPEG_Image("1.jpg");
	box->image(*jpg);
	win->show();


}


double Robot::get_component_cost()
{
	component_cost = arm1.get_cost() + arm2.get_cost() + head1.get_cost() + torso1.get_cost() + locomotor1.get_cost()+torso1.get_b1().get_cost()+torso1.get_b2().get_cost()+torso1.get_b3().get_cost();
	return component_cost;
}

void Robot::set_picture(int n)
{
	if (n == 1) image_name = "1.jpg";
	if (n == 2) image_name = "2.jpg";
	if (n == 3) image_name = "3.jpg";
	if (n == 4) image_name = "4.jpg";
	if (n == 5) image_name = "5.jpg";
	if (n == 6) image_name = "6.jpg";
	if (n == 7) image_name = "7.jpg";
	if (n == 8) image_name = "8.jpg";

}

string Robot::get_picture()
{
	return image_name;
}

void Robot::set_model_name(string n)
{
	model_name = n;
}

string Robot::get_model_name()
{
	return model_name;
}

void Robot::set_model_number(int p)
{
	model_number = p;
}

int Robot::get_model_number()
{
	return model_number;
}

void Robot::set_cost(double w)
{
	cost = w;
}

double Robot::get_cost()
{
	return cost;
}

void Robot::set_description(string d)
{
	description = d;
}

string Robot::get_description()
{
	return description;
}

void Robot::set_count(int u)
{
	count = u;
}

int Robot::get_count()
{
	return count;
}

void Robot::set_head1(Head temp)
{
	head1 = temp;
}

void Robot::set_torso(Torso temp)
{
	torso1 = temp;
}

void Robot::set_locomotor1(Locomotor temp)
{
	locomotor1 = temp;
}

void Robot::set_arm1(Arm temp)
{
	arm1 = temp;
}

void Robot::set_arm2(Arm temp)
{
	arm2 = temp;
}

Arm Robot::get_arm1()
{
	return arm1;
}

Arm Robot::get_arm2()
{
	return arm2;
}

Head Robot::get_head1()
{
	return head1;
}

Torso Robot::get_torso1()
{
	return torso1;
}

Locomotor Robot::get_locomotor1()
{
	return locomotor1;
}
