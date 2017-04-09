//============================================================================
// Name        : locomotor.h
// Author      : Rafid Ishrak Jahan
// Version     :
// Copyright   : Your copyright notice
// Description : Robbie Robot Shop in C++, Ansi-style
//============================================================================

#ifndef __LOCOMOTOR__
#define __LOCOMOTOR__

#include<string>
using namespace std;


//Defining a class
class Locomotor
{
private:
	//Data's of the class
	string name;
	int part_number;
	double weight;
	double cost;
	string description;
	string type_name;
	int use_status ;
	//unique data
	double max_speed;
	double power_consumed;


	//Functions of the class	
public:
	Locomotor();
	Locomotor(string n, int p, double w, double c, string d, double m, double po);
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

	void set_max_speed(double p);
	double get_max_speed();

	void set_power_consumed(double p);
	double get_power_consumed();
};
#endif

