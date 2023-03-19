#include "Client.h"
#include "Extradition.h"
extern drevo* obj;
extern node* head;
extern main_data_list* header;
int gen = 0;

void insertik(node*& head, string number, string place, string date, string name, int birthday_year, string adress)
{
    if (head == NULL) {
        node* n = new node(number, place, date, name, birthday_year, adress);
        n->next = head;
        if (head != NULL) {
            head->prev = n;
        }
        head = n;
        return;
    }
    node* n = new node(number, place, date, name, birthday_year, adress);
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}
int getsizik(node* head)
{
    int q = 0;
    node* temp = head;
    if (temp == NULL) return 0;
    while (temp != NULL) {
        temp = temp->next;
        q++;
    }
    return q;
}
int* returnik(node* head)
{
    //int x = getsizik(head);
    //int* mas = new int[x];
    //int i = 0;
    //node* temp = head;
    //if (temp == NULL) return 0;
    //while (temp != NULL) {
    //    mas[i] = temp->data;
    //    temp = temp->next;
    //    i++;
    //}
    //return mas;
    return 0;
}//�� ��������
void deletik(node*& head)
{
    node* temp = head;
    while (temp->next)
    {
        temp = temp->next;
        head = temp->next;
    }
    delete temp;
}
void coutik(node* head) {
    node* temp = head;
    if (temp == NULL) return;
    while (temp != NULL) {
        cout << temp->data.number<< endl;
        cout << temp->data.place <<", " << temp->data.date << endl;
        cout << temp->data.name << endl;
        cout << temp->data.birthday_year << endl;
        cout << temp->data.adress_city << endl<<endl;
        temp = temp->next;
    }
    return;
}



int height(struct drevo*& elem) {
    if (elem) return elem->height;
    return 0;
}

int bfactor(struct drevo*& elem) {
    return height(elem->right) - height(elem->left);
}

void fixheight(struct drevo*& elem) {
    if (height(elem->left) > height(elem->right)) elem->height = height(elem->left) + 1;
    else elem->height = height(elem->right) + 1;
}

drevo* righting(struct drevo*& elem) {
    drevo* holder = elem->left;
    elem->left = holder->right;
    holder->right = elem;
    fixheight(elem);
    fixheight(holder);
    return holder;
}

drevo* lefting(struct drevo*& elem) {
    drevo* holder = elem->right;
    elem->right = holder->left;
    holder->left = elem;
    fixheight(elem);
    fixheight(holder);
    return holder;
}

drevo* balance(drevo* p)
{
    fixheight(p);
    if (bfactor(p) == 2)
    {
        if (bfactor(p->right) < 0)
            p->right = righting(p->right);
        return lefting(p);
    }
    if (bfactor(p) == -2)
    {
        if (bfactor(p->left) > 0)
            p->left = lefting(p->left);
        return righting(p);
    }
    return p;
}

drevo* add(drevo*& Root, string num, string plc, string dat, string nam, int bir, string cit) {
    drevo* cur = Root;
    if (cur == NULL) {
        drevo* p = new drevo;
        p->right = NULL;
        p->left = NULL;
        p->client.number = num;
        p->client.place = plc;
        p->client.date = dat;
        p->client.name = nam;
        p->client.birthday_year = bir;
        p->client.adress_city = cit;
        p->height = 1;
        return p;
    }
    if (cur->client.number == num) {
        cout << "������������ ��� ���������������, ���������� ����� �� ��������" << endl;
        return cur;
    }
    if (num < cur->client.number) {
        cur->left = add(cur->left, num, plc, dat, nam, bir, cit);
    }
    else {
        cur->right = add(cur->right, num, plc, dat, nam, bir, cit);
    }
    return balance(cur);
}

drevo* find_min(drevo*& Root) {
    if (!(Root->left)) return Root;
    find_min(Root->left);
}

drevo* rem_min(drevo*& Root) {
    if (!(Root->left)) return Root->right;
    Root->left = rem_min(Root->left);
    return balance(Root);
}

drevo* del(struct drevo*& Root, string value) {
     if (value < Root->client.number) Root->left = del(Root->left, value);
    else if (value > Root->client.number) Root->right = del(Root->right, value);
    else {
        drevo* L = Root->left;
        drevo* R = Root->right;
        delete Root;
        if (!R) return L;
        drevo* min = find_min(R);
        min->right = rem_min(R);
        min->left = L;
        return balance(min);
    }
    return balance(Root);
}

