//============================================================================
// Name        : customer.h
// Author      : Rafid Ishrak Jahan
// Version     :
// Copyright   : Your copyright notice
// Description : Robbie Robot Shop in C++, Ansi-style
//============================================================================

#ifndef __Customer__
#define __Customer__

#include<string>
using namespace std;


//Defining a class
class Customer
{
private:
	//Data's of the class
	string name;
	string phone;
	string address;
	string email;
	int order_number;

	//Functions of the class	
public:
	Customer();
	Customer(string customer_name, string customer_phone, string a, string e);
	void set_name(string customer_name);
	string get_name();
	void set_phone(string customer_phone);
	string get_phone();
	void set_address(string customer_phone);
	string get_address();
	void set_email(string customer_phone);
	string get_email();
	void set_order_number(int o);
	int get_order_number();



};
#endif