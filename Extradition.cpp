#include "Extradition.h"
#include "Client.h"
#include "Sim.h"

extern drevo* obj;
extern main_data_list* header;

void insertik_main_data(main_data_list*& header, string pass_num, string sim_num, string first, string last)
{
    if (header == NULL) {
        main_data_list* n = new main_data_list(pass_num, sim_num, first, last);
        n->next = header;
        if (header != NULL) {
            header->prev = n;
        }
        header = n;
        return;
    }
    main_data_list* n = new  main_data_list(pass_num, sim_num, first, last);
    main_data_list* temp = header;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;

    sort_main_data(header);
}

void insertik_main_data_sort(main_data_list*& header, string pass_num, string sim_num, string first, string last)
{
    if (header == NULL) {
        main_data_list* n = new main_data_list(pass_num, sim_num, first, last);
        n->next = header;
        if (header != NULL) {
            header->prev = n;
        }
        header = n;
        return;
    }
    main_data_list* n = new  main_data_list(pass_num, sim_num, first, last);
    main_data_list* temp = header;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

int getsizik_main_data(main_data_list* header)
{
    int q = 0;
    main_data_list* temp = header;
    if (temp == NULL) return 0;
    while (temp != NULL) {
        temp = temp->next;
        q++;
    }
    return q;
}

void sort_main_data(main_data_list*& header) {
    int n = getsizik_main_data(header);
    string* mas = new string[n];
    int i = 0;
    main_data_list* current = header;
    main_data_list* now = header;
    while (current != NULL)
    {
        mas[i] =current->simka_number;
        current = current->next;
        i++;

    }
    string* mas2 = new string[n];

    int* mas1 = new int[n];
    for (int i = 0; i < n; i++)
    {
        mas1[i] = 0;
    }

    for (int i = n - 1; i > 0; i--)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (strcmp(mas[i].c_str(), mas[j].c_str()) < 0) mas1[j]++;
            else mas1[i]++;
        }
    }
    for (int j = 0; j < n; j++)
    {
        mas2[mas1[j]] = mas[j];
    }
    //� �as2 ���������������
    for (int j = 0; j < n; j++) {
        string num = mas2[j];
        now = header;
        while (now != NULL)
        {
            if (num == now->simka_number)
            {
                string pass = now->clientik;
                string ls = now->last_date;
                string fs = now->first_date;
                insertik_main_data_sort(header, pass, num, fs, ls);
                del_main_data(header, num);
                break;
            }
            now = now->next;
        }
    }
    delete [] mas2;
    delete []mas1;
    delete []mas;
}

void coutik_main_data(main_data_list* header) {
    main_data_list* temp = header;
    if (temp == NULL) return;
    while (temp != NULL) {
        cout << temp->clientik << endl;
        cout << temp->simka_number << endl;
        cout << temp->first_date << endl;
        cout << temp->last_date << endl;
        temp = temp->next;
    }
    return;
}

string returnik_main_data_first(main_data_list* header, string s) {
    main_data_list* temp = header;
    if (temp == NULL) return 0;
    while (temp != NULL) {
        if (temp->simka_number == s)
        {
            return temp->first_date;
        }
        temp = temp->next;
    }
    return 0;
}

void find_cout_data(main_data_list* header, string pass_num) {
    main_data_list* temp = header;
    if (temp == NULL) return;
    if (temp->clientik == pass_num)
    {
        cout << endl;
        cout << temp->clientik << endl;
        cout << temp->simka_number << endl;
        cout << temp->first_date << endl;
        cout << temp->last_date << endl<<endl;
    }
    temp = temp->next;
    while (temp != NULL) {
        if (temp->clientik == pass_num)
        {
            cout << temp->simka_number << endl;
            cout << temp->first_date << endl;
            cout << temp->last_date << endl << endl;
        }
        temp = temp->next;
    }
    return;
}

