//============================================================================
// Name        : main.cpp
// Author      : Rafid Ishrak Jahan
// Version     :
// Copyright   : Your copyright notice
// Description : Robbie Robot Shop in C++, Ansi-style
//============================================================================
#include "stdafx.h"
#include "arm.h"
#include"locomotor.h"
#include"battery.h"
#include "head.h"
#include "torso.h"
#include"robot.h"
#include"image.h"
#include<string>
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstdlib>
#include "head.h"
#include "order.h"
#include"customer.h"
#include"robot.h"
#include"associate.h"
#include<cstdlib>
#include<FL/Fl.H>
#include<FL/Fl_Box.H>
#include<FL/Fl_Window.H>
#include<FL/Fl_Button.H>
#include<FL/Fl_Menu_Bar.H>
#include<FL/fl_ask.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include<FL/Fl_File_Chooser.H>
#include <FL/Fl_Text_Display.H>
#include<FL/Fl_Multiline_Output.H>
#include<FL/Fl_Box.H>
#include <FL/Fl_Shared_Image.H>
#include<FL/Fl_JPEG_Image.H>

using namespace std;

class Error {};
void CloseCB(Fl_Widget *w, void *p);
void ArmCB(Fl_Widget *w, void *p);
Battery BatteryCB();
void HeadCB(Fl_Widget *w, void *p);
void LocomotorCB(Fl_Widget *w, void *p);
void TorsoCB(Fl_Widget *w, void *p);
void show_arm(Fl_Widget *w, void *p);
void show_head(Fl_Widget *w, void *p);
void show_locomotor(Fl_Widget *w, void *p);
void show_torso(Fl_Widget *w, void *p);
void robot_model(Fl_Widget *w, void *p);
void CB(Fl_Widget *w, void *p);
void input_head(Fl_Widget *w, void *p);
void input_arm(Fl_Widget *w, void *p);
void input_locomotor(Fl_Widget *w, void *p);
void input_torso(Fl_Widget *w, void *p);
void input_arm2(Fl_Widget *w, void *p);
void show_robot(Fl_Widget *w, void *p);
void image1(Fl_Widget *w, void *p);
void image2(Fl_Widget *w, void *p);
void image3(Fl_Widget *w, void *p);
void image4(Fl_Widget *w, void *p);
void image5(Fl_Widget *w, void *p);
void image6(Fl_Widget *w, void *p);
void image7(Fl_Widget *w, void *p);
void image8(Fl_Widget *w, void *p);
void image_robot(Fl_Widget *w, void *p);
void robot_picture(Fl_Widget *w, void *p);
void robot_output_full(Fl_Widget *w, void *p);
void robot_out_full_close(Fl_Widget *w, void *p);
void taking_input_for_image(Fl_Widget *w, void *p);
void create_customer(Fl_Widget *w, void *p);
void create_associate(Fl_Widget *w, void *p);
void create_order(Fl_Widget *w, void *p);
void show_associate_order(Fl_Widget *w, void *p);
void user_manual(Fl_Widget *w, void *p);
void version(Fl_Widget *w, void *p);
void generate_data();

//Global variables
vector<Battery>battery;
vector<Torso>torso;
vector<Head>head;
vector<Arm>arm;
vector<Locomotor>locomotor;
vector<Robot>robot;
vector<Order>order;
vector<Customer>customer;
vector<Associate>sales_associate;

Fl_Window *win, *window_image,*window_robot;
Fl_Menu_Bar *menubar;
Fl_Window *dialog = new Fl_Window(640, 480, "Arm");
Fl_Window *wi = new Fl_Window(640, 480);
Fl_Window *window ;
const char *c;
int head_x=0,arm_x=0,arm2_x,loco_x=0,torso_x=0,picture=0;
Image image;

int main()
{
	try {
		generate_data();//Generating Rondom Data

		win = new Fl_Window(700, 400, "Robbie Robot Shop"); //Creating Window
		menubar = new Fl_Menu_Bar(0, 0, 700, 30);//Creating menubar
		win->callback(CloseCB);//Signing for callbacks
		Fl_Menu_Item menuitems[] = {
			{ "&File", 0, 0, 0, FL_SUBMENU },
				 { "&Quit", FL_ALT + 'q',(Fl_Callback*)CloseCB },
				 { 0 },
			{ "&Create", 0, 0, 0, FL_SUBMENU },
				 { "&Create Arm", FL_ALT + 'a',(Fl_Callback*)ArmCB },
				 { "&Create Head", FL_ALT + 'h',(Fl_Callback*)HeadCB },
				 { "&Create Locomotor", FL_ALT + 'l',(Fl_Callback*)LocomotorCB },
				 { "&Create Torso including Battery", FL_ALT + 't',(Fl_Callback*)TorsoCB },
				 { "&Create a Customer", FL_ALT + 'a',(Fl_Callback*)create_customer },
				 { "&Create an Sales Associate", FL_ALT + 'a',(Fl_Callback*)create_associate },
				 { "&Create an Order", FL_ALT + 'a',(Fl_Callback*)create_order },
				 { 0 },
		   { "&Create Robot Model", 0, 0, 0, FL_SUBMENU },
				 { "&Create with existing component", FL_ALT + 'a',(Fl_Callback*)robot_model },
				 { 0 },
			{ "&Report", 0, 0, 0, FL_SUBMENU },
				 { "&Show all Arm", FL_ALT + 'a',(Fl_Callback*)show_arm },
				 { "&Show all Head", FL_ALT + 'h',(Fl_Callback*)show_head },
				 { "&Show all Locomotor", FL_ALT + 'l',(Fl_Callback*)show_locomotor },
				 { "&Show all Torso including Battery", FL_ALT + 't',(Fl_Callback*)show_torso },
				 { "&Shot all Robot Model", FL_ALT + 'm' ,(Fl_Callback*)show_robot },
				 { "&Shot all Robot Model with picture", FL_ALT + 'm' ,(Fl_Callback*)robot_output_full },
				 { "&Shot Order per Sales Associate", FL_ALT + 'm' ,(Fl_Callback*)show_associate_order },
				 { 0 },
			{ "&Help", 0, 0, 0, FL_SUBMENU },
				 { "&Manual", FL_ALT + 'a',(Fl_Callback*)user_manual },
				 { "&About", FL_ALT + 'a',(Fl_Callback*)version },
				 { 0 },
			{ 0 }
		}; //Adding menu items
		menubar->menu(menuitems);
		win->show(); ///Making visible the window
	}
	catch (Error &e) { cerr << "Invalid input"; return -1; }
	return Fl::run();
}

