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
}