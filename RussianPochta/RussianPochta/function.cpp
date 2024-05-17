#include <iostream>
#include <string>
#include "Pochta.h"
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
using namespace PostOfficeControl;

time_t PostOfficeControl::timeLocation(PostOffice& sender, PostOffice& reciever) {

    double distance = sqrt(pow(sender.getCoordinateX() - reciever.getCoordinateX(), 2) +
        pow(sender.getCoordinateY() - reciever.getCoordinateY(), 2));

    double speed = 60.0; // км/ч
    double hoursInDay = 24.0;

    double travelTime = distance / speed;
    if (travelTime > hoursInDay) {
        travelTime -= hoursInDay;
    }

    time_t currentTime = time(nullptr);
    return currentTime + static_cast<time_t>(travelTime * 3600);
}

void PostOfficeControl::rewindTime() {
    vector<Parcel> parcels = readParcel();

    if (parcels.empty()) {
        cout << "Нет посылок для отслеживания." << endl;
        return;
    }

    int timeToAdd;

    cout << "Введите количество времени для перемотки вперед (в минутах): ";
    timeToAdd = inputInteger();

    // Получаем текущее время
    time_t currentTime = time(nullptr);

    // Перематываем время для каждой посылки
    for (int i = 0; i < parcels.size(); ++i) {
        if ((parcels[i].getReceiveTime() - timeToAdd * 60) <= currentTime) {
            parcels[i].setReceiveTime(currentTime);
            parcels[i].setState(0);
        }
        else {
            parcels[i].setReceiveTime(parcels[i].getReceiveTime() - timeToAdd * 60);
        }
    }
    saveParcel(parcels, getCountParcel());
    cout << "Время успешно перемотано вперед для всех посылок." << endl;
}

void PostOfficeControl::sendParcel() {
    vector<Parcel> parcels = readParcel();
    vector<PostOffice> offices = readPostOffice();

    // Создаем новую посылку
    Parcel newParcel;
    cin >> newParcel;

    int from;
    int where;
    for (int i = 0; i < offices.size(); ++i) {
        if (newParcel.getFrom() == offices[i].getIndex()) {
            from = i;
        }
        else if (newParcel.getWhere() == offices[i].getIndex()) {
            where = i;
        }

    }
    // Рассчитываем время отправления и доставки
    time_t currentTime = time(nullptr);
    newParcel.setSentTime(currentTime);
    newParcel.setReceiveTime(timeLocation(offices[from], offices[where])); // тут хз че с индексами

    // Обновляем информацию о посылке и сохраняем изменения
    newParcel.setState(true); //true - едет, false - не едет
    parcels.push_back(newParcel); // Добавляем новую посылку в вектор
    saveParcel(parcels, getCountParcel() + 1);

    cout << "Посылка отправлена!" << endl;
    cout << "Трек-Номер: " << newParcel.getTrackNumber() << endl;
}

void PostOfficeControl::progressTime() {
    vector<Parcel> parcel = readParcel();
    string trackNumber;
    cout << "Введите трек-номер посылки чтобы узнать статус: ";
    cin >> trackNumber;
    int foundParcel = -1;
    time_t currentTime = time(nullptr);
    for (int i = 0; i < parcel.size(); i++) {
        if (!(parcel[i].getTrackNumber()).compare(trackNumber)) {
            foundParcel = i;
            break;
        }

    }
    if (foundParcel == -1) {
        cout << " Посылка не найдена " << endl;
    }
    else if (currentTime >= parcel[foundParcel].getReceiveTime()) {
        parcel[foundParcel].setState(0);
        cout << "Посылка прибыла" << endl;
    }
    else {
        double curentTimeDouble = currentTime * 1.0;
        double sentTime = parcel[foundParcel].getSentTime() * 1.0;
        double receiveTime = parcel[foundParcel].getReceiveTime() * 1.0;
        cout << "Посылка доставлена на " << (curentTimeDouble - sentTime) / (receiveTime - sentTime) * 100 << "% " << endl;;
    }
}

void PostOfficeControl::checkStatusParcels() {
    vector<Parcel> parcel = readParcel();
    time_t currentTime = time(nullptr);
    for (int i = 0; i < getCountParcel(); i++) {
        if (parcel[i].getReceiveTime() <= currentTime) {
            parcel[i].setState(0);
        }
    }
    saveParcel(parcel, getCountParcel());
}

void PostOfficeControl::print() {
    vector<PostOffice> office = readPostOffice();
    vector <Parcel> parcel = readParcel();
    cout << "Отделения:" << endl;
    for (int i = 0; i < getCountPostOffice(); i++) {
        cout << i + 1 << ". " << office[i];
    }
    if (getCountParcel() != 0) {
        cout << "\n" << "Посылки:" << endl;
    }
    for (int i = 0; i < getCountParcel(); i++) {
        cout << i + 1 << ". " << "\n" << parcel[i];
    }
}