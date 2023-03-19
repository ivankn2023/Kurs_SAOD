#include "Reader.h"
#include "Client.h"
#include "Sim.h"
#include "Extradition.h"
extern drevo* obj;
extern main_data_list* header;


void reading()
{
	setlocale(LC_ALL, "RUS");
	string number;
	string loc_dat;
	string place = "";
	string date = "";
	string name;
	string years;
	int year;
	string city;
	string nothing;
	int num = 0;

	sim readcart;
	string sim_num;
	string sim_tar;
	string sim_yer;
	int sim_yar;
	bool freesim =false;

	string first;
	string second;
	setlocale(LC_ALL, "RUS");
	ifstream in("baza.txt");
	while (!in.eof())
	{
		getline(in, number);
		getline(in, loc_dat);

		for (int i = 0; i < loc_dat.length(); i++) {
			if ((loc_dat[i] != ',')&&(num==0)) {
				place += loc_dat[i];
				continue;
			}
			else {
				num ++;
			}
			if (num > 2) {
				date += loc_dat[i];
			}
		}
		num = 0;


		getline(in, name);
		getline(in, years);
		year = stoi(years);
		getline(in, city);



		getline(in, sim_num);
		getline(in, sim_tar);
		getline(in, sim_yer);
		sim_yar = stoi(sim_yer);


		getline(in, first);
		getline(in, second);




		if (to_up(second) == "ÀÊÒÈÂÍÀ") freesim = false;
		if (!date_trouble(second)) freesim = true;
		if(!no_unic_number(obj, number)) obj = add(obj, number, place, date, name, year, city);

		place = "";
		date = "";

		readcart.number = sim_num;
		readcart.tarif = sim_tar;
		readcart.open_year = sim_yar;
		readcart.is_free = freesim;
		add_hash_function(readcart);

		if(!freesim) insertik_main_data(header, number, sim_num, first, second);

		getline(in, nothing);
	}
	in.close();
}