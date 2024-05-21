#include <iostream>
#include <sstream>
#include <cctype>
#include "Pochta.h"
using namespace PostOfficeControl;
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    vector<Parcel> parcelss;
    vector<PostOffice> office;
    int number;
    cout << "1. Админ" << endl;
    cout << "2. Пользователь" << endl;
    cout << "3. Алла Владимировна" << endl;
    cout << "Кто вы?" << endl;
    while (true) {
        number = inputInteger();
        if (number <= 0 || number > 3) {
            cout << "Вы хотите найти какой то секретный пункт? Выберите пожалуйста из предложенных" << endl;
            continue;
        }
        break;
    }
    if (number == 1) {
        while (true) {
            checkStatusParcels();
            std::cout << "/------------------------------\\" << std::endl;
            std::cout << "|         Почта России         |" << std::endl;
            std::cout << "|------------------------------|" << std::endl;
            std::cout << "| 1. Создать отделение почты   |" << std::endl;
            std::cout << "| 2. Удалить отделение почты   |" << std::endl;
            std::cout << "| 3. Изменить отделение почты  |" << std::endl;
            std::cout << "| 4. Отправить посылку         |" << std::endl;
            std::cout << "| 5. Вывод                     |" << std::endl;
            std::cout << "| 6. Найти посылку             |" << std::endl;
            std::cout << "| 7. Получить посылку          |" << std::endl;
            std::cout << "| 8. Перемотать время          |" << std::endl;
            std::cout << "| 9. Статус посылок            |" << std::endl;
            std::cout << "| 10. Выйти из программы       |" << std::endl;
            std::cout << "\\------------------------------/" << std::endl;
            int choice;
            std::string input;
            int n;
            choice = inputInteger();
            switch (choice) {
            case 1:
                cout << "Сколько отделений вы хотите создать: ";
                n = inputInteger();
                createPostOffice(n);
                break;
            case 2:
                removePostOffice();
                break;
            case 3:
                editPostOffice();
                break;
            case 4:
                sendParcel();
                break;
            case 5:
                print();
                break;
            case 6:
                findParcel();
                break;
            case 7:
                deliveryParcel();
                break;
            case 8:
                rewindTime();
                break;
            case 9:
                progressTime();
                break;
            case 10:
                cout << "Выход из программы." << endl;
                return 0;
            default:
                cout << "Некорректный выбор. Пожалуйста, выберите действие от 1 до 10." << endl;
                break;
            }
        }
    }
    else if (number == 2) {
        while (true) {
            checkStatusParcels();
            std::cout << "/------------------------------\\" << std::endl;
            std::cout << "|         Почта России         |" << std::endl;
            std::cout << "|------------------------------|" << std::endl;
            std::cout << "| 1. Отправить посылку         |" << std::endl;
            std::cout << "| 2. Найти посылку             |" << std::endl;
            std::cout << "| 3. Получить посылку          |" << std::endl;
            std::cout << "| 4. Статус посылки            |" << std::endl;
            std::cout << "| 5. Выйти из программы        |" << std::endl;
            std::cout << "\\------------------------------/" << std::endl;
            int choice;
            std::string input;
            int n;
            choice = inputInteger();
            switch (choice) {
            case 1:
                sendParcel();
                break;
            case 2:
                findParcel();
                break;
            case 3:
                deliveryParcel();
                break;
            case 4:
                progressTime();
                break;
            case 5:
                cout << "Выход из программы." << endl;
                return 0;
            default:
                cout << "Некорректный выбор. Пожалуйста, выберите действие от 1 до 5." << endl;
                break;
            }
        }
    }
    else if (number == 3) {
        checkStatusParcels();
        cout << "У нас всё работает, можете не проверять, ставьте сразу автомат :)";
        return 0;
    }
    return 0;
}