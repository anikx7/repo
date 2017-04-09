//============================================================================
// Name        : torso.h
// Author      : Rafid Ishrak Jahan
// Version     :
// Copyright   : Your copyright notice
// Description : Robbie Robot Shop in C++, Ansi-style
//============================================================================
#ifndef __TORSO__
#define __TORSO__

#include<string>
#include"battery.h"
using namespace std;


//Defining a class
class Torso
{
private:
	//Data's of the class
	string name;
	int part_number;
	double weight;
	double cost;
	string description;
	string type_name;
	int use_status;
	//unique data
	Battery b1;
	Battery b2;
	Battery b3;


	//Functions of the class	
public:
	Torso();
	Torso(string n, int p, double w, double c, string d, Battery b_temp1);
	Torso(string n, int p, double w, double c, string d, Battery b_temp1,Battery b_temp2);
	Torso(string n, int p, double w, double c, string d, Battery b_temp1,Battery b_temp2, Battery b_temp3);
	void show();


	void set_name(string n);
	string get_name();

	void set_part_number(int p);
	int get_part_number();

	void set_weight(double w);
	double get_weight();

	void set_cost(double c);
	double get_cost();

	void set_description(string d);
	string get_description();

	void set_use_status(int u);
	int get_use_status();

	void set_b1(Battery b);
	Battery get_b1();

	void set_b2(Battery b);
	Battery get_b2();


	void set_b3(Battery b);
	Battery get_b3();



};
#endif