//Showing robot model with picture
void robot_output_full(Fl_Widget *w, void *p){
	window_robot = new Fl_Window{ 405,300,"Browse Robot" };
	char* label1 = "Show all Robot List", *label2 = "Add number to see picture", *label3 = "Close";
	Fl_Button* button1 = new Fl_Button(5, 20, 180, 50, label1), *button2 = new Fl_Button(220, 20, 180, 50, label2),*button3 = new Fl_Button(190, 100, 100, 50, label3);
	
	button1->callback(show_robot, label1);
	button2->callback(taking_input_for_image,label2);
	button3->callback(robot_out_full_close,label3);

	window_robot->end();
	window_robot->show();
}

void robot_out_full_close(Fl_Widget *w, void *p) { window_robot->hide(); }

void taking_input_for_image(Fl_Widget *w, void *p) {
	const char *s = "Enter robot model serial number(digit)"; const char *d = " "; const char *b = fl_input(s, d); picture = atoi(b);
	string temp= robot[picture - 1].get_picture();
	image.show_image(temp);
}

void image_robot(Fl_Widget *w, void *p){
	window_image = new Fl_Window{ 640,400,"Available Robot Images" };
	char* label1 = "Picture 1", *label2 = "Picture 2", *label3 = "Picture 3", *label4 = "Picture 4", *label5 = "Picture 5";
	char* label6 = "Picture 6", *label7 = "Picture 7", *label8 = "Picture 8";
	Fl_Button* button1 = new Fl_Button(5, 100, 140, 50, label1), *button2 = new Fl_Button(160, 100, 140, 50, label2);
	Fl_Button* button3 = new Fl_Button(320, 100, 140, 50, label3), *button4 = new Fl_Button(480, 100, 140, 50, label4);
	Fl_Button* button5 = new Fl_Button(5, 200, 140, 50, label5), *button6 = new Fl_Button(160, 200, 140, 50, label6);
	Fl_Button* button7 = new Fl_Button(320, 200, 140, 50, label7),* button8 = new Fl_Button(480, 200, 140, 50, label8);
	Fl_Button* button10 = new Fl_Button(180, 330, 330, 80, "Enter your choice");
	button1->callback(image1, 0); button2->callback(image2, label2); button3->callback(image3, label3); button4->callback(image4, label4);
	button5->callback(image5, label5); button6->callback(image6, label6);button7->callback(image7, label7); button8->callback(image8, label8);
	button10->callback(robot_picture, 0);
	window_image->end();
	window_image->show();
}

void image1(Fl_Widget *w, void *p) { image.show_image("1.jpg"); }
void image2(Fl_Widget *w, void *p) { image.show_image("2.jpg"); }
void image3(Fl_Widget *w, void *p) { image.show_image("3.jpg"); }
void image4(Fl_Widget *w, void *p) { image.show_image("4.jpg"); }
void image5(Fl_Widget *w, void *p) { image.show_image("5.jpg"); }
void image6(Fl_Widget *w, void *p) { image.show_image("6.jpg"); }
void image7(Fl_Widget *w, void *p) { image.show_image("7.jpg"); }
void image8(Fl_Widget *w, void *p) { image.show_image("8.jpg"); }

void robot_picture(Fl_Widget *w, void *p) { window_image->hide(); const char *s = "Enter picture number(digit)"; const char *d = " "; const char *b = fl_input(s, d); picture = atoi(b); }

