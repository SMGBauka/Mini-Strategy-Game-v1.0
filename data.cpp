#include "data.h"
Player::Player(string n):name(n)
{
        gold = 100;
        army = 10; 
        territory = 10; 
}

void Player::show()
{
    cout << "Игрок " << name << ":\n";
    cout << "Золото: " << gold << "\n";
    cout << "Армия: " << army << "\n";
    cout << "Территория: " << territory << "\n";
}


void Player::buyArmy(int n) 
{
    if (n > 0 && n * 10 <= gold) { // проверка на достаточность золота и положительность числа
        gold -= n * 10; // уменьшение золота на стоимость войск
        army += n; // увеличение армии на количество купленных войск
        cout << name << " купил " << n << " войск за " << n * 10 << " золота.\n";
    }
    else {
        cout << name << " не может купить " << n << " войск.\n";
    }
}

void Player::sellArmy(int n) 
{
    if (n > 0 && n <= army) { // проверка на достаточность армии и положительность числа
        gold += n * 5; // увеличение золота на половину стоимости войск
        army -= n; // уменьшение армии на количество проданных войск
        cout << name << " продал " << n << " войск за " << n * 5 << " золота.\n";
    }
    else {
        cout << name << " не может продать " << n << " войск.\n";
    }
}

void Player::attack(Player& other) 
{
    if (army > 0 && other.army > 0) { // проверка на наличие армии у обоих игроков
        cout << name << " атакует " << other.name << ".\n";
        int r = rand() % (army + other.army); // случайное число от 0 до суммы армий
        if (r < army) { // если число меньше армии атакующего, то он побеждает
            cout << name << " побеждает.\n";
            territory += other.territory / 2; // увеличение территории атакующего на половину территории проигравшего
            other.territory /= 2; // уменьшение территории проигравшего вдвое
            gold += other.gold / 2; // увеличение золота атакующего на половину золота проигравшего
            other.gold /= 2; // уменьшение золота проигравшего вдвое
            army -= other.army / 2; // уменьшение армии атакующего на половину армии проигравшего
            other.army = 0; // обнуление армии проигравшего
        }
        else { // если число больше или равно армии атакующего, то он проигрывает
            cout << other.name << " побеждает.\n";
            other.territory += territory / 2; // увеличение территории защищающегося на половину территории атакующего
            territory /= 2; // уменьшение территории атакующего вдвое
            other.gold += gold / 2; // увеличение золота защищающегося на половину золота атакующего
            gold /= 2; // уменьшение золота атакующего вдвое
            other.army -= army / 2; // уменьшение армии защищающегося на половину армии атакующего
            army = 0; // обнуление армии атакующего
        }
    }
    else {
        cout << "Атака невозможна.\n";
    }
}

void showMenu()
{
    cout << "Выберите действие:\n"
        << "1. Купить войска\n"
        << "2. Продать войска\n"
        << "3. Атаковать другого игрока\n"
        << "4. Показать информацию об игроках\n"
        << "5. Завершить ход\n";
}

int correct_count(int& n)
{
    while (true) {
        cin >> n;
        // Проверяем состояние cin и тип данных, введенных пользователем
        if (cin.fail() || n < 2 || n > 4) {
            cout << "Ошибка ввода. Пожалуйста, введите целое число заново (от 2 до 4):";
            // Сбрасываем флаг ошибки и очищаем буфер ввода
            cin_fail;
        }
        else {
            // Проверяем, что после ввода целого числа нет других символов
            char c;
            if (cin.get(c) && c == '\n') {
                break; // Ввод корректен, выходим из цикла
            }
            else {
                cout << "Ошибка ввода. Пожалуйста, введите только целое число (от 2 до 4):";
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
        // Проверяем состояние cin и тип данных, введенных пользователем
        if (cin.fail() || n < 1 || n > 5) {
            cout << "Неверный выбор. Попробуйте еще раз:";
            // Сбрасываем флаг ошибки и очищаем буфер ввода
            cin_fail;
        }
        else {
            // Проверяем, что после ввода целого числа нет других символов
            char c;
            if (cin.get(c) && c == '\n') {
                break; // Ввод корректен, выходим из цикла
            }
            else {
                cout << "Неверный выбор. Попробуйте еще раз:";
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

            // Удаление начальных и конечных пробелов
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
    for (int j = 0; j < n; j++) { // цикл для вывода информации обо всех игроках
        players[j].show(); // вызов метода показа информации об игроке
        cout << "\n";
    }

}
