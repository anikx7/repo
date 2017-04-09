//============================================================================
// Name        : associate.cpp
// Author      : Rafid Ishrak Jahan
// Version     :
// Copyright   : Your copyright notice
// Description : Robbie Robot Shop in C++, Ansi-style
//============================================================================
#include "stdafx.h"
#include "customer.h"
#include"order.h"
#include<string>
#include<cstdio>
#include<iostream>
#include<vector>
#include "stdafx.h"
#include "associate.h"

using namespace std;
Associate::Associate()
{
	name = " ";
	employee_number = 0;
}

Associate::Associate(string employee_name, int n)
{
	name = employee_name;
	employee_number = n;
}

void Associate::set_name(string customer_name)
{
	name = customer_name;
}

string Associate::get_name()
{
	return name;
}

void Associate::set_employee_number(int n)
{
	employee_number = n;
}

int Associate::get_employee_number()
{
	return employee_number;
}

void Associate::set_order(Order order1)
{
	orders.push_back(order1);
}

Order Associate::get_order(int order_number)
{
	return orders[order_number];
}

int Associate::get_order_count()
{
	return (int)orders.size();
}
