//============================================================================
// Name        : order.cpp
// Author      : Rafid Ishrak Jahan
// Version     :
// Copyright   : Your copyright notice
// Description : Robbie Robot Shop in C++, Ansi-style
//============================================================================
#include "stdafx.h"
#include "order.h"
#include<iostream>
using namespace std;
Order::Order()
{
	employe_number = 0;
	order_number =0;
	day = 0;
	month = 0;
	year = 0;
	quantity = 0;
}

Order::Order(int o, int d, int m, int y, Customer c, Robot r, int q,int employee)
{
	employe_number = employee;
	order_number =o;
	day = d;
	month = m;
	year =y;
	customer =c;
	robot_model = r;
	quantity =q;
}

double Order::get_total_price_with_tax()
{
	return ((robot_model.get_cost()) + (robot_model.get_cost() * 0.75));
}

void Order::show()
{
	cout << "Order Number: " << order_number << ", Customer Name: " << customer.get_name() << "( " << customer.get_phone() << " )\n";
	cout << "Robot Model: " << robot_model.get_model_name()<<", Quatity: "<<quantity<<", Price(Including tax):$"<<get_total_price_with_tax();
	cout << "\n Date: " << day << " - " << month << " - " << year << endl;
}

void Order::set_employee_number(int o)
{
	employe_number = o;
}

int Order::get_employee_number()
{
	return employe_number;
}

void Order::set_order_number(int o)
{
	order_number = o;
}

int Order::get_order_number()
{
	return order_number;
}

void Order::set_day(int d)
{
	day = d;
}

int Order::get_day()
{
	return day;
}

void Order::set_month(int m)
{
	month = m;
}

int Order::get_month()
{
	return month;
}

void Order::set_year(int y)
{
	year = y;
}

int Order::get_year()
{
	return year;
}

void Order::set_customer(Customer c_temp)
{
	customer = c_temp;
}

Customer Order::get_customer()
{
	return customer;
}

void Order::set_robot_model(Robot r_temp)
{
	robot_model = r_temp;
}

Robot Order::get_robot_model()
{
	return robot_model;
}

void Order::set_quantity(int q)
{
	quantity = q;
}

int Order::get_quantity()
{
	return quantity;
}