int no_unic_number(drevo* Root, string num) {
    if (!(Root)) {
        return 0;
    }
    while (Root) {
        if (Root->client.number == num) {
            return 1;
        }
        if (num > Root->client.number) {
            Root = Root->right;
        }
        else {
            Root = Root->left;
        }
    }
    return 0;
}

void treeprint(drevo*& tree) {
    if (tree != NULL) {
        cout << "���: " << tree->client.name << endl;
        cout << "����� ��������: " << tree->client.number << endl;
        cout << "����� � ���� ������: " << tree->client.place << ", " << tree->client.date << endl;
        cout << "��� ��������: " << tree->client.birthday_year << endl;
        cout << "����� �����������: " << tree->client.adress_city << endl << endl;
        treeprint(tree->left);
        treeprint(tree->right);
    }
}

string find_client_year(struct drevo* Root, string num) {
    if (!(Root)) {
        cout << "������ ������" << endl; return " ";
    }
    while (Root) {
        if (Root->client.number == num) {
            return Root->client.date;
        }
        if (num > Root->client.number) {
            Root = Root->right;
        }
        else {
            Root = Root->left;
        }
    }
}

void find_name(drevo* tree, string nam)
{
    if (tree != NULL) {
        find_name(tree->left, nam);
        if (nam.length() <= tree->client.name.length()) {
            for (int i = 0; i < tree->client.name.length(); i++)
            {
                string s = tree->client.name.substr(i, nam.length());

                if (s == nam)
                {
                    insertik(head, tree->client.number, tree->client.place, tree->client.date, tree->client.name,
                        tree->client.birthday_year, tree->client.adress_city);
                    break;
                }
            }

        }
        find_name(tree->right, nam);
    }
}

void find_adress(drevo* tree, string nam)
{
    if (tree != NULL) {
        find_adress(tree->left, nam);
        if (nam.length() <= tree->client.adress_city.length()) {
            for (int i = 0; i < tree->client.adress_city.length(); i++)
            {
                string s = tree->client.adress_city.substr(i, nam.length());

                if (s == nam)
                {
                    insertik(head, tree->client.number, tree->client.place, tree->client.date, tree->client.name,
                        tree->client.birthday_year, tree->client.adress_city);
                    break;
                }
            }

        }
        find_adress(tree->right, nam);
    }
}

void find_number(drevo* tree, string nam)
{
    if (tree != NULL) {

        if (tree->client.number == nam) {
            cout << "������ ������:" << endl << endl;
            cout << "���: " << tree->client.name << endl;
            cout << "����� ��������: " << tree->client.number << endl;
            cout << "����� � ���� ������: " << tree->client.place << ", " << tree->client.date << endl;
            cout << "��� ��������: " << tree->client.birthday_year << endl;
            cout << "������ �����������: " << tree->client.adress_city << endl;
            gen++;
            find_cout_sim_inf(header, tree->client.number);
        }
        find_number(tree->left, nam);
        find_number(tree->right, nam);
    }
    else if(!no_unic_number(obj, nam))
    {   
        cout << "������ �� ������" << endl;
        gen++;
        return;
    }
}