void find_cout_sim_inf(main_data_list* header, string pass_num) {
    main_data_list* temp = header;
    if (temp == NULL) return;
    if (temp->clientik == pass_num)
    {
        cout << endl;
        cout << temp->simka_number << endl;
    }
    temp = temp->next;
    while (temp != NULL) {
        if (temp->clientik == pass_num)
        {
            cout << temp->simka_number << endl;
        }
        temp = temp->next;
    }
    return;
}

void find_cout_client_inf(main_data_list* header, string pass_num) {
    main_data_list* temp = header;
    if (temp == NULL) return;

    while (temp != NULL) {
        if (temp->simka_number == pass_num)
        {
            cout<<"����� �������� �������: " << temp->clientik << endl << endl;
            return;
        }
        temp = temp->next;
    }
    return;
}

void del_main_data(main_data_list*& header, string s) {
    main_data_list* current = header;
    main_data_list* now = NULL;
    if (current->simka_number == s) {
        if (current->next != NULL) {
            header = current->next;
            header->prev = NULL;
        }
        else {
            header = NULL;
        }
        delete current;
        return;
    }
    while (current != NULL)
    {
        if (current->next == nullptr) return;
        if (s == current->next->simka_number)
        {
            now = current->next;
            if (current->next->next == NULL) {
                current->next = NULL;
            }
            else {
                now = current->next->next;
                current->next->next->prev = current;
                current->next = now;
            }
            return;
        }
        current = current->next;
    }
}

int find_client_is(main_data_list* header, string s) {
    main_data_list* temp = header;
    int k = 0;
    if (temp == NULL) return 0;
    if (temp->clientik == s)
    {
        k++;
        cout << endl;
        cout << temp->clientik << endl;
        cout << temp->simka_number << endl;
        cout << temp->first_date << endl;
        cout << temp->last_date << endl << endl;
    }
    temp = temp->next;
    while (temp != NULL) {
        if (temp->clientik == s)
        {
            k++;
            cout << temp->simka_number << endl;
            cout << temp->first_date << endl;
            cout << temp->last_date << endl << endl;
        }
        temp = temp->next;
    }
    if (k) return 1;
    else return 0;
}

