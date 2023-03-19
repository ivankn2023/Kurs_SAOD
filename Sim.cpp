#include "Sim.h"
#include "Extradition.h"
extern int sim_table_value;
extern sim* table;
int addest = 0;
int free_slot = 0;
list* title = NULL;
extern main_data_list* header;

void insertik_sim(list*& title , string number, string tarif, int open_year, bool is_free)
{
    if (title == NULL) {
        list* n = new list(number, tarif, open_year, is_free);
        n->next = title;
        if (title != NULL) {
            title->prev = n;
        }
        title = n;
        return;
    }
    list* n = new list(number, tarif, open_year, is_free);
    list* temp = title;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}
int getsizik_sim(list* title)
{
    int q = 0;
    list* temp = title;
    if (temp == NULL) return 0;
    while (temp != NULL) {
        temp = temp->next;
        q++;
    }
    return q;
}
void deletik_sim(list*& title)
{
    list* temp = title;
    while (temp->next)
    {
        temp = temp->next;
        title = temp->next;
    }
    delete temp;
}
void coutik_sim(list* title) {
    list* temp = title;
    if (temp == NULL) return;
    while (temp != NULL) {
        cout << endl;
        cout << temp->simka.number << endl;
        cout << temp->simka.tarif << endl;
        cout << temp->simka.open_year << endl;
        if (temp->simka.is_free) cout << "СВОБОДНА" << endl;
        else cout << "ЗАНЯТА" << endl;
        temp = temp->next;
    }
    return;
}


void decision_collision(sim a) {
        int hesh = 0;
        int i = 0;
        int c = 13;
        int iter = 0;
        while (iter < 25)
        {
            iter++;
            hesh = hash_number(a.number) + c * i;
            hesh %= sim_table_value;
            if ((table[hesh].number == " ") || (table[hesh].number == "DEL")) {
                table[hesh].number = a.number;
                table[hesh].tarif = a.tarif;
                table[hesh].open_year = a.open_year;
                table[hesh].is_free = a.is_free;
                addest++;
                break;
            }
            else i++;
        }
        if (iter == 25) cout << "Увы, мы не смогли добавить, попробуйте снова с другим номером"<<endl;
}

int hash_number(string s) {
    int heshik = 0;
    char num;
    for (int i = 0; i < s.length(); i++) {
        num = s[i];
        heshik += pow(int(num) * (i + 1), 2);
    }
    return heshik % sim_table_value;
}

void add_hash_function(sim a) {

    int hesh = hash_number(a.number);
    if ((table[hesh].number == " ") || (table[hesh].number == "DEL")) {
        table[hesh].number = a.number;
        table[hesh].tarif = a.tarif;
        table[hesh].open_year = a.open_year;
        table[hesh].is_free = a.is_free;
        addest++;
    }
    else decision_collision(a);
}

int sim_find(string s) {
    int hesh = 0;
    int i = 0;
    int c = 29;
    while (i < 25)
    {
        hesh = hash_number(s) + c * i;
        hesh %= sim_table_value;
        if (table[hesh].number == s) {
            return hesh;
        }
        if ((table[hesh].number == " ")||(table[hesh].number == "DEL")) return -1;
        else i++;
    }
    return -1;
}

bool sim_del(string s) {
    if (sim_find(s) == -1) return 1;

}

bool sim_no_unic(string s) {
    if (sim_find(s) == -1) return 0;
    else return 1;
}

int tarif_find(string s) {
    for (int i = 0; i < sim_table_value; i++)
    {
        if (table[i].tarif == s)
            insertik_sim(title, table[i].number, table[i].tarif, table[i].open_year, table[i].is_free);
    }
    if (getsizik_sim(title) == 0) return -1;
    else return 1;
}

bool is_sim_free(string s) {
    int i = sim_find(s);
    if (table[i].is_free == true) return 1;
    else return false;
}

int sim_year_return(string s) {
    int i = sim_find(s);
    return table[i].open_year;
}