//Showing robot model has been created
void show_robot(Fl_Widget *w, void *p) {
	Fl_Window *win = new Fl_Window(640, 480);
	Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 640 - 40, 480 - 40, "Robot Models");
	Fl_Text_Buffer *buff1 = new Fl_Text_Buffer(); Fl_Text_Buffer *buff2 = new Fl_Text_Buffer();
	disp->buffer(buff1);
	string str_final1, str_final2;

	if ((int)robot.size() == 0)buff1->text("Out of Robot!!!");
	else{
		for (int i = 0; i < (int)robot.size(); i++){
			string number = to_string(i + 1),name = robot[i].get_model_name(),description = robot[i].get_description();
			int part_number = robot[i].get_model_number(); double component_cost = robot[i].get_component_cost(),cost = robot[i].get_cost();
			string arm1 = robot[i].get_arm1().get_name(),arm2 = robot[i].get_arm2().get_name(),loco = robot[i].get_locomotor1().get_name();
			string head = robot[i].get_head1().get_name(),torso = robot[i].get_head1().get_name();
			if (i == 0) {
				str_final1 = number + ". Name: " + name + ", Part Number: " + to_string(part_number) +
					", Component cost: " + to_string(component_cost) + ", Cost: " + to_string(cost) + ", Head: " + head + ", Arm1: " + arm1
					+", Arm2: " + arm2 + ", Locomotor: "+loco+", Torso: "+torso;
				const char *c1 = str_final1.c_str(); buff1->text(c1);
			}
			else if (i%2 != 0) {
				str_final2 = str_final1+ "\n"+number + ". Name: " + name + ", Part Number: " + to_string(part_number) +
					", Component cost: " + to_string(component_cost) + ", Cost: " + to_string(cost) + ", Head: " + head + ", Arm1: " + arm1
					+ ", Arm2: " + arm2 + ", Locomotor: " + loco + ", Torso: " + torso;
				const char *c1 = str_final2.c_str(); buff1->text(c1);
			}
			else if (i%2 == 0) {
				str_final1 = str_final2 + "\n" + number + ". Name: " + name + ", Part Number: " + to_string(part_number) +
					", Component cost: " + to_string(component_cost) + ", Cost: " + to_string(cost) + ", Head: " + head + ", Arm1: " + arm1
					+ ", Arm2: " + arm2 + ", Locomotor: " + loco + ", Torso: " + torso;
				const char *c1 = str_final1.c_str(); buff1->text(c1);
			}
		}
	}
	buff2->text("AAAAAAAAAA\nBBBBBBBBBB\nCCCCCCCCCC\nDDDDDDDDDD\n""AAAAAAAAAA\nBBBBBBBBBB\nCCCCCCCCCC\nDDDDDDDDDD\n");
	win->resizable(*disp); win->show();
}
//Create a Robot Model
void robot_model(Fl_Widget *w, void *p) { 
	if ((int)arm.size() > 0 && (int)head.size() > 0 && (int)locomotor.size() > 0 && (int)torso.size() > 0) {
		window = new Fl_Window{ 640,400,"Create Robot Model" };
		char* label1 = "Show all Head", *label2 = "Show all Arm", *label3 = "Show all Locomotor", *label4 = "Show all Torso", *label5 = "Selection of Parts Completed";
		char* label6 = "Enter Head", *label7 = "Enter Arm1", *label8 = "Enter Locomotor", *label9 = "Enter Torso",*label10="Add Arm2";

		Fl_Button* button1 = new Fl_Button(5, 100, 140, 50, label1),* button2 = new Fl_Button(160, 100, 140, 50, label2);
		Fl_Button* button3 = new Fl_Button(320, 100, 140, 50, label3),* button4 = new Fl_Button(480, 100, 140, 50, label4);
		Fl_Button* button5 = new Fl_Button(390, 330, 250, 80, label5),* button6 = new Fl_Button(5, 200, 110, 49, label6);
		Fl_Button* button7 = new Fl_Button(160, 200, 110, 49, label7),* button8 = new Fl_Button(320, 200, 110, 49, label8);
		Fl_Button* button9 = new Fl_Button(480, 200, 110, 49, label9),* button10 = new Fl_Button(160, 250, 110, 49, label10);
		Fl_Button *button11 = new Fl_Button(5, 330, 250, 80, "Add picture");
		Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 560, 40, "Component Available");
		Fl_Text_Buffer *buff1 = new Fl_Text_Buffer(); Fl_Text_Buffer *buff2 = new Fl_Text_Buffer();
		
		button1->callback(show_head, label1);button2->callback(show_arm, label2);
		button3->callback(show_locomotor, label3);button4->callback(show_torso, label4);
		button5->callback(CB, label5);button6->callback(input_head, label6);
		button7->callback(input_arm, label7);button8->callback(input_locomotor, label8);
		button9->callback(input_torso, label9);button10->callback(input_arm2,label10);
		button11->callback(image_robot,"Add picture");

		disp->buffer(buff1);
		string str = "Head: " + to_string((int)head.size()) + ", Arm: " + to_string((int)arm.size()) + ", Locomotor: " + to_string((int)locomotor.size()) + ", Torso: " + to_string((int)torso.size());
        const char *c1 = str.c_str();
		buff1->text(c1);
		window->end();
		window->show();
	}
	else{
		int selection = 1; selection = fl_choice("Out of Component!!!!!\n Do you to exit the program?", fl_no, fl_yes, 0);
		if (selection == 1)win->hide();}
}

void CB(Fl_Widget *w, void *p) {
	window->hide();
	if (head_x != 0 && arm_x != 0 && loco_x != 0 && torso_x != 0){
		Robot *ptr = new Robot();
		ptr->set_picture(picture);
		ptr->set_head1(head[head_x - 1]);
		ptr->set_arm1(arm[arm_x - 1]);

		if(arm2_x  != 0) ptr->set_arm2(arm[arm2_x - 1]);

		ptr->set_locomotor1(locomotor[loco_x - 1]);
		ptr->set_torso(torso[torso_x - 1]);
		char *s = "Enter robot model name"; char *d = " "; const char *a = fl_input(s, d); string temp(a);ptr->set_model_name(temp);
		int x; s = "Enter robot part number (digit)"; d = " "; const char *b = fl_input(s, d); x = atoi(b);ptr->set_model_number(x);
		string t = to_string(ptr->get_component_cost());
		t = "Enter Robot Cost (Component cost: $" + t + " ): ";const char *te = t.c_str();s = (char*)te;
		d = " "; const char *e = fl_input(s, d); x = atoi(e);ptr->set_cost(x);
		s = "Enter Arm Description"; d = " "; const char *g = fl_input(s, d); string temp2(a);
		ptr->set_description(temp2);robot.push_back(*ptr);

		head_x = 0, arm_x = 0, arm2_x, loco_x = 0, torso_x = 0,picture=0;
	}
	else {
		int selection = 1; selection = fl_choice("Invalid Input!!!!!\n Do you to exit the program?", fl_no, fl_yes, 0);
		if (selection == 1)win->hide();
	}
}

