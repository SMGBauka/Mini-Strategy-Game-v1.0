#include "lib.h"
#include "data.h"
using namespace std;


int main()
{
    setlocale(0, "");
    srand(unsigned(time(0))); // инициализация генератора случайных чисел
    vector<Player> players; // вектор для хранения игроков
    int n; // количество игроков
    string name; // имя игрока
    int choice; // выбор действия
    int amount; // количество войск для покупки или продажи
    int target; // номер цели для атаки

    cout << "Добро пожаловать в мою стратегическую игру который был создан с помощю С++!\n"
         << "Пожалуйста введите количество игроков (от 2 до 4): ";
    correct_count(n);

    for (int i = 0; i < n; i++) { // цикл для создания игроков
        cout << "Введите имя игрока " << i + 1 << ": ";
        correct_name(name);
        players.push_back(Player(name)); // добавление игрока в вектор
    }

    bool gameOver = true; // флаг для завершения игры
    int turn{ 0 }; // номер хода
    
    cls; //Очистка консоля

    while (gameOver) 
    { // Начало игры
        turn++; // увеличение номера хода
        cout << "\nХод " << turn << ".\n";
        sleep_for(seconds(3));
        for (int i = 0; i < n; i++) { // цикл для хода каждого игрока
            _again:
            cls;
            cout << "\nХодит игрок " << players[i].name << ".\n";
            showMenu(); // вывод меню действий
            cout << "Ваш выбор:";
            correct_choice(choice);
            if(!rules(turn, choice))
            {
                cout << "Правило было нарушено.Выберите заново";
                milis(600);
                again;
            }
            


            cls; //Очистка консоля

            switch (choice) { // обработка выбора действия
            case 1: // покупка войск
                cout << "Сколько войск вы хотите купить? ";
                cin >> amount;
                players[i].buyArmy(amount); // вызов метода покупки войск
                break;
            case 2: // продажа войск
                cout << "Сколько войск вы хотите продать? ";
                cin >> amount;
                players[i].sellArmy(amount); // вызов метода продажи войск
                break;
            case 3: // атака другого игрока
                cout << "Кого вы хотите атаковать? Введите номер игрока: ";
                cin >> target;
                milis(200);
                while (cin.fail() || target < 1 || target > n || target == i + 1) { // проверка на корректность ввода
                    cout << "Неверный номер игрока. Попробуйте еще раз: ";
                    cin_fail;
                    cin >> target;
                }
                players[i].attack(players[target - 1]); // вызов метода атаки другого игрока
                break;
            case 4: // показ информации об игроках
                player_list(players, n);
                cout << "Нажмите кнопку что бы продолжить:";
                cin.ignore();
                again;
            case 5: // завершение хода
                cout << "Ход завершен.";
                sleep_for(seconds(1));
                break;
            }
            cls;
        }

        // Проверка условий окончания игры
        int alive = 0; // количество живых игроков
        int winner = -1; // номер победителя
        for (int i = 0; i < n; i++) { // цикл для подсчета живых игроков и определения победителя
            if (players[i].army > 0) { // если у игрока есть армия, то он живой
                alive++; // увеличение количества живых игроков
                winner = i; // запоминание номера победителя
            }
        }
        if (alive == 1) { // если остался один живой игрок, то он победил
            cls; //Очистка консоля
            cout << "\nИгра окончена. \nПобедил игрок " << players[winner].name << ". Поздравляем!\n";
            gameOver = true; // установка флага завершения игры
            break;
        }
        else if (alive == 0) { // если не осталось живых игроков, то ничья
            cls; //Очистка консоля
            cout << "\nИгра окончена. Никто не победил. Это ничья.\n";
            gameOver = true; // установка флага завершения игры
            break;
        }
    }
}