void sim_find_number(string s) {
    int num = sim_find(s);
    if (num == -1) {
        cout << "Не удалось найти сим-карту с таким номером" << endl;
    }
    else {

            cout << "Номер карты: " << table[num].number << endl;
            cout << "Тариф: " << table[num].tarif << endl;
            cout << "Год открытия: " << table[num].open_year << endl;
            if (!table[num].is_free) {
                find_cout_client_inf(header, s);
                cout << endl << endl;
            }
            else cout << "СВОБОДНА" << endl << endl;
    }
}

void made_sim_nofree(string s) {
    int i = sim_find(s);
    table[i].is_free = false;

}

void made_sim_free(string s) {
    int i = sim_find(s);
    table[i].is_free = true;

}

void sim_del_all() {
    for (int i = 0; i < sim_table_value; i++) {
        table[i].number = " ";
    }
}

void SimChoise() {
    sim cart;
    int sim_enter;
    string sim_number;
    string sim_tarif;
    int sim_year = 0;
    int result;
    int sim_finder = 0;
    while (true)
    {
        cin.sync();
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        cout << "Регистрация новой сим-карты (1)" << endl;
        cout << "Удаление сим-карты (2)" << endl;
        cout << "Удалить все сим-карты (3)" << endl;
        cout << "Просмотр всех сим-карт (4)" << endl;
        cout << "Поиск сим-карты (5)" << endl;
        cout << "Вернуться в главное меню (0)" << endl;
        cout << "Ваш ввод: ";
        while (!(cin >> sim_enter) || (cin.peek() != '\n') || (sim_enter != round(sim_enter)) || (sim_enter < 1) || (sim_enter > 5))
        {
            if (sim_enter == 0) return;
            cin.clear();
            while (cin.get() != '\n');
            cout << "Некорректный ввод" << endl;
            cout << " ДЕЙСТВИЕ ПОД НОМЕРОМ: ";
        }
        break;
    }
    cin.sync();
    cin.clear();
    cin.ignore(cin.rdbuf()->in_avail());
    if (sim_enter == 1) {
        if (addest == sim_table_value) {
            cout << "БАЗА ДАННЫХ СЛИШКОМ ЗАНЯТА, УДАЛИТЕ ЧТО-НИБУДЬ" << endl;
            return;
        }
        cout << "Вернуться в главное меню (0)" << endl;
        cout << "Введите номер сим-карты: ";

        while ((!getline(cin, sim_number)) || (sim_number_trouble(sim_number))||(sim_no_unic(sim_number)))
        {
            if (sim_number == "0") {
                cout << "Возврат в главное меню" << endl;
                return;
            }
            if (sim_no_unic(sim_number)) {
                cout << "Такая сим-карта уже есть, нужны уникальные номера" << endl;
                cout << "Введите номер сим-карты: ";
                continue;
            }
            cout << "Неправильный формат, повторите попытку" << endl;
            cout << "Введите номер сим-карты: ";
            cin.sync();
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());
        }
        cin.sync();
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());

        cout << "Вернуться в главное меню (0)" << endl;
        cout << "Введите тариф сим-карты: ";
        while ((!getline(cin, sim_tarif)) || (tarif_trouble(sim_tarif)))
        {
            if (sim_tarif == "0") {
                cout << "Возврат в главное меню" << endl;
                return;
            }
            cout << "Такого тарифа нет, повторите попытку" << endl;
            cout << "Введите тариф сим-карты: ";
            cin.sync();
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());
        }
        cin.sync();
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());

        cout << "Вернуться в главное меню (0)" << endl;
        cout << "Введите год выпуска сим-карты: ";
        while (!(cin>>sim_year) || (cin.peek() != '\n') || (sim_year_trouble(sim_year)))
        {
            if (sim_year == 0) {
                cout << "Возврат в главное меню" << endl;
                return;
            }
            cout << "Неправильный формат, повторите попытку" << endl;
            cout << "Введите год выпуска сим-карты: ";
            cin.sync();
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());
        }
        cin.sync();
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        sim_tarif = to_up(sim_tarif);
        cart.number = sim_number;
        cart.tarif = sim_tarif;
        cart.open_year = sim_year;
        cart.is_free = true;

        add_hash_function(cart);

        cout << "Сим-карта успешно добавлена" << endl;
        cout << "Возврат в главное меню" << endl;
    }

    if (sim_enter == 2) {
        cin.sync();
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        if (addest == 0) {
            cout << "БАЗА ПУСТАЯ, УДАЛЯТЬ НЕЧЕГО" << endl;
            return;
        }
        cout << "Вернуться в главное меню (0)" << endl;
        cout << "Введите номер сим-карты, которую хотите удалить: ";
        while ((!getline(cin, sim_number)) || (sim_number_trouble(sim_number)))
        {
            if (sim_number == "0") {
                cout << "Возврат в главное меню" << endl;
                return;
            }
            cout << "Неправильный формат, повторите попытку" << endl;
            cout << "Введите номер сим-карты: ";
            cin.sync();
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());
        }
        cin.sync();
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());

        if (sim_del(sim_number)) cout << "Элемент не удалось найти" << endl;
        else cout << "Ваш элемент успешно удалён" << endl;
        addest--;
        return;
    }

    if (sim_enter == 3) {

        if (addest == 0) {
            cout << "БАЗА ПУСТАЯ, УДАЛЯТЬ НЕЧЕГО" << endl;
            return;
        }
        sim_del_all();
        addest = 0;
        cout << "ВСЯ БАЗА СИМ-КАРТ УДАЛЕНА" << endl;
    }

    if (sim_enter == 4) {
        if (addest == 0) {
            cout << "БАЗА ПУСТА, ВСЕ СЛОТЫ СВОБОДНЫ" << endl;
            return;
        }
        print_all_sim();
    }

    if (sim_enter == 5) {

        cin.sync();
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        cout << "Поиск по Тарифу (1)" << endl;
        cout << "Поиск по номеру сим-карты (2)" << endl;
        cout << "Вернуться в главное меню (0)" << endl;
        cout << " ДЕЙСТВИЕ ПОД НОМЕРОМ: ";

        while (!(cin >> sim_finder) || (cin.peek() != '\n') || (sim_finder != round(sim_finder)) || (sim_finder < 1) || (sim_finder > 2))
        {
            if (sim_finder == 0) return;
            cin.clear();
            while (cin.get() != '\n');
            cout << "Некорректный ввод" << endl;
            cout << " ДЕЙСТВИЕ ПОД НОМЕРОМ: ";
            cin.sync();
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());
        }
        if (sim_finder == 1) {
            cin.sync();
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());
            cout << "Вернуться в главное меню (0)" << endl;
            cout << "Введите тариф для поиска:";
            while ((!getline(cin, sim_tarif)) || (tarif_trouble(sim_tarif)))
            {
                if (sim_tarif == "0") {
                    cout << "Возврат в главное меню" << endl;
                    return;
                }
                cout << "Неправильный формат, повторите попытку" << endl;
                cout << "Введите номер сим-карты: ";
                cin.sync();
                cin.clear();
                cin.ignore(cin.rdbuf()->in_avail());
            }
            cin.sync();
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());

            if (tarif_find(sim_tarif)) {
                cout << "Всё, что удалось найти" << endl;
                coutik_sim(title);
                deletik_sim(title);
                return;
            }

            else cout << "Ничего найти не удалось" << endl;
            return;
        }
        if (sim_finder == 2) {
            cin.sync();
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());
            cout << "Вернуться в главное меню (0)" << endl;
            cout << "Введите номер сим-карты, которую хотите найти: ";
            while ((!getline(cin, sim_number)) || (sim_number_trouble(sim_number)))
            {
                if (sim_tarif == "0") {
                    cout << "Возврат в главное меню" << endl;
                    return;
                }
                cout << "Неправильный формат, повторите попытку" << endl;
                cout << "Введите номер сим-карты: ";
                cin.sync();
                cin.clear();
                cin.ignore(cin.rdbuf()->in_avail());
            }
            cin.sync();
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());
            sim_find_number(sim_number);
            return;
        }
        
    }
}