void input_head(Fl_Widget *w, void *p) {
	const char *s = "Enter Head number from Head list(digit)"; const char *d = " "; const char *b = fl_input(s, d); head_x = atoi(b); }

void input_arm(Fl_Widget *w, void *p) {
	const char *s = "Enter Arm number from Arm list(digit)"; const char *d = " "; const char *b = fl_input(s, d); arm_x = atoi(b);}

void input_arm2(Fl_Widget *w, void *p) {
	const char *s = "Enter Arm2 number from Arm list(digit)"; const char *d = " "; const char *b = fl_input(s, d); arm2_x = atoi(b);
}
void input_locomotor(Fl_Widget *w, void *p) {
	const char *s = "Enter Locomotor number from Locomotor list(digit)"; const char *d = " "; const char *b = fl_input(s, d); loco_x = atoi(b);}
void input_torso(Fl_Widget *w, void *p) {
	const char *s = "Enter Torso number from Torso list(digit)"; const char *d = " "; const char *b = fl_input(s, d); torso_x = atoi(b);}

void CloseCB(Fl_Widget *w, void *p){
	int selection = 1;selection = fl_choice("Are you sure you want exit the program?",fl_no,fl_yes,0);
	if (selection == 1)win->hide();
}

//Create a Customer
void create_customer(Fl_Widget *w, void *p) {
	Customer *ptr = new Customer();

	char *s = "Enter customer name"; char *d = " "; const char *a = fl_input(s, d); string temp(a);
	ptr->set_name(temp);
	s = "Enter customer address"; d = " "; const char *b = fl_input(s, d); string temp1(b);
	ptr->set_address(temp1);
	s = "Enter customer phone number"; d = " "; const char *c = fl_input(s, d); string temp2(c);
	ptr->set_phone(temp2);
	s = "Enter customer email address"; d = " "; const char *f = fl_input(s, d); string temp3(f);
	ptr->set_email(temp3);

	customer.push_back(*ptr);
}

//Create a Sales Associate
void create_associate(Fl_Widget *w, void *p) {
	Associate *ptr = new Associate();

	char *s = "Enter Sales Associate name"; char *d = " "; const char *a = fl_input(s, d); string temp(a);
	ptr->set_name(temp);
	int x; s = "Enter employee number (digit)"; d = " "; const char *b = fl_input(s, d); x = atoi(b);
	ptr->set_employee_number(x);

	sales_associate.push_back(*ptr);
}

//Create an Order for Sales Associate
void create_order(Fl_Widget *w, void *p) {
	Order *ptr = new Order();
	Customer *ptr1 = new Customer();
	char *s = "Enter Employee number"; char *d = " "; const char *b = fl_input(s, d);int associate_number = atoi(b);
	ptr->set_employee_number(associate_number);
	s = "Enter Order number"; d = " "; const char *c = fl_input(s, d); int x = atoi(c);
	ptr->set_order_number(x);
	s = "Enter today's day"; d = " "; const char *k = fl_input(s, d); x = atoi(k);
	ptr->set_day(x);
	s = "Enter today's month number"; d = " "; const char *e = fl_input(s, d); x = atoi(e);
	ptr->set_month(x);
	s = "Enter year"; d = " "; const char *f = fl_input(s, d); x = atoi(f);
	ptr->set_year(x);
	s = "Enter Customer name"; d = " "; const char *g = fl_input(s, d); string temp(g);
	ptr1->set_name(temp);
	s = "Enter Customer phone number"; d = " "; const char *h = fl_input(s, d); string temp1(h);
	ptr1->set_phone(temp1);
	s = "Enter Customer address"; d = " "; const char *i = fl_input(s, d); string temp2(i);
	ptr1->set_address(temp2);
	s = "Enter Customer email address"; d = " "; const char *l = fl_input(s, d); string temp3(l);
	ptr1->set_email(temp3);
	s = "Enter robot serial number"; d = " "; const char *m = fl_input(s, d); x = atoi(m);
	ptr->set_robot_model(robot[x-1]);
	s = "Enter quantity"; d = " "; const char *j = fl_input(s, d); x = atoi(j);
	ptr->set_quantity(x);
	ptr->set_customer(*ptr1);
	order.push_back(*ptr);
	cout << order.size();
	sales_associate[associate_number - 1].set_order(*ptr);
}

