#include "lib.h"
#define cls system("cls") //Очистка консоля
#define milis(x) sleep_for(milliseconds(x)) //Ожидание в милисекундах
#define again goto _again; //Возврат в начало
#define cin_fail cin.clear(); cin.ignore(numeric_limits<std::streamsize>::max(), '\n') //Очистка ввода

// Класс для представления игрока
class Player {
public:
    string name; // имя игрока
    int gold; // золото игрока
    int army; // армия игрока
    int territory; // территория игрока

    // Конструктор класса
    Player(string);

    //Информации об игроках
    void show();

    

    //Покупка войск за золото
    void buyArmy(int);

    //Продажа войск за золото
    void sellArmy(int);

    //Атаковать другого игрока
    void attack(Player&);
};

// Функция для вывода меню действий
void showMenu();
//Фунция для написания колличество игроков
int correct_count(int&);

//Проверка на корректности выбора
int correct_choice(int&);

//Проверка на корректность имени
string correct_name(string&);

bool rules(int&, int&);

//Список игроков
void player_list(vector<Player>&, int&);