void print_all_sim() {
    cout << "ВСЕГО СИСТЕМА ПОДДЕРЖИВАЕТ " << sim_table_value << " СИМ-КАРТ" << endl;
    cout << "СПИСОК ЗАНЯТЫХ СЛОТОВ БАЗЫ:" << endl << endl;
    free_slot = 0;
    for (int i = 0; i < sim_table_value; i++) {
        if ((table[i].number == " ") || (table[i].number == "DEL")) free_slot++;
        else {
            cout << "Номер карты: " << table[i].number << endl;
            cout << "Тариф: " << table[i].tarif << endl;
            cout << "Год открытия: " << table[i].open_year << endl;
            if (table[i].is_free) cout << "СВОБОДНА" << endl << endl;
            else cout << "\x1b[31mЗАНЯТА\x1b[0m" << endl << endl;
        }
    }
    if (free_slot) {

        cout << "КОЛИЧЕСТВО СВОБОДНЫХ СЛОТОВ: " << free_slot << endl;
    }
    if (free_slot == 0) {
        cout << "СВОБОДНЫХ СЛОТОВ НЕТ" << endl;
    }
}

int amount_of_free_sim() {
    int isfr = 0;
    for (int i = 0; i < sim_table_value; i++) {
        if ((table[i].is_free) && (table[i].number != " ") && (table[i].number != "DEL")) {
            isfr++;
        }
    }
    if (isfr == 0) {
        return 0;
    }
    return 1;
}