//Callback for Arm
void ArmCB(Fl_Widget *w, void *p){
	Arm *ptr = new Arm();
	char *s = "Enter arm name";char *d = " ";const char *a = fl_input(s, d);string temp(a);ptr->set_name(temp);

	int x;s = "Enter arm part number (digit)";d = " ";const char *b = fl_input(s, d);x = atoi(b);ptr->set_part_number(x);
	s = "Enter arm weight (digit)";d = " ";const char *c = fl_input(s, d);x = atoi(c);ptr->set_weight(x);
	s = "Enter arm cost (digit)";d = " ";const char *e = fl_input(s, d);x = atoi(e);ptr->set_cost(x);
	s = "Enter battery power energy(kw-h) while operating (digit)";d = " ";const char *f = fl_input(s, d);x = atoi(f);ptr->set_power_consumed(x);
	s = "Enter Arm Description"; d = " "; const char *g = fl_input(s, d); string temp2(a);ptr->set_description(temp2);

	arm.push_back(*ptr);
}
//Callback for Head
void HeadCB(Fl_Widget *w, void *p){
	Head *ptr = new Head();

	char *s = "Enter Head name";char *d = " ";const char *a = fl_input(s, d);string temp(a);ptr->set_name(temp);
	s = "Enter Head part number (digit)";d = " ";const char *b = fl_input(s, d);int x = atoi(b);ptr->set_part_number(x);
	s = "Enter Head weight (digit)";d = " ";const char *c = fl_input(s, d);x = atoi(c);ptr->set_weight(x);
	s = "Enter Head cost (digit)";d = " ";const char *e = fl_input(s, d);	x = atoi(e);ptr->set_cost(x);
	s = "Enter Head Description"; d = " "; const char *g = fl_input(s, d); string temp2(a);ptr->set_description(temp2);

	head.push_back(*ptr);
}

//Callback for Locomotor
void LocomotorCB(Fl_Widget *w, void *p){
	Locomotor *ptr = new Locomotor();
	char *s = "Enter Locomotor name";char *d = " ";const char *a = fl_input(s, d);string temp(a);ptr->set_name(temp);
	s = "Enter Locomotor part number (digit)";d = " ";const char *b = fl_input(s, d);int x = atoi(b);ptr->set_part_number(x);
	s = "Enter Locomotor weight (digit)";d = " ";const char *c = fl_input(s, d);x = atoi(c);ptr->set_weight(x);
	s = "Enter Locomotor cost (digit)";d = " ";const char *e = fl_input(s, d);x = atoi(e);ptr->set_cost(x);
	s = "Enter Locomotor power consumed while operating (digit)";d = " ";const char *f = fl_input(s, d);x = atoi(f);ptr->set_power_consumed(x);
	s = "Enter Locomtor maximum speed(watts) while operating (digit)";d = " ";const char *k = fl_input(s, d);x = atoi(k);ptr->set_max_speed(x);
	s = "Enter  Description"; d = " "; const char *g = fl_input(s, d); string temp2(a);ptr->set_description(temp2);
	locomotor.push_back(*ptr);
}

//Callback for torso
void TorsoCB(Fl_Widget *w, void *p){
	Torso *ptr = new Torso();
	char *s = "Enter torso name";char *d = " ";const char *a = fl_input(s, d);string temp(a);ptr->set_name(temp);
	s = "Enter torso part number (digit)";d = " ";const char *b = fl_input(s, d);int x = atoi(b);ptr->set_part_number(x);
	s = "Enter torso weight (digit)";d = " ";const char *c = fl_input(s, d);x = atoi(c);ptr->set_weight(x);
	s = "Enter torso cost (digit)";d = " ";const char *e = fl_input(s, d);x = atoi(e);ptr->set_cost(x);
	s = "Enter torso Description"; d = " "; const char *g = fl_input(s, d); string temp2(a);ptr->set_description(temp2);
	ptr->set_b1(BatteryCB());
	int selection = 1, selection2 = 1;
	selection = fl_choice("Do you want another battery?", fl_no, fl_yes, 0);
	
	if (selection == 1){
		ptr->set_b2(BatteryCB());selection2 = fl_choice("Do you want another battery?", fl_no, fl_yes, 0);
		if (selection2 == 1)
			ptr->set_b3(BatteryCB());
	}

    torso.push_back(*ptr);
}

//Callback for Battery 
Battery BatteryCB() {
	Battery *ptr = new Battery();
	char *s = "Enter Battery name"; char *d = " "; const char *a = fl_input(s, d); string temp(a);
	ptr->set_name(temp);
	s = "Enter Battery part number (digit)"; d = " "; const char *b = fl_input(s, d); int x = atoi(b);ptr->set_part_number(x);
	s = "Enter Battery weight (digit)"; d = " "; const char *c = fl_input(s, d); x = atoi(c);ptr->set_weight(x);
	s = "Enter Battery cost (digit)"; d = " "; const char *e = fl_input(s, d); x = atoi(e);ptr->set_cost(x);
	s = "Enter battery power energy(kw-h) while operating (digit)"; d = " "; const char *f = fl_input(s, d); x = atoi(f);ptr->set_energy(x);
	s = "Enter battery power maximum power(watts) while operating (digit)"; d = " "; const char *k = fl_input(s, d); x = atoi(k);ptr->set_max_power(x);
	s = "Enter battery Description"; d = " "; const char *g = fl_input(s, d); string temp2(a);ptr->set_description(temp2);
	return *ptr;
}

