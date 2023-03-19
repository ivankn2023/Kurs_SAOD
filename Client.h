#pragma once
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <string>
using namespace std;



struct passport
{
	string number;
	string place;
	string date;
	string name;
	int birthday_year = 0;
	string adress_city;
};

void client_register(string pass_num);


struct node {
	node* prev;
	passport data;
	node* next;
	node(string number, string place, string date, string name, int birthday_year, string adress)
	{
		prev = NULL;
		data.number = number;
		data.place = place;
		data.date = date;
		data.name = name;
		data.birthday_year = birthday_year;
		data.adress_city = adress;
		next = NULL;
	}
};
void insertik(node*& head, string number, string place, string date, string name, int birthday_year, string adress);
int getsizik(node* head);
int* returnik(node* head);
void deletik(node*& head);
void coutik(node* head);



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
drevo* add(drevo*& Root, string num, string plc, string dat, string nam, int bir, string cit);
drevo* find_min(drevo*& Root);
drevo* rem_min(drevo*& Root);
drevo* del(struct drevo*& Root, string value);
int no_unic_number(struct drevo* Root, string num);
string find_client_year(struct drevo* Root, string value);
void find_name(drevo* tree, string nam);
void find_adress(drevo* tree, string nam);
void treeprint(drevo*& tree);
void find_number(drevo* tree, string nam);

void ClientChoise();

int client_year_return(string s);
bool passport_trouble(string s);
bool date_trouble(string s);
bool calendar_trouble(int day, int month, int year);
bool have_no_letter(string s);
bool have_symbols(string s);
bool have_no_numbers(string s);
bool client_date_trouble(int year, string s);
string to_up(string s);