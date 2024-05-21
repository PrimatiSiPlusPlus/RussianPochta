#include <iostream>
#include <ctime>
#include "Pochta.h"
using namespace PostOfficeControl;
using namespace std;

string Parcel::getSenderName() {
    return senderName;
}
string Parcel::getSenderSurname() {
    return senderSurname;
}
string Parcel::getRecipientName() {
    return recipientName;
}
string Parcel::getRecipientSurname() {
    return recipientSurname;
}
string Parcel::getTrackNumber() {
    return trackNumber;
}
int Parcel::getFrom() {
    return from;
}
int Parcel::getWhere() {
    return where;
}
int Parcel::getWeight() {
    return weight;
}
void Parcel::setSenderName(string SenderName) {
    senderName = SenderName;
}
void Parcel::setSenderSurname(string SenderSurname) {
    senderSurname = SenderSurname;
}
void Parcel::setRecipientName(string RecipientName) {
    recipientName = RecipientName;
}
void Parcel::setRecipientSurname(string RecipientSurname) {
    recipientSurname = RecipientSurname;
}
void Parcel::setTrackNumber(string TrackNumber) {
    trackNumber = TrackNumber;
}
void Parcel::setFrom(int From) {
    from = From;
}
void Parcel::setWhere(int Where) {
    where = Where;
}
void Parcel::setWeight(int Weight) {
    weight = Weight;
}
time_t Parcel::getSentTime() {
    return sentTime;
}
void Parcel::setSentTime(time_t time) {
    sentTime = time;
}
time_t Parcel::getReceiveTime()  {
    return recieveTime;
}
void Parcel::setReceiveTime(time_t time) {
    recieveTime = time;
}
void Parcel::setState(bool State) {
    state = State;
}
bool Parcel::getState() {
    return state;
}

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
    vector<PostOffice> postOffice = readPostOffice();
    for (int i = 0; i < getCountPostOffice(); i++) {
        cout << i + 1 << ". " << postOffice[i];
    }
    answer = inputInteger();
    parcel.from = postOffice[answer - 1].getIndex();
    cout << "Куда: " << endl;
    for (int i = 0; i < getCountPostOffice(); i++) {
        cout << i + 1 << ". " << postOffice[i];
    }
    int answer2 = answer;
    answer = inputInteger();
    while (answer == answer2) {
        cout << "Вы уже тута. Попробуйте заново" << endl;
        answer = inputInteger();
        cin.clear();
    }
    parcel.where = postOffice[answer - 1].getIndex();
    cout << "Вес посылки(в килограммах): ";
    in >> parcel.weight;
    return in;
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