void ClientChoise()
{
    setlocale(0, "rus");
    drevo cust;
    int enter;
    string value;
    string pass_num;
    string pass_place;
    string pass_date;
    string pass_surname;
    string pass_name;
    string pass_patronymic;
    int pass_year;
    string pass_adress_city;
    string pass_adress_street;
    string pass_adress_house;
    string pass_adress_flat;
        cout << endl;
        while (true)
        {
            cout << "����������� ������ ������� (1)" << endl;
            cout << "������ ������� � ������������ (2)" << endl;
            cout << "�������� ���� �������� (3)" << endl;
            cout << "����� ������� (4)" << endl;
            cout << "��������� � ������� ���� (0)" << endl;
            cout << "��� ����: ";
            while (!(cin >> enter) || (cin.peek() != '\n') || (enter != round(enter)) || (enter < 0) || (enter > 4))
            {
                cin.clear();
                while (cin.get() != '\n');
                cout << "������������ ����" << endl;
                cout << " �������� ��� �������: ";
            }
            break;
        }
        cout << endl;
        cin.sync();
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        if (enter == 1) {
            cout << "��������� � ������� ���� (0)" << endl;
            cout << "������� ����� �������� �������: ";
            while ((!getline(cin, pass_num)) || (passport_trouble(pass_num)) || (no_unic_number(obj, pass_num)))
            {
                if (pass_num == "0") {
                    cout<< "������� � ������� ����" << endl;
                    return;
                }
                if (no_unic_number(obj, pass_num)) {
                    cout << "������ � ����� ������� �������� ��� ����" << endl;
                    cout << "��������� �������: " << endl;
                    cout << "������� ����� ��������: ";
                    continue;
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

            client_register(pass_num);
            cout << " ������� � ������� ����" << endl;
            return;
        }

        if (enter == 2) {

            if (!(obj)) {
                cout << "������ �������� ������, ������� ������" << endl;
                cout << "������� � ������� ����" << endl;
                return;
            }
            cout << "��������� � ������� ���� (0)" << endl;
            cout << "������� ����� �������� ������������, �������� ������ ����� � ������������: ";
            while ((!getline(cin, pass_num)) || (passport_trouble(pass_num))||(!no_unic_number(obj, pass_num)))
            {
                if (pass_num == "0") {
                    cout << "������� � ������� ����" << endl;
                    return;
                }
                if (!no_unic_number(obj, pass_num)) {
                    cout<<"������ ������� ���, �������� ����������"<<endl;
                    return;
                }
                cout << "������������ ������, ��������� �������" << endl;
                cout << "������� ����� �������� �������: ";
                cin.sync();
                cin.clear();
                cin.ignore(cin.rdbuf()->in_avail());
            }
            obj = del(obj, pass_num);
            cout << "������ �����" << endl<< endl;
            cout << " ������� � ������� ����" << endl;
            return;
        }

        if (enter == 3) {
            if (!(obj)) {
                cout << "������ �������� ������, �������� ������" << endl;
                cout << "������� � ������� ����" << endl;
                return;
            }
            cout << " ������ ��������:" << endl << endl;
            treeprint(obj);
            cout << endl << endl;
            cout << "������� � ������� ����" << endl;
            return;
        }

        if (enter == 4) {
            int choise;
            cin.sync();
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());

            if (!(obj)) {
                cout << "������ �������� ������, ������ ������" << endl;
                cout << "������� � ������� ����" << endl;
                return;
            }


            cout << "����� �� ��� ��� ��� ����� (1)" << endl;
            cout << "����� �� ������ ��� ��� ����� (2)" << endl;
            cout << "����� �� ������ �������� (3)" << endl;
            cout << "��������� � ������� ���� (0)" << endl;
            cout << " �������� ��� �������: ";
            while (!(cin >> choise) || (cin.peek() != '\n') || (choise != round(choise)) || (choise < 1) || (choise > 3))
            {
                if (choise == 0) return;
                cin.clear();
                while (cin.get() != '\n');
                cout << "������������ ����" << endl;
                cout << " �������� ��� �������: ";
                cin.sync();
                cin.clear();
                cin.ignore(cin.rdbuf()->in_avail());
            }
            cin.sync();
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());

            if (choise == 1) {
                cout << "��������� � ������� ���� (0)" << endl;
                cout << "������� ��� ��� ��� ����� ��� �������, �������� ������ �����: ";
                cin.sync();
                cin.clear();
                cin.ignore(cin.rdbuf()->in_avail());
                getline(cin, value);
                if (value == "0") {
                    cout << "������� � ������� ����" << endl;
                    return;
                }
                value = to_up(value);
                find_name(obj, value);

                if (getsizik(head) == 0) cout << "�� ������� ����� �� ����� ������" << endl;
                else
                {
                    cout << "��������� ������ �������� �� ����� ������" << endl;
                    coutik(head);
                    deletik(head);
                }
                return;
            }

            if (choise == 2)
            {
                cout << "��������� � ������� ���� (0)" << endl;
                cout << "������� ����� ��� ��� ����� ��� �������, �������� ������ �����: ";
                cin.sync();
                cin.clear();
                cin.ignore(cin.rdbuf()->in_avail());
                getline(cin, value);
                if (value == "0") {
                    cout << "������� � ������� ����" << endl;
                    return;
                }
                value = to_up(value);
                find_adress(obj, value);
                if (getsizik(head) == 0) cout << "�� ������� ����� �� ����� ������" << endl;
                else
                {
                    cout << "��������� ������ �������� �� ����� ������" << endl;
                    coutik(head);
                    deletik(head);
                }
                return;
            }

            if (choise == 3) {
                cin.sync();
                cin.clear();
                cin.ignore(cin.rdbuf()->in_avail());
                cout << "��������� � ������� ���� (0)" << endl;
                cout << "������� ����� �������� �������, �������� ������ �����: ";
                while ((!getline(cin, value)) || (passport_trouble(value)))
                {
                    cout << "������������ ������, ��������� �������" << endl;
                    cout << "������� ����� �������� �������: ";
                    cin.sync();
                    cin.clear();
                    cin.ignore(cin.rdbuf()->in_avail());
                }
                gen = 0;
                find_number(obj, value);
                return;
            }
        }

        if (enter == 0) {
            cout << " ������� � ������� ����" << endl;
            return;
        }
}


