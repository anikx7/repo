//============================================================================
// Name        : arm.cpp
// Author      : Rafid Ishrak Jahan
// Version     :
// Copyright   : Your copyright notice
// Description : Robbie Robot Shop in C++, Ansi-style
//============================================================================

#include "stdafx.h"
#include "arm.h"
#include<iostream>
using namespace std;
Arm::Arm()
{
	name ="";
	part_number = 0;
	weight = 0;
	cost = 0;
	description = "";
	type_name = "Arm";
	power_consumed = 0;
	use_status = 0;
}

Arm::Arm(string n, int p, double w, double c, string d, double power)
{
	name = n;
	part_number = p;
	weight = w;
	cost = c;
	description = d;
	type_name = "Arm";
	power_consumed = power;
	use_status = 0;
}

void Arm::show()
{
	cout << "Name: " << name << ", Part Number: " << part_number << ", weight: " << weight << "gram(s)\n";
	cout << "Cost: $" << cost << "Power consumed: "<<power_consumed<<"watts (" << description << ")\n\n";
}

void Arm::set_name(string n)
{
	name = n;
}

string Arm::get_name()
{
	return name;
}

void Arm::set_part_number(int p)
{
	part_number = p;
}

int Arm::get_part_number()
{
	return part_number;
}

void Arm::set_weight(double w)
{
	weight = w;
}

double Arm::get_weight()
{
	return weight;
}

void Arm::set_cost(double c)
{
	cost = c;
}

double Arm::get_cost()
{
	return cost;
}

void Arm::set_description(string d)
{
	description = d;
}

string Arm::get_description()
{
	return description;
}

void Arm::set_use_status(int u)
{
	use_status = u;
}

int Arm::get_use_status()
{
	return use_status;
}

void Arm::set_power_consumed(double p)
{
	power_consumed = p;
}

double Arm::get_power_consumed()
{
	return power_consumed;
}