int client_has_sim(main_data_list*& header, string num, string pass) {
    main_data_list* temp = header;
    int k = 0;
    if (temp == NULL) return 0;
    while (temp != NULL) {
        if (temp->clientik == pass)
        {
            if (temp->simka_number == num) return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int is_sim_free_ext(main_data_list* header, string number) {
    main_data_list* temp = header;
    int k = 0;
    if (temp == NULL) return 1;
    while (temp != NULL) {
        if (temp->clientik == number) return 0;
        temp = temp->next;
    }
    return 1;
}




void Extradition_Choise()
{
    cin.sync();
    cin.clear();
    cin.ignore(cin.rdbuf()->in_avail());
    int extr_enter = 0;
    string ext_pass;
    string ext_number;
    string ext_date;
    string ext_date_out = "�������";
    string ext_date_out_2;
    cout << "����������� ������ ���-�����(1)" << endl;
    cout << "����������� �������� (2)" << endl;
    cout << "��������� � ������� ���� (0)" << endl;
    cout << "��� ����: ";
    while (!(cin >> extr_enter) || (cin.peek() != '\n') || (extr_enter != round(extr_enter)) || (extr_enter < 1) || (extr_enter > 2))
    {
        if (extr_enter == 0) {
            cout << "������� � ������� ����" << endl;
            return;
        }
        cin.clear();
        while (cin.get() != '\n');
        cout << "������������ ����" << endl;
        cout << " �������� ��� �������: ";
    }

    if (extr_enter == 1) {
        cin.sync();
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        if (!amount_of_free_sim()) {
            cout << "� ���� ��� ��������� ���-����, ������ ������ �� �������" << endl;
        }
        cout << "��������� � ������� ���� (0)" << endl;
        cout << "������� ����� �������� �������: ";
        while ((!getline(cin, ext_pass)) || (passport_trouble(ext_pass)))
        {
            if (ext_pass == "0") {
                cout << "������� � ������� ����" << endl;
                return;
            }
            cout << "������������ ������, ��������� �������" << endl;
            cout << "������� ����� �������� �������: ";
            cin.sync();
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());
        }
        cin.sync();
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        if (!no_unic_number(obj, ext_pass)) {
            cout << "������ � ���� ������� �������� �� ����������, �� ����� ��� ���������������� ����� ������" << endl;
            cout << "���������������� ������ ������� (1) " << endl;
            cout << "���� � ������� ���� (0)" << endl;
            cout << "��� �����: ";
            while (!(cin >> extr_enter) || (cin.peek() != '\n') || (extr_enter != round(extr_enter)) || (extr_enter != 1))
            {
                if (extr_enter == 0) {
                    cout << "������� � ������� ����" << endl;
                    return;
                }
                cout << "������������ ������, ��������� �������" << endl;
                cout << "������� ����� �������� �������: ";
                cin.sync();
                cin.clear();
                cin.ignore(cin.rdbuf()->in_avail());
            }

            client_register(ext_pass);
            cout << "������ ���������������" << endl;
        }
        else {
            find_cout_data(header, ext_pass);
        }
        cin.sync();
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());

        cout << "����� ������ ����� ���-����� �� ������ ����������� ��������� ���-�����" << endl;
        cout << "��������� �������� (1) " << endl;
        cout << "������ ����� (2)" << endl;
        cout << "��������� � ������� ���� (0)" << endl;
        cout << "��� �����: ";
        while (!(cin >> extr_enter) || (cin.peek() != '\n') || (extr_enter != round(extr_enter)) || (extr_enter > 2) || (extr_enter < 1))
        {
            if (extr_enter == 0) {
                cout << "������� � ������� ����" << endl;
                return;
            }
            cout << "������������ ������, ��������� �������" << endl;
            cout << "������� ����� �������� �������: ";
            cin.sync();
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());
        }
        if (extr_enter == 1) {
            print_free_sim();
        }
        cin.sync();
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());


        while (true) {
            cout << "��������� � ������� ���� (0)" << endl;
            cout << "������� ����� ���-�����, ������� ������ ���������������� �� �������: ";
            cin.sync();
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());
            while ((!getline(cin, ext_number)) || (sim_number_trouble(ext_number)) || (!sim_no_unic(ext_number)) || (!is_sim_free_ext(header, ext_number)))
            {
                if (ext_number == "0") {
                    cout << "������� � ������� ����" << endl;
                    return;
                }
                if (!sim_no_unic(ext_number)) {
                    cout << "����� ���-����� ���, ����� �������� ������ �� �����, ��� ��� ������ � ����" << endl;
                    cout << "������� ����� ���-�����: ";
                    continue;
                }
                if (!is_sim_free_ext(header, ext_number))
                {
                    cout << "�� ����� ���-�����, ������� ��� ������, ������� ���������" << endl;
                    continue;
                }
                cout << "������������ ������, ��������� �������" << endl;
                cout << "������� ����� ���-�����: ";
                cin.sync();
                cin.clear();
                cin.ignore(cin.rdbuf()->in_avail());
            }
            cin.sync();
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());
            break;
        }
        cout << "��������� � ������� ���� (0)" << endl;
        cout << "������� ���� ����������� ������: ";
        while ((!getline(cin, ext_date)) || (date_trouble(ext_date))||(registr_date_trouble(ext_date, ext_pass, ext_number)) )
        {
            if (ext_date == "0") {
                cout << "������� � ������� ����" << endl;
                return;
            }
            cout << "������������ ������, ��������� �������" << endl;
            cout << "������� ���� ����������� ������: ";
            cin.sync();
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());
        }
        cin.sync();
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());

        insertik_main_data(header, ext_pass, ext_number, ext_date, ext_date_out);
        //�������� ������� ��� ����� � ������� � ��������� ������
        made_sim_nofree(ext_number);
        cout << "������ ������� ������� ���-�����" << endl;
        return;
    }

    if (extr_enter == 2) {
        cin.sync();
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        cout << endl;
        cout << "�� ���������� � ���� ��������." << endl;
        cout << "��������� � ������� ���� (0)" << endl;
        cout << "������� ����� �������� �������: ";
        cin.sync();
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        //�������� �������� �� �� ��� ������ ������ ����
        while ((!getline(cin, ext_pass)) || (passport_trouble(ext_pass)))
        {
            if (ext_pass == "0") {
                cout << "������� � ������� ����" << endl;
                return;
            }
            cout << "������������ ������, ��������� �������" << endl;
            cout << "������� ����� �������� �������: ";
            cin.sync();
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());
        }
        cin.sync();
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        if (!find_client_is(header, ext_pass)) {
            cout << "������ ��� ����������, �� � ���� ��� ���-����, ��������� �������" << endl;
            return;
        }
        cout << "��������� � ������� ���� (0)" << endl;
        cout << "������� ����� ���-�����: ";
        while ((!getline(cin, ext_number)) || (sim_number_trouble(ext_number)))
        {
            if (ext_number == "0") {
                cout << "������� � ������� ����" << endl;
                return;
            }
            cout << "������������ ������, ��������� �������" << endl;
            cout << "������� ����� ���-�����: ";
            cin.sync();
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());
        }
        if(!client_has_sim(header, ext_number, ext_pass)) {
            cout << "����� �������� ������ �� ���������� � �������, ������ ������� � �� ����" << endl;
            return;
        }
        //�������� �������� �� �� ��� � ����� ������� ���� ��� �����
        cout << "��������� � ������� ���� (0)" << endl;
        cout << "������� ���� ��������: ";
        while ((!getline(cin, ext_date_out_2)) || (date_trouble(ext_date_out_2)) /* || last_trouble(ext_date_out_2, ext_number)*/)
        {
            if (ext_date_out_2 == "0") {
                cout << "������� � ������� ����" << endl;
                return;
            }
            cout << "������������ ������, ��������� �������" << endl;
            cout << "������� ���� ��������: ";
            cin.sync();
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());
        }
        cin.sync();
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());

        del_main_data(header, ext_number);
        //coutik_main_data(header);
        cout << "����� ������� �������" << endl;
        made_sim_free(ext_number);
        return;
    }
}