void client_register(string pass_num) {

    string pass_place;
    string pass_date;
    string pass_surname;
    string pass_name;
    string pass_patronymic;
    int pass_year;
    string pass_adress_city;
    string pass_adress_street;
    string pass_adress_house;
    string pass_adress_flat;

    cin.sync();
    cin.clear();
    cin.ignore(cin.rdbuf()->in_avail());


    cout << "������� ����� ������ �������� �������: ";
    while ((!getline(cin, pass_place)) || (have_no_letter(pass_place)))
    {
        cout << "������������ ������, ��������� �������" << endl;
        cout << "������� ����� ������ �������� �������: ";
        cin.sync();
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
    }
    pass_place = to_up(pass_place);
    cin.sync();
    cin.clear();
    cin.ignore(cin.rdbuf()->in_avail());

    /////

    cout << "������� ���� ������ �������� �������: ";
    while ((!getline(cin, pass_date)) || (date_trouble(pass_date)))
    {
        cout << "������������ ������, ��������� �������" << endl;
        cout << "������� ���� ������ �������� �������: ";
        cin.sync();
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
    }
    cin.sync();
    cin.clear();
    cin.ignore(cin.rdbuf()->in_avail());
    /////

    cout << "������� ������� �������: ";
    while ((!getline(cin, pass_surname)) || (have_no_letter(pass_surname)))
    {
        cout << "������������ ������, ��������� �������" << endl;
        cout << "������� ������� �������: ";
        cin.sync();
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
    }
    pass_surname = to_up(pass_surname);
    cin.sync();
    cin.clear();
    cin.ignore(cin.rdbuf()->in_avail());
    /////

    cout << "������� ��� �������: ";
    while ((!getline(cin, pass_name)) || (have_no_letter(pass_name)))
    {
        cout << "������������ ������, ��������� �������" << endl;
        cout << "������� ��� �������: ";
        cin.sync();
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
    }
    pass_name = to_up(pass_name);
    cin.sync();
    cin.clear();
    cin.ignore(cin.rdbuf()->in_avail());
    /////

    cout << "������� �������� �������: ";
    while ((!getline(cin, pass_patronymic)) || (have_no_letter(pass_patronymic)))
    {
        cout << "������������ ������, ��������� �������" << endl;
        cout << "������� �������� �������: ";
        cin.sync();
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
    }
    pass_patronymic = to_up(pass_patronymic);
    cin.sync();
    cin.clear();
    cin.ignore(cin.rdbuf()->in_avail());

    /////

    cout << "������� ��� �������� �������: ";
    while (!(cin >> pass_year) || (cin.peek() != '\n') || (client_date_trouble(pass_year, pass_date)))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "������������ ���" << endl;
        cout << "������� ��� �������� ������� ";
    }
    cin.sync();
    cin.clear();
    cin.ignore(cin.rdbuf()->in_avail());
    /////

    cout << "������� ����� �������: ";
    while ((!getline(cin, pass_adress_city)) || (have_no_letter(pass_adress_city)))
    {
        cout << "������������ ������, ��������� �������" << endl;
        cout << "������� ����� �������: ";
        cin.sync();
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
    }
    pass_adress_city = to_up(pass_adress_city);
    cin.sync();
    cin.clear();
    cin.ignore(cin.rdbuf()->in_avail());
    /////

    cout << "������� �������� �����/���������/�������� �������: ";
    while ((!getline(cin, pass_adress_street)) || (have_symbols(pass_adress_street)))
    {
        cout << "������������ ������, ��������� �������" << endl;
        cout << "������� �������� �����/���������/�������� �������: ";
        cin.sync();
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
    }
    pass_adress_street = to_up(pass_adress_street);
    cin.sync();
    cin.clear();
    cin.ignore(cin.rdbuf()->in_avail());
    /////

    cout << "������� ����� ���� �������: ";
    while ((!getline(cin, pass_adress_house)) || (have_no_numbers(pass_adress_house)))
    {
        cout << "������������ ������, ��������� �������" << endl;
        cout << "������� ����� ���� �������: ";
        cin.sync();
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
    }
    cin.sync();
    cin.clear();
    cin.ignore(cin.rdbuf()->in_avail());
    /////

    cout << "������� ����� �������� ������� (������� 0, ���� �������� ���): ";
    while ((!getline(cin, pass_adress_flat)) || (have_no_numbers(pass_adress_flat)))
    {
        if (pass_adress_flat == "0") break;
        cout << "������������ ������, ��������� �������" << endl;
        cout << "������� ����� �������� �������: ";
        cin.sync();
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
    }
    cin.sync();
    cin.clear();
    cin.ignore(cin.rdbuf()->in_avail());

    pass_name = pass_surname + " " + pass_name + " " + pass_patronymic;
    if (pass_adress_flat == "0")  pass_adress_city = pass_adress_city + ", " + pass_adress_street + ", " + pass_adress_house;
    else pass_adress_city = pass_adress_city + ", " + pass_adress_street + ", " + pass_adress_house + ", " + pass_adress_flat;

    obj = add(obj, pass_num, pass_place, pass_date, pass_name, pass_year, pass_adress_city);

    cout << "������ ������� ���������������" << endl;
}