int print_free_sim() {
    int isfr = 0;
    for (int i = 0; i < sim_table_value; i++) {
        if ((table[i].is_free)&&(table[i].number != " ") && (table[i].number != "DEL")) {
            cout << "Номер карты: " << table[i].number << endl;
            cout << "Тариф: " << table[i].tarif << endl;
            cout << "Год открытия: " << table[i].open_year << endl << endl;
            isfr++;
        }
    }
    if (isfr == 0) {
        cout << "Свободных сим-карт нет, клиенту придётся отказать" << endl;
        return 0;
    }
    return 1;
}

bool sim_number_trouble(string s) {
    if (s.length() != 11) return 1; //234-0123456
    string s1 = { s[0], s[1], s[2] };
    char s2 = s[3];
    string s3 = { s[4], s[5], s[6],s[7], s[8], s[9], s[10] };
    string numbers = "1234567890";
    int inc = 0;
    for (int i = 0; i < 3; i++)
    {
        inc = 0;
        for (int j = 0; j < 10; j++)
        {
            if (s[i] != numbers[j]) inc++;
        }
        if (inc == 10) return 1;
    }

    if (s2 != '-') return 1;

    for (int i = 4; i < 11; i++)
    {
        inc = 0;
        for (int j = 0; j < 10; j++)
        {
            if (s[i] != numbers[j]) inc++;
        }
        if (inc == 10) return 1;
    }

    return 0;
}

bool tarif_trouble(string s) {
    string all_tarif[5] = { "МИНИМАЛЬНЫЙ", "МАКСИМАЛЬНЫЙ", "ПРАКТИЧНЫЙ" , "УДАЧНЫЙ", "VIP" };
    s = to_up(s);
    for (int i = 0; i < all_tarif->length(); i++) {
        if (all_tarif[i] == s) return 0;
    }
    return 1;
}

bool sim_year_trouble(int year)
{
    if (year != round(year)) return 1;
    if ((year < 2000) || (year > 2023)) return 1;
    return 0;
}