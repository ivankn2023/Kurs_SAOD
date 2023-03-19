#include "Client.h"
#include "Reader.h"
#include "Sim.h"
#include "Extradition.h"
int MenuMainNum = 1;
drevo* obj = NULL;
main_data_list* header = NULL;
int sim_table_value = 10;
node* head = NULL;
sim* table = new sim[sim_table_value];


void Menu()
{
	cout << "Главное меню оператора сотовой связи:" << endl<<endl;
	cout << "Выберите, что вы хотите сделать:" << endl;
	cout << " Выход из программы (0)" << endl;
	cout << " Действия с базой клиентов (1)" << endl;
	cout << " Действия с базой сим-карт (2)" << endl;
	cout << " Регистрация выдачи или возврата сим-карты (3)" << endl;
	//cout << " Считать базу данных пользователей (4)" << endl;
	cout << " ДЕЙСТВИЕ ПОД НОМЕРОМ: ";
	while (!(cin >> MenuMainNum) || (cin.peek() != '\n') || (MenuMainNum != round(MenuMainNum))
		|| (MenuMainNum < 0) || (MenuMainNum > 4))
	{

		cin.clear();
		while (cin.get() != '\n');
		cout << "Некорректный ввод" << endl;
		cout << " ДЕЙСТВИЕ ПОД НОМЕРОМ: ";
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << " Вас приветствует оператор связи" << endl << endl;
	for (int i = 0; i < sim_table_value; i++) {
		table[i].number = " ";
	}
	while (MenuMainNum != 0)
	{
		Menu();
		system("cls");
		if (MenuMainNum == 0) break;
		if (MenuMainNum == 1)
		{
			ClientChoise();
		}

		if (MenuMainNum == 2)
		{
			SimChoise();
		}
		if (MenuMainNum == 3)
		{
			Extradition_Choise();
		}

		if (MenuMainNum == 4)
		{
			reading();
		}

		cout << endl;
	}

	cout << " Спасибо что воспользовались нашим приложением" << endl;
	return 0;
}