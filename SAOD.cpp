#include "Client.h"
#include "Reader.h"

int MenuMainNum = 1;

void Menu()
{
	cout << "Выберите, что вы хотите сделать:" << endl;
	cout << " Выход из программы (0)" << endl;
	cout << " Действия с клиентом (1)" << endl;
	cout << " Действия с SIM-Картой (2)" << endl;


	cout << " ДЕЙСТВИЕ ПОД НОМЕРОМ: ";
	while (!(cin >> MenuMainNum) || (cin.peek() != '\n') || (MenuMainNum != round(MenuMainNum)) 
								|| (MenuMainNum < 0) || (MenuMainNum > 2))
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

		}
		cout << endl;
	}

	cout << " Спасибо что воспользовались нашим приложением" << endl;
	return 0;
}