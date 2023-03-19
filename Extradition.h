#pragma once
#include "Client.h"
#include "Sim.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


struct main_data_list {
	main_data_list* prev;
	string clientik;
	string simka_number;
	string first_date;
	string last_date;
	main_data_list* next;
	main_data_list(string pas_num, string sim_num, string first, string last)
	{
		prev = NULL;
		clientik = pas_num;
		simka_number = sim_num;
		first_date = first;
		last_date = last;
		next = NULL;
	}
};
void insertik_main_data(main_data_list*& header, string pass_num, string sim_num, string first, string last);
int getsizik_main_data(main_data_list* header);
void coutik_main_data(main_data_list* header);
void find_cout_data(main_data_list* header, string pass_num);
void find_cout_sim_inf(main_data_list* header, string pass_num);
void find_cout_client_inf(main_data_list* header, string pass_num);
string returnik_main_data_first(main_data_list* header, string s);
void del_main_data(main_data_list*& header, string s);
int client_has_sim(main_data_list*& header, string s, string pass);
void sort_main_data(main_data_list*& header);
void insertik_main_data_sort(main_data_list*& header, string pass_num, string sim_num, string first, string last);

void Extradition_Choise();

int last_trouble(string last, string number);
int registr_date_trouble(string s, string pass, string num);
int year_of_date_return(string s);