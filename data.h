#include "lib.h"
#define cls system("cls") //������� �������
#define milis(x) sleep_for(milliseconds(x)) //�������� � ������������
#define again goto _again; //������� � ������
#define cin_fail cin.clear(); cin.ignore(numeric_limits<std::streamsize>::max(), '\n') //������� �����

// ����� ��� ������������� ������
class Player {
public:
    string name; // ��� ������
    int gold; // ������ ������
    int army; // ����� ������
    int territory; // ���������� ������

    // ����������� ������
    Player(string);

    //���������� �� �������
    void show();

    

    //������� ����� �� ������
    void buyArmy(int);

    //������� ����� �� ������
    void sellArmy(int);

    //��������� ������� ������
    void attack(Player&);
};

// ������� ��� ������ ���� ��������
void showMenu();
//������ ��� ��������� ����������� �������
int correct_count(int&);

//�������� �� ������������ ������
int correct_choice(int&);

//�������� �� ������������ �����
string correct_name(string&);

bool rules(int&, int&);

//������ �������
void player_list(vector<Player>&, int&);