int last_trouble(string last, string number)
{
    string first = returnik_main_data_first(header, number);
    int day, month, year;
    int day1, month1, year1;
    string d = last.substr(0,2), m = last.substr(3, 2), y = last.substr(6, 4);
    string d1 = first.substr(0, 2), m1 = first.substr(3, 2), y1 = first.substr(6, 4);
    try
    {
        day = stoi(d);
        month = stoi(m);
        year = stoi(y);
        day1 = stoi(d1);
        month1 = stoi(m1);
        year1 = stoi(y1);
    }
    catch (const std::exception&)
    {
        return 1;
    }
    if (calendar_trouble(day, month, year)) return 1;

    if (year > year1) return 1;
    if ((year == year1) && (month < month1)) return 1;
    if ((year == year1) && (month == month1) && (day<day1)) return 1;

    return 0;
}

int registr_date_trouble(string s, string pass, string num)
{
    try
    {
        if ((year_of_date_return(s) < sim_year_return(num)) ||
            (year_of_date_return(s) < client_year_return(pass)))
        {
            return 1;
        }
    }
    catch (const std::exception&)
    {
        return 1;
    }
    return 0;
}

int year_of_date_return(string s) {
    string s1 = s.substr(0, 2);
    string s2 = s.substr(3, 2);
    string s3 = s.substr(6);
    int year = stoi(s3);
    return year;
}