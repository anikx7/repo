//============================================================================
// Name        : battery.cpp
// Author      : Rafid Ishrak Jahan
// Version     :
// Copyright   : Your copyright notice
// Description : Robbie Robot Shop in C++, Ansi-style
//============================================================================

#include "stdafx.h"
#include "battery.h"
#include<iostream>
using namespace std;

Battery::Battery()
{
	name = "";
	part_number = 0;
	weight = 0;
	cost = 0;
	description = "";
	type_name = "Batter";
	energy = 0;
	max_power = 0;
	use_status = 0;
}

Battery::Battery(string n, int p, double w, double c, string d, double e, double m)
{
	name = n;
	part_number = p;
	weight = w;
	cost = c;
	description = d;
	type_name = "Batter";
	energy = e;
	max_power = m;
	use_status = 0;
}

void Battery::show()
{
	cout << "Name: " <<name <<", Part Number: "<<part_number<< ", weight: "<<weight <<"gram(s)\n";
	cout << "Cost: $" << cost << ", Energy: " << energy << "kilowatts, Max power: " << max_power << "watt(s) (" << description << ")\n\n";
}


void Battery::set_name(string n)
{
	name = n;
}

string Battery::get_name()
{
	return name;
}

void Battery::set_part_number(int p)
{
	part_number = p;
}

int Battery::get_part_number()
{
	return part_number;
}

void Battery::set_weight(double w)
{
	weight = w;
}

double Battery::get_weight()
{
	return weight;
}

void Battery::set_cost(double c)
{
	cost = c;
}

double Battery::get_cost()
{
	return cost;
}

void Battery::set_description(string d)
{
	description = d;
}

string Battery::get_description()
{
	return description;
}

void Battery::set_use_status(int u)
{
	use_status = u;
}

int Battery::get_use_status()
{
	return use_status;
}

void Battery::set_energy(double p)
{
	energy = p;
}

double Battery::get_energy()
{
	return energy;
}

void Battery::set_max_power(double p)
{
	max_power = p;
}

double Battery::get_max_power()
{
	return max_power;
}


