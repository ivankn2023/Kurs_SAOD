#include "Reader.h"
//void List::stream()
//{
//	ofstream out("vasha_baza.txt");
//	marsh* current = head;
//	out << setw(5) << "Номер";
//	out << " | " << setw(max_size) << "Начало";
//	out << " | " << setw(max_size) << "Конец";
//	out << endl;
//	out << setw(5) << "------";
//	out << setfill('-') << setw(2 * max_size + 6) << '-';
//	out << endl << setfill(' ');
//	while (current != NULL)
//	{
//		out << setw(5) << current->number << " | ";
//		out << setw(max_size) << current->start << " | ";
//		out << setw(max_size) << current->finish;
//		current = current->next;
//		if (current != NULL) out << endl;
//	}
//	out.close();
//}
//
// 






void reading()
{
	setlocale(LC_ALL, "RUS");
	string nm, st, fi;
	int num = 0;
	setlocale(LC_ALL, "RUS");
	ifstream in("baza.txt");
	if (!in.is_open())
	{
		cout << "Файл пустой" << endl;
		return;
	}

	getline(in, nm);
	cout << nm << endl;
	getline(in, st);
	cout << st << endl;
	getline(in, fi);
	cout << fi << endl;
	in.close();
}

void streaming() {
	ofstream out("vasha_baza.txt");
	out << "YA" << endl;
	out << "YEEE" << endl;
	out.close();
}
//	bool erorik = 0;
//	bool er_infile = 0;
//	bool tr_num = 0;
//	bool gotnum = false;
//	while (!in.eof()) {
//		if (!gotnum) {
//			getline(in, nm);
//			try {
//				num = stoi(nm);
//			}
//			catch (std::invalid_argument) {
//				continue;
//				er_infile = 1;
//			}
//		}
//		getline(in, st);
//		if (string_truble(st)) {
//			er_infile = 1;
//			try {
//				num = stoi(st);
//				gotnum = true;
//				continue;
//			}
//			catch (std::invalid_argument) {
//				gotnum = false;
//				max_size = 0;
//				continue;
//			}
//		}
//		getline(in, fi);
//		if (string_truble(fi)) {
//			er_infile = 1;			try {
//				num = stoi(fi);
//				gotnum = true;
//				continue;
//			}
//			catch (std::invalid_argument) {
//				gotnum = false;
//				continue;
//			}
//		}
//		gotnum = false;
//		if ((num < 0) || (num > 999)) er_infile = 1;
//		else
//			if (!un_unic(num)) {
//				addNode(st, fi, num);
//				if (fi.size() > max_size) max_size = fi.size();
//				if (st.size() > max_size) max_size = st.size();
//			}
//			else
//			{
//				if (!erorik)
//				{
//					cout << "Часть данных не записана по причине их неуникальности." << endl;
//					erorik = 1;
//				}
//			}
//	}
//	if (er_infile) {
//		cout << "Некоторые данные не записаны ввиду их некорректности." << endl;
//	}
//	in.close();
//	cout << "Данные из базы теперь в вашем распоряжении" << endl;
//}

