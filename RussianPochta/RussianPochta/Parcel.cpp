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
    cout << "Èìÿ îòïðàâèòåëÿ: ";
    in >> parcel.senderName;
    cout << "Ôàìèëèÿ îòïðàâèòåëÿ: ";
    in >> parcel.senderSurname;
    cout << "Èìÿ ïîëó÷àòåëÿ: ";
    in >> parcel.recipientName;
    cout << "Ôàìèëèÿ ïîëó÷àòåëÿ: ";
    in >> parcel.recipientSurname;
    cout << "Îòêóäà: " << endl;
    //òóò ïîòîì ñìîòðÿ ïî ñèòóàöèè äîáàâëþ...
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
    out << "Òðåê-íîìåð: " << parcel.trackNumber << std::endl;
    out << "Îòïðàâèòåëü: " << parcel.senderName << " " << parcel.senderSurname << std::endl;
    out << "Ïîëó÷àòåëü: " << parcel.recipientName << " " << parcel.recipientSurname << std::endl;
    out << "Îòïðàâëåíî èç îòäåëåíèÿ: " << parcel.from << std::endl;
    out << "Àäðåñ äîñòàâêè: " << parcel.where << std::endl;
    out << "Âåñ: " << parcel.weight << " êèëîãðàìì" << std::endl;
    out << "Ñòàòóñ: " << (parcel.state ? "Â ïóòè" : "Äîñòàâëåíî") << std::endl;
    out << "Âðåìÿ îòïðàâêè: " << buffer1 << endl;
    out << "Âðåìÿ ïðèáûòèÿ: " << buffer2 << "\n" << endl;
    return out;
}
