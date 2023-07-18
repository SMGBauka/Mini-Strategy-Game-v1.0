#include "data.h"
Player::Player(string n):name(n)
{
        gold = 100;
        army = 10; 
        territory = 10; 
}

void Player::show()
{
    cout << "����� " << name << ":\n";
    cout << "������: " << gold << "\n";
    cout << "�����: " << army << "\n";
    cout << "����������: " << territory << "\n";
}


void Player::buyArmy(int n) 
{
    if (n > 0 && n * 10 <= gold) { // �������� �� ������������� ������ � ��������������� �����
        gold -= n * 10; // ���������� ������ �� ��������� �����
        army += n; // ���������� ����� �� ���������� ��������� �����
        cout << name << " ����� " << n << " ����� �� " << n * 10 << " ������.\n";
    }
    else {
        cout << name << " �� ����� ������ " << n << " �����.\n";
    }
}

void Player::sellArmy(int n) 
{
    if (n > 0 && n <= army) { // �������� �� ������������� ����� � ��������������� �����
        gold += n * 5; // ���������� ������ �� �������� ��������� �����
        army -= n; // ���������� ����� �� ���������� ��������� �����
        cout << name << " ������ " << n << " ����� �� " << n * 5 << " ������.\n";
    }
    else {
        cout << name << " �� ����� ������� " << n << " �����.\n";
    }
}

void Player::attack(Player& other) 
{
    if (army > 0 && other.army > 0) { // �������� �� ������� ����� � ����� �������
        cout << name << " ������� " << other.name << ".\n";
        int r = rand() % (army + other.army); // ��������� ����� �� 0 �� ����� �����
        if (r < army) { // ���� ����� ������ ����� ����������, �� �� ���������
            cout << name << " ���������.\n";
            territory += other.territory / 2; // ���������� ���������� ���������� �� �������� ���������� ������������
            other.territory /= 2; // ���������� ���������� ������������ �����
            gold += other.gold / 2; // ���������� ������ ���������� �� �������� ������ ������������
            other.gold /= 2; // ���������� ������ ������������ �����
            army -= other.army / 2; // ���������� ����� ���������� �� �������� ����� ������������
            other.army = 0; // ��������� ����� ������������
        }
        else { // ���� ����� ������ ��� ����� ����� ����������, �� �� �����������
            cout << other.name << " ���������.\n";
            other.territory += territory / 2; // ���������� ���������� ������������� �� �������� ���������� ����������
            territory /= 2; // ���������� ���������� ���������� �����
            other.gold += gold / 2; // ���������� ������ ������������� �� �������� ������ ����������
            gold /= 2; // ���������� ������ ���������� �����
            other.army -= army / 2; // ���������� ����� ������������� �� �������� ����� ����������
            army = 0; // ��������� ����� ����������
        }
    }
    else {
        cout << "����� ����������.\n";
    }
}

void showMenu()
{
    cout << "�������� ��������:\n"
        << "1. ������ ������\n"
        << "2. ������� ������\n"
        << "3. ��������� ������� ������\n"
        << "4. �������� ���������� �� �������\n"
        << "5. ��������� ���\n";
}

int correct_count(int& n)
{
    while (true) {
        cin >> n;
        // ��������� ��������� cin � ��� ������, ��������� �������������
        if (cin.fail() || n < 2 || n > 4) {
            cout << "������ �����. ����������, ������� ����� ����� ������ (�� 2 �� 4):";
            // ���������� ���� ������ � ������� ����� �����
            cin_fail;
        }
        else {
            // ���������, ��� ����� ����� ������ ����� ��� ������ ��������
            char c;
            if (cin.get(c) && c == '\n') {
                break; // ���� ���������, ������� �� �����
            }
            else {
                cout << "������ �����. ����������, ������� ������ ����� ����� (�� 2 �� 4):";
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }
    return n;
}

int correct_choice(int& n)
{
    cin >> n;
    while (true) {
        // ��������� ��������� cin � ��� ������, ��������� �������������
        if (cin.fail() || n < 1 || n > 5) {
            cout << "�������� �����. ���������� ��� ���:";
            // ���������� ���� ������ � ������� ����� �����
            cin_fail;
        }
        else {
            // ���������, ��� ����� ����� ������ ����� ��� ������ ��������
            char c;
            if (cin.get(c) && c == '\n') {
                break; // ���� ���������, ������� �� �����
            }
            else {
                cout << "�������� �����. ���������� ��� ���:";
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }
    return n;
}


string correct_name(string& name)
{
        do {
            getline(cin, name);

            // �������� ��������� � �������� ��������
            name.erase(
                name.begin(),
                find_if(name.begin(),
                name.end(),
                [](unsigned char ch) 
                { return !isspace(ch);}
                ));

            name.erase(find_if(
                name.rbegin(),
                name.rend(),
                [](unsigned char ch) 
                { return !isspace(ch); }
                ).base(), name.end());

        } while (name.empty());
        return name;
}

bool rules(int& turn, int& choice)
{
    bool rule1 = (turn == 1 && choice == 3) ? false : true;
    return (rule1) ? true : false;
}

void player_list(vector<Player>& players, int& n)
{
    for (int j = 0; j < n; j++) { // ���� ��� ������ ���������� ��� ���� �������
        players[j].show(); // ����� ������ ������ ���������� �� ������
        cout << "\n";
    }

}
