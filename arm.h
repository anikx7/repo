//============================================================================
// Name        : arm.h
// Author      : Rafid Ishrak Jahan
// Version     :
// Copyright   : Your copyright notice
// Description : Robbie Robot Shop in C++, Ansi-style
//============================================================================

#ifndef __ARM__
#define __ARM__

#include<string>
using namespace std;


//Defining a class
class Arm
{
private:
	//Data's of the class
	string name;
	int part_number;
	double weight;
	double cost;
	string description;
	string type_name;
	//unique data
	double power_consumed;
	int use_status;

	//Functions of the class	
public:
	Arm();
	Arm(string n, int p, double w, double c, string d, double power);

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

	void set_power_consumed(double p);
	double get_power_consumed();

};
#endif