int client_year_return(string s) {
    string years = find_client_year(obj, s);
    int year = 0;
    try
    {
        year = stoi(years);
    }
    catch (const std::exception&)
    {
        return 10000;
    }
    return year;
}

bool passport_trouble(string s) {
    if (s.length() != 11) return 1; //1234-123456
    string s1 = { s[0], s[1], s[2],  s[3]};
    char s2 = s[4];
    string s3 = {s[5], s[6],s[7], s[8], s[9], s[10]};
    string numbers = "1234567890";
    int inc = 0;
    for (int i = 0; i < 4; i++)
    {
        inc = 0;
        for (int j = 0; j < 10; j++)
        {
            if (s[i] != numbers[j]) inc++;
        }
        if (inc == 10) return 1;
    }

    if (s2 != '-') return 1;

    for (int i = 5; i < 11; i++)
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

bool date_trouble(string s)
{
    if(s.length()!=10) return 1;
    string s1 = s.substr(0, 2);
    string s2 = s.substr(3, 2);
    string s3 = s.substr(6);
    int day = 0;
    int month = 0;
    int year = 0;
    try
    {
        day = stoi(s1);
        month = stoi(s2);
        year = stoi(s3);
    }
    catch (const std::exception&)
    {
        return 1;
    }
    if (calendar_trouble(day, month, year)) return 1;
    if (((s[2]) != '.')||(s[5]!='.')) return 1;

    return 0;
}

bool calendar_trouble(int day, int month, int year) {

    if ((day > 31) || (day < 1)) return 1;
    if ((month < 0) || (month > 12)) return 1;
    if ((year < 1800) || (year > 2023)) return 1;

    if ((month == 2) && (year%4 ==0) && (day>29)) return 1; //������� 29
    if ((month == 2) && (year % 4 != 0) && (day > 28)) return 1; //������� 

    if ((month == 4) || (month == 6) || (month == 9) || (month == 11)) {
        if (day > 30) return 1;
    }
    return 0;
}

bool have_no_letter(string s) {
    int inc = 0;
    for (int i = 0; i < s.length(); i++) {
        char x = s[i];
        if ((x >= '�' && x <= '�') || (x >= '�' && x <= '�')) inc++; ;
    }
    if (inc != s.length()) return 1;
    return 0;
}

bool have_symbols(string s) {
    for (int i = 0; i < s.length(); i++) {
        char x = s[i];
        if ((x >= ' ' && x <= ',') || (x >= ':' && x <= '@') || (x >= '[' && x <= '`') || (x>= '{' && x<= '~')) return 1;
    }
    return 0;
}

bool have_no_numbers(string s) {

    if ((s.length() == 1) && (s[0] == '0')) return 1;
    for (int i = 0; i < s.length(); i++) {
        char x = s[i];
        if ((x < '0') || (x > '9' )) return 1;
    }
    return 0;
}

bool client_date_trouble(int year, string s)
{
    if ((year != round(year)) || (year < 1800) || (year > 2023)) return 1;
    int year_pass = 0;
    string s3 = s.substr(6);
    try
    {
        year_pass = stoi(s3);
    }
    catch (const std::exception&)
    {
        return 1;
    }
    if (year > year_pass) return 1;
    return 0;
}

string to_up(string s) {
    for (size_t i = 0; i < s.length(); ++i) {
        s[i] = toupper(s[i]);
        if (s[i] == '�') s[i] = '�';
    }
    return s;
}