//Callback for arm to show all torso increated by Product Manager
void show_arm(Fl_Widget *w, void *p) {
	Fl_Window *win = new Fl_Window(640, 480);
	Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 640 - 40, 480 - 40, "List of Arm");
	Fl_Text_Buffer *buff1 = new Fl_Text_Buffer();Fl_Text_Buffer *buff2 = new Fl_Text_Buffer();
	disp->buffer(buff1);
	string str_final1, str_final2;
	
	if ((int)arm.size() == 0)buff1->text("Out of Arm!!!");
	else{
		for (int i = 0; i < (int)arm.size(); i++){
			string number = to_string(i+1);string name = arm[i].get_name();string description = arm[i].get_description();
			int part_number = arm[i].get_part_number();double weight = arm[i].get_part_number();double cost = arm[i].get_cost();
			double power_consumed = arm[i].get_power_consumed();
			
			if (i == 0) {str_final1 = number + ". Name: " + name + ", Part Number: " + to_string(part_number) +
					",Weight: " + to_string(weight) + ", Cost: " + to_string(cost) + ", Power consumed: " + to_string(power_consumed) + ",Description: " + description;
				const char *c1 = str_final1.c_str(); buff1->text(c1); }
			
			else if (i%2 != 0) { str_final2 = str_final1+ "\n"+ number + ". Name: " + name + ", Part Number: " + to_string(part_number) +
				", Weight: " + to_string(weight) + ", Cost: " + to_string(cost) + ", Power consumed: " + to_string(power_consumed) + ",Description: " + description;
			    const char *c2 = str_final2.c_str(); buff1->text(c2); }
			
			else if (i%2 == 0) {str_final1 = str_final2 + "\n" + number + ". Name: " + name + ", Part Number: " + to_string(part_number) +", Weight:: " + to_string(weight) 
				+ ", Cost: " + to_string(cost) + ", Power consumed: " + to_string(power_consumed) + ",Description: " + description;
				const char *c3 = str_final1.c_str(); buff1->text(c3); }
		}
	}
	buff2->text("AAAAAAAAAA\nBBBBBBBBBB\nCCCCCCCCCC\nDDDDDDDDDD\n""AAAAAAAAAA\nBBBBBBBBBB\nCCCCCCCCCC\nDDDDDDDDDD\n");
	win->resizable(*disp);win->show();
}

//Callback for head to show all torso increated by Product Manager
void show_head(Fl_Widget *w, void *p) {
	Fl_Window *win = new Fl_Window(640, 480);
	Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 640 - 40, 480 - 40, "List of head");
	Fl_Text_Buffer *buff1 = new Fl_Text_Buffer();Fl_Text_Buffer *buff2 = new Fl_Text_Buffer();
	disp->buffer(buff1);
	string str_final1, str_final2;
	if ((int)head.size() == 0)buff1->text("Out of head!!!");
	else{
		for (int i = 0; i < (int)head.size(); i++){
			string number = to_string(i + 1); string name = head[i].get_name(); string description = head[i].get_description();
			int part_number = head[i].get_part_number(); double weight = head[i].get_part_number(); double cost = head[i].get_cost();
			
			if (i == 0) {str_final1 = number + ". Name: " + name + ", Part Number: "+ to_string(part_number) +
					", Weight: " + to_string(weight) + ", Cost: " + to_string(cost) + ",Description: " + description;
				const char *c1 = str_final1.c_str(); buff1->text(c1);}
			
			else if (i%2 != 0) {str_final2 = str_final1 + "\n" + number + ". Name: " + name + ", Part Number: " + to_string(part_number) +
					", Weight: " + to_string(weight) + ", Cost: " + to_string(cost)  + ",Description: " + description;
				const char *c2 = str_final2.c_str(); buff1->text(c2);}
			
			else if (i%2 == 0) {str_final1 = str_final2 + "\n" + number + ". Name: " + name + ", Part Number: " + to_string(part_number)
				+ ", Weight: " + to_string(weight)+ ", Cost: " + to_string(cost) + ",Description: " + description;
				const char *c3 = str_final1.c_str(); buff1->text(c3);}
		}
	}
	buff2->text("AAAAAAAAAA\nBBBBBBBBBB\nCCCCCCCCCC\nDDDDDDDDDD\n""AAAAAAAAAA\nBBBBBBBBBB\nCCCCCCCCCC\nDDDDDDDDDD\n");
	win->resizable(*disp); win->show();
}

//Callback for locomotor to show all torso increated by Product Manager
void show_locomotor(Fl_Widget *w, void *p) {
	Fl_Window *win = new Fl_Window(640, 480);
	Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 640 - 40, 480 - 40, "List of locomotor");
	Fl_Text_Buffer *buff1 = new Fl_Text_Buffer();Fl_Text_Buffer *buff2 = new Fl_Text_Buffer();
	disp->buffer(buff1);
	string str_final1, str_final2;
	if ((int)locomotor.size() == 0)buff1->text("Out of Locomotor!!!");
	else
	{for (int i = 0; i < (int)locomotor.size(); i++){
			string number = to_string(i + 1); string name = locomotor[i].get_name(); string description = locomotor[i].get_description();int part_number = locomotor[i].get_part_number(); 
			double weight = locomotor[i].get_part_number(), cost = locomotor[i].get_cost(),speed=locomotor[i].get_max_speed(),power=locomotor[i].get_power_consumed();
			
			if (i == 0) {str_final1 = number + ". Name: " + name + ", Part Number: " + to_string(part_number) +
					", Wieght: " + to_string(weight) + ", Cost: " + to_string(cost) +", Max speed: "+ to_string(speed) +", Power consumed: " +to_string(power)+",Description: " + description;
				const char *c1 = str_final1.c_str(); buff1->text(c1);}

			else if (i%2 != 0) {str_final2 = str_final1 + "\n" + number + ". Name: " + name + ", Part Number: " + to_string(part_number) +", Weight: " + to_string(weight) +
				", Cost: " + to_string(cost) + +", Max speed: " + to_string(speed) + ", Power consumed: " + to_string(power) + ",Description: " + description;
				const char *c2 = str_final2.c_str(); buff1->text(c2);}

			else if (i%2 == 0) {str_final1 = str_final2 + "\n" + number + ". Name: " + name + ", Part Number: " + to_string(part_number) + ", Weight: " + to_string(weight)+ ", Cost: " + 
				to_string(cost) +", Max speed: " + to_string(speed) + ", Power consumed: " + to_string(power) + ",Description: " + description;
				const char *c3 = str_final1.c_str(); buff1->text(c3);}
		}
	}
	buff2->text("AAAAAAAAAA\nBBBBBBBBBB\nCCCCCCCCCC\nDDDDDDDDDD\n""AAAAAAAAAA\nBBBBBBBBBB\nCCCCCCCCCC\nDDDDDDDDDD\n");
	win->resizable(*disp); win->show();
}

