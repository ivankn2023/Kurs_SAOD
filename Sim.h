#pragma once
#include "Client.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct sim {
	string number;
	string tarif;
	int open_year = 0;
	bool is_free = true;
};

struct list {
	list* prev;
	sim simka;
	list* next;
	list(string number, string tarif, int open_year, bool is_free)
	{
		prev = NULL;
		simka.number = number;
		simka.tarif = tarif;
		simka.open_year = open_year;
		simka.is_free = is_free;
		next = NULL;
	}
};
void insertik_sim(list*& title, string number, string tarif, int open_year, bool is_free);
int getsizik_sim(list* title);
void deletik_sim(list*& title);
void coutik_sim(list* title);



int hash_number(string);
void add_hash_function(sim);
void decision_collision(sim);
int sim_find(string);
bool sim_del(string);
bool sim_no_unic(string s);
bool is_sim_free(string s);
int sim_year_return(string s);
void sim_find_number(string s);
void made_sim_nofree(string s);
void made_sim_free(string s);
void sim_del_all();

void SimChoise();

int print_free_sim();
void print_all_sim();
int amount_of_free_sim();
bool sim_number_trouble(string);
bool tarif_trouble(string);
bool sim_year_trouble(int);