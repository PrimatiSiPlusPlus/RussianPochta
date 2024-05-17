#include <iostream>
#include <ctime>
#include "Pochta.h"
using namespace PostOfficeControl;
using namespace std;

std::istream& operator>>(std::istream& in, Parcel& parcel) {
    int answer;
    parcel.state = false;
    parcel.sentTime = time(nullptr);
    parcel.recieveTime = time(nullptr);
    parcel.trackNumber = to_string((getCountParcel() + 1));
    cout << "Имя отправителя: ";
    in >> parcel.senderName;
    cout << "Фамилия отправителя: ";
    in >> parcel.senderSurname;
    cout << "Имя получателя: ";
    in >> parcel.recipientName;
    cout << "Фамилия получателя: ";
    in >> parcel.recipientSurname;
    cout << "Откуда: " << endl;
    //тут потом смотря по ситуации добавлю...
}

std::ostream& operator<<(std::ostream& out, const Parcel& parcel) {
    std::tm timeinfo1;
    std::tm timeinfo2;
    localtime_s(&timeinfo1, &parcel.sentTime);
    localtime_s(&timeinfo2, &parcel.recieveTime);
    char buffer1[80];
    char buffer2[80];
    std::strftime(buffer1, 80, "%Y-%m-%d %H:%M:%S", &timeinfo1);
    std::strftime(buffer2, 80, "%Y-%m-%d %H:%M:%S", &timeinfo2);
    out << "Трек-номер: " << parcel.trackNumber << std::endl;
    out << "Отправитель: " << parcel.senderName << " " << parcel.senderSurname << std::endl;
    out << "Получатель: " << parcel.recipientName << " " << parcel.recipientSurname << std::endl;
    out << "Отправлено из отделения: " << parcel.from << std::endl;
    out << "Адрес доставки: " << parcel.where << std::endl;
    out << "Вес: " << parcel.weight << " килограмм" << std::endl;
    out << "Статус: " << (parcel.state ? "В пути" : "Доставлено") << std::endl;
    out << "Время отправки: " << buffer1 << endl;
    out << "Время прибытия: " << buffer2 << "\n" << endl;
    return out;
}