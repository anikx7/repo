
//============================================================================
// Name        : battery.h
// Author      : Rafid Ishrak Jahan
// Version     :
// Copyright   : Your copyright notice
// Description : Odometer math in C++, Ansi-style
//============================================================================

#ifndef __BATTERY__
#define __BATTERY__

#include<string>
using namespace std;


//Defining a class
class Battery
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
	double energy;
	double max_power;


	//Functions of the class	
public:
	Battery();
	Battery(string n, int p, double w, double c, string d, double e, double m);
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

	void set_energy(double p);
	double get_energy();

	void set_max_power(double p);
	double get_max_power();
};
#endif
