//============================================================================
// Name        : head.cpp
// Author      : Rafid Ishrak Jahan
// Version     :
// Copyright   : Your copyright notice
// Description : Robbie Robot Shop in C++, Ansi-style
//============================================================================

#include "stdafx.h"
#include "head.h"
#include<iostream>
using namespace std;
Head::Head()
{
	name = "";
	part_number = 0;
	weight = 0;
	cost = 0;
	description = "";
	type_name = "Head";
	use_status = 0;
}

Head::Head(string n, int p, double w, double c, string d)
{
	name =n;
	part_number = p;
	weight = w;
	cost =c;
	description = d;
	type_name = "Head";
	use_status=0;
}
void Head::show()
{
	cout << "Name: " << name << ", Part Number: " << part_number << ", weight: " << weight << "gram(s)\n";
	cout << "Cost: $" << cost <<" (" << description << ")\n\n";
}

void Head::set_name(string n)
{
	name = n;
}

string Head::get_name()
{
	return name;
}

void Head::set_part_number(int p)
{
	part_number = p;
}

int Head::get_part_number()
{
	return part_number;
}

void Head::set_weight(double w)
{
	weight = w;
}

double Head::get_weight()
{
	return weight;
}

void Head::set_cost(double c)
{
	cost = c;
}

double Head::get_cost()
{
	return cost;
}

void Head::set_description(string d)
{
	description = d;
}

string Head::get_description()
{
	return description;
}

void Head::set_use_status(int u)
{
	use_status = u;
}

int Head::get_use_status()
{
	return use_status;
}
