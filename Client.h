#pragma once
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <string>
using namespace std;

using namespace std;
struct node {
	node* prev;
	string node_name;
	string node_adress;
	node* next;
	node(string nodname, string nodadress)
	{
		prev = NULL;
		node_name = nodname;
		node_name = nodadress;
		next = NULL;
	}
};
void insertik(node*& head, string, string);
int getsizik(node* head);
string* returnik(node* head);
void delet(node*& head);

struct addition
{
	string num;
	string plc;
	string dat;
	string sur;
	string nam;
	string pat;
	int bir;
	string cit;
	string str;;
	string hos;
	string flt;

	addition(string, string, string, string, string, string, int, string, string, string, string);
};

struct passport
{
	string number;
	string place;
	string date;
	//string surname;
	string name;
	//string patronymic;
	int birthday_year;
	string adress_city;
	string adress_street;
	string adress_house;
	string adress_flat;
};

struct sim
{
	string sim_number;
	string sim_tarif;
	int sim_year;
	bool active;
};

struct drevo {
public:
	drevo* left;
	drevo* right;
	string value;
	int height;
	passport client;
};
int height(struct drevo*& elem);
int bfactor(struct drevo*& elem);
void fixheight(struct drevo*& elem);
drevo* righting(struct drevo*& elem);
drevo* lefting(struct drevo*& elem);
drevo* balance(drevo* p);
drevo* add(drevo*& Root, addition);
drevo* find_min(drevo*& Root);
drevo* rem_min(drevo*& Root);
drevo* del(struct drevo*& Root, string value);
void find_number(struct drevo* Root, string value);
void find_name(struct drevo* Root, string value);
void treeprint(drevo*& tree);


void ClientChoise();
bool passport_trouble(string s);
bool date_trouble(string s);
bool calendar_trouble(int day, int month, int year);
bool have_no_letter(string s);
bool have_symbols(string s);
bool have_no_numbers(string s);
bool client_date_trouble(int year, string s);
string to_up(string s);