//Callback for torso to show all torso increated by Product Manager
void show_torso(Fl_Widget *w, void *p) {
	Fl_Window *win = new Fl_Window(640, 480);
	Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 640 - 40, 480 - 40, "List of Torso");
	Fl_Text_Buffer *buff1 = new Fl_Text_Buffer(); Fl_Text_Buffer *buff2 = new Fl_Text_Buffer();
	disp->buffer(buff1);
	string str_final1, str_final2;
	
	if ((int)torso.size() == 0)buff1->text("Out of Torso!!!");
	else{
		for (int i = 0; i < (int)torso.size(); i++){
			string number = to_string(i + 1); string name = torso[i].get_name(); string description = torso[i].get_description();
			int part_number = torso[i].get_part_number(),battery=0; double weight = torso[i].get_part_number(); double cost = torso[i].get_cost();
			if (torso[i].get_b1().get_cost() != 0) battery++;
			if (torso[i].get_b2().get_cost() != 0) battery++;
			if (torso[i].get_b3().get_cost() != 0) battery++;
			if (i == 0) {str_final1 = number + ". Name: " + name + ", Part Number: " + to_string(part_number) +
					", Weight: " + to_string(weight) + ", Cost: " + to_string(cost) +", Number of Battery: " + to_string(battery) +",Description: " + description;
				const char *c1 = str_final1.c_str(); buff1->text(c1);}

			else if (i%2 != 0) {str_final2 = str_final1 + "\n" + number + ". Name: " + name + ", Part Number: " + to_string(part_number) +
					", Weight: " + to_string(weight) + ", Cost: " + to_string(cost) + ", Number of Battery: " + to_string(battery) + ",Description: " + description;
				const char *c2 = str_final2.c_str(); buff1->text(c2);}

			else if (i%2 == 0) {str_final1 = str_final2 + "\n" + number + ". Name: " + name + ", Part Number: " + to_string(part_number) + ", Weight: " + to_string(weight)
					+ ", Cost: " + to_string(cost) + ",Description: " + ", Number of Battery: " + to_string(battery) + description;
				const char *c3 = str_final1.c_str(); buff1->text(c3);}
		}
	}
	buff2->text("AAAAAAAAAA\nBBBBBBBBBB\nCCCCCCCCCC\nDDDDDDDDDD\n""AAAAAAAAAA\nBBBBBBBBBB\nCCCCCCCCCC\nDDDDDDDDDD\n");
	win->resizable(*disp); win->show();
}

//Callback for Sales Associate to show order per associate
void show_associate_order(Fl_Widget *w, void *p) {
	    char *s = "Enter Employee number"; char *d = " "; const char *b = fl_input(s, d); int associate_number = atoi(b);
		Fl_Window *win = new Fl_Window(640, 480);
		Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 640 - 40, 480 - 40, "Orders per Sales Associate");
		Fl_Text_Buffer *buff1 = new Fl_Text_Buffer(); Fl_Text_Buffer *buff2 = new Fl_Text_Buffer();
		disp->buffer(buff1);string str_final1, str_final2;

		if (sales_associate[associate_number-1].get_order_count() == 0)buff1->text("No Order to Show!!!");
		else{
			for (int i = 0; i < sales_associate[associate_number - 1].get_order_count(); i++){
				string number = to_string(i + 1),name = order[i].get_customer().get_name(),add=order[i].get_customer().get_address(),email=order[i].get_customer().get_email();
				string phone = order[i].get_customer().get_phone(); int quant = order[i].get_quantity(), d = order[i].get_day(), m = order[i].get_month(), y = order[i].get_year();
				double bill = order[i].get_total_price_with_tax()*quant; string robot_m_name = order[i].get_robot_model().get_model_name();
				int p_num = order[i].get_robot_model().get_model_number();
				if (i == 0) {
					str_final1 = number+". Customer Name: "+name+", Customer Address: "+add+", Customer Phone: "+phone+
						", Customer Email:"+email+", Robot Model: "+robot_m_name+", Robot Part Name: "+to_string(p_num)+", Price: "+ to_string(bill)+
						", Date: "+ to_string(m)+"/"+ to_string(d)+"/"+ to_string(y);
					const char *c1 = str_final1.c_str(); buff1->text(c1);}

				else if (i % 2 != 0) {
					str_final2 = str_final1 + "\n" + number + ". Customer Name: " + name+", Customer Address: " + add + 
						", Customer Phone: " + phone + ", Customer Email:" + email + ", Robot Model: " + robot_m_name + ", Robot Part Name: " +
						to_string(p_num) + ", Price: " + to_string(bill) + ", Date: " + to_string(m) + "/" + to_string(d) + "/" + to_string(y);
					const char *c2 = str_final2.c_str(); buff1->text(c2);}

				else if (i % 2 == 0) {
					str_final1 = str_final2 + "\n" + number + ". Customer Name: " + name + ", Customer Address: " + add + 
						", Customer Phone: " + phone + ", Customer Email:" + email + ", Robot Model: " + robot_m_name + ", Robot Part Name: " + 
						to_string(p_num) + ", Price: " + to_string(bill) + ", Date: " + to_string(m) + "/" + to_string(d) + "/" + to_string(y);
					const char *c3 = str_final1.c_str(); buff1->text(c3);}
			}
		}
		buff2->text("AAAAAAAAAA\nBBBBBBBBBB\nCCCCCCCCCC\nDDDDDDDDDD\n""AAAAAAAAAA\nBBBBBBBBBB\nCCCCCCCCCC\nDDDDDDDDDD\n");
		win->resizable(*disp); win->show();
}

//Show User Manual
void user_manual(Fl_Widget *w, void *p) {
	Fl_Window *win = new Fl_Window(640, 480);
	Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 640 - 40, 480 - 40, "User Manual");
	Fl_Text_Buffer *buff1 = new Fl_Text_Buffer(); Fl_Text_Buffer *buff2 = new Fl_Text_Buffer();disp->buffer(buff1);
	string str_final1= "---------------------------------------------------------------------Welcome to Robbie Robot Shop---------------------------------------------------------------\n"
		"This shop management system helps Product Manager to create robot parts, define robot models, create customer, create sales associates,\n"
		"and create orders in the system via GUI. Customer can browse catalogue with pictures of robot models and order certain amount of robots.\n"
		"Sales associate can place an order for customers. Lastly, Product Manager and Sales Associate can view orders per Sales Associate.\n\n"
		"After running this software, a window with menu will pop up. There are five submenu such as File, Create, Create Robot Model, Report, and\n"
		"Help. If you want to create robot parts, customer, sales associate, and orders, then, options can be found under Create submenu. If you\n"
		"create robot models, then option can be found under Create Robot Model submenu. In additon, if user want to see report such components,\n"
		"robot models, and sales associates, then it can be done under Report submenu. Lastly, customer can browse catalogue with pictures in the\n"
		"Report submenu. \n";
	const char *c1 = str_final1.c_str(); buff1->text(c1);
	buff2->text("AAAAAAAAAA\nBBBBBBBBBB\nCCCCCCCCCC\nDDDDDDDDDD\n""AAAAAAAAAA\nBBBBBBBBBB\nCCCCCCCCCC\nDDDDDDDDDD\n");
	win->resizable(*disp); win->show();
}

//Show version of the product
void version(Fl_Widget *w, void *p) {
	Fl_Window *win = new Fl_Window(640, 480);
	Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 640 - 40, 480 - 40, "v2.0");
	Fl_Text_Buffer *buff1 = new Fl_Text_Buffer(); Fl_Text_Buffer *buff2 = new Fl_Text_Buffer(); disp->buffer(buff1);
	string str_final1 = "Version 2.0\nAll copyrights reserved.";
	const char *c1 = str_final1.c_str(); buff1->text(c1);
	buff2->text("AAAAAAAAAA\nBBBBBBBBBB\nCCCCCCCCCC\nDDDDDDDDDD\n""AAAAAAAAAA\nBBBBBBBBBB\nCCCCCCCCCC\nDDDDDDDDDD\n");
	win->resizable(*disp); win->show();
}

//Generate Random Data
void generate_data(){
	for (int i = 0; i < 2; i++){
		Battery *ptr = new Battery("Duracell", 11, 1.4, 0.63, "AA battery", 4.5, 100);battery.push_back(*ptr);
		ptr = new Battery("Energizer", 110, 1.4, 0.80, "AA battery", 45.5, 110);battery.push_back(*ptr);}

	for (int i = 0; i < 2; i++){
		Torso *ptr = new Torso("Baxter", 120, 10, 989.99, "Full Size Torso", battery[0]);torso.push_back(*ptr);
		ptr = new Torso("Eraxer", 120, 10, 899.99, "Medium Size Torso", battery[0], battery[1], battery[2]);torso.push_back(*ptr);}

	for (int i = 0; i < 2; i++){
		Head *ptr = new Head("MICRON", 9199, 10, 760.69, "Robot full size face");head.push_back(*ptr);
		ptr = new Head("MICRON 2", 9199, 10, 559.99, "Robot medium size face");head.push_back(*ptr);}

	for (int i = 0; i < 2; i++){
		Arm *ptr = new Arm("Lynxmotion", 9188, 20, 299.99, "Right hand", 450);arm.push_back(*ptr);
		ptr = new Arm("Lynxmotion", 9188, 20, 219.99, "Left hand", 350);arm.push_back(*ptr);}

	for (int i = 0; i < 2; i++){
		Locomotor *ptr = new Locomotor("Lyation", 2312, 40, 599.99, "High Power Motor", 100.00, 350.00);locomotor.push_back(*ptr);
		ptr = new Locomotor("Lyation", 2312, 40, 449.99, "Medium Power Motor", 100.00, 350.00);locomotor.push_back(*ptr);}
}