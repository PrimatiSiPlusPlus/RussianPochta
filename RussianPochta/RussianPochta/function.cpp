#include <iostream>
#include <string>
#include "Pochta.h"
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
using namespace PostOfficeControl;

int PostOfficeControl::inputInteger() {
    std::string input;
    int number;
    while (true) {
        cin >> input;

        std::istringstream iss(input);
        if (iss >> number && iss.eof()) {
            // Преобразование успешно, выходим из цикла
            break;
        }
        else {
            std::cout << "Ошибка! Пожалуйста, введите корректное число." << std::endl;
        }
    }

    return number;
}

void PostOfficeControl::saveParcel(vector<Parcel> arr, const int& n) {
    ofstream file("fileParcel.txt");
    if (!file.is_open()) {
        std::cout << "Error: could not open fileParcel.txt for saving" << std::endl;
        return;
    }
    file << n << std::endl;
    for (int i = 0; i < n; ++i) {
        file << arr[i].getTrackNumber() <<" "<< arr[i].getSenderName() <<
            " " << arr[i].getSenderSurname() << " " << arr[i].getRecipientName() <<
            " " << arr[i].getRecipientSurname() << " " << arr[i].getFrom() << " " << arr[i].getWhere() <<
            " " << arr[i].getWeight() << " " << arr[i].getState() << " " << arr[i].getSentTime() << " " << arr[i].getReceiveTime() << std::endl;
    }
    file.close();
};

vector<Parcel> PostOfficeControl::readParcel() {
    int countParcel;
    string senderName;
    string senderSurname;
    string recipientName;
    string recipientSurname;
    string trackNumber;
    int from;
    int where;
    int weight;
    bool state;
    time_t sentTime;
    time_t receiveTime;
    ifstream file("fileParcel.txt");
    if (!file.is_open()) {
        cout << "Error: could not open fileParcel.txt for loading" << endl;
        return {};
    }
    file >> countParcel;
    vector<Parcel> arrayParcel(countParcel);
    for (int i = 0; i < countParcel; ++i) {
        file >> trackNumber >> senderName>> senderSurname >> recipientName >> recipientSurname >> from >> where >> weight >> state >> sentTime >> receiveTime;
        arrayParcel[i].setTrackNumber(trackNumber);
        arrayParcel[i].setRecipientName(recipientName);
        arrayParcel[i].setRecipientSurname(recipientSurname);
        arrayParcel[i].setSenderName(senderName);
        arrayParcel[i].setSenderSurname(senderSurname);
        arrayParcel[i].setFrom(from);
        arrayParcel[i].setWhere(where);
        arrayParcel[i].setWeight(weight);
        arrayParcel[i].setState(state);
        arrayParcel[i].setSentTime(sentTime);
        arrayParcel[i].setReceiveTime(receiveTime);
    }
    file.close();
    return arrayParcel;
}

int PostOfficeControl::getCountParcel() {
    int n = 0;
    ifstream file("fileParcel.txt");
    if (!file.is_open()) {
        std::cout << "Error: could not open file.txt for loading" << std::endl;
        return n;
    }
    file >> n;
    file.close();
    return n;
}

void PostOfficeControl::findParcel() {
    vector<Parcel> parcel = readParcel();
    string track;
    int countFound = 0;
    cout << "Введите трек-номер посылки: ";
    cin >> track;
    cout << "\n";
    for (int i = 0; i < getCountParcel(); i++) {
        if (!(parcel[i].getTrackNumber()).compare(track)) {
            cout << parcel[i];
            countFound++;
            break;
        }
    }
    if (countFound == 0)
        cout << "Нет посылки с этим трек-номером" << endl;

}

void PostOfficeControl::deliveryParcel() {
    string deliveryParcel;
    int countFound = 0;
    int number;
    vector<Parcel> parcel = readParcel();
    cout << "Введите трек-номер посылки: ";
    cout << "\n";
    cin >> deliveryParcel;
    for (int i = 0; i < getCountParcel(); i++) {
        if (!(parcel[i].getTrackNumber()).compare(deliveryParcel) && (parcel[i].getState() == 0)){
            cout << "Получена посылка: " << parcel[i];
            number = i;
            countFound++;
            break;
        }
        else if (!(parcel[i].getTrackNumber()).compare(deliveryParcel) && (parcel[i].getState() == 1)) {
            countFound--;
        }
    }
    if (countFound == 0)
        cout << "Нет посылки с этим трек-номером" << endl;
    else if (countFound == -1) {
        cout << "Посылка с этим трек-номером в пути" << endl;
    }
    else {
        parcel.erase(parcel.begin() + number);
        saveParcel(parcel, getCountParcel() - 1);
    }
}

time_t PostOfficeControl::timeLocation(PostOffice& sender, PostOffice& reciever) {

    double distance = sqrt(pow(sender.getCoordinateX() - reciever.getCoordinateX(), 2) +
        pow(sender.getCoordinateY() - reciever.getCoordinateY(), 2));

    double speed = 60.0; 
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

void PostOfficeControl::createPostOffice(const int n) {
    vector<PostOffice> arrayPostOffice = readPostOffice();
    int countPost = getCountPostOffice();
    vector<PostOffice> arrayPostOfficeNew(n);
    for (int i = 0; i < n; i++) {
        cin >> arrayPostOfficeNew[i];
    }

    // Совмещает два ветора в один ,старый из файла и новый созданный
    arrayPostOffice.insert(arrayPostOffice.end(), arrayPostOfficeNew.begin(), arrayPostOfficeNew.end());
    savePostOffice(arrayPostOffice, n + countPost);// сохраняем все в файл
}

void PostOfficeControl::removePostOffice() {
    int deleteOffice;
    vector<PostOffice> postOffice = readPostOffice();
    for (int i = 0; i < getCountPostOffice(); i++) {
        cout << i + 1 << ". " << postOffice[i];
    }
    cout << "Какое отделение почты вы хотите удалить? Введите номер отделения: " << endl;
    deleteOffice = inputInteger();
    postOffice.erase(postOffice.begin() + deleteOffice - 1);
    savePostOffice(postOffice, getCountPostOffice() - 1);
}

void PostOfficeControl::editPostOffice() {
    int numberForEdit;
    string newNamePostOffice;
    vector<PostOffice> office = readPostOffice();
    for (int i = 0; i < getCountPostOffice(); i++) {
        cout << i + 1 << ". " << office[i];
    }
    cout << "Имя у какого отделения почты вы хотите изменить? Введите номер отделения: ";
    while (true) {
        numberForEdit = inputInteger();
        if (numberForEdit > 0 && numberForEdit <= getCountPostOffice())
            break;
    }
    cout << "Введите новое имя:";
    cin >> newNamePostOffice;
    office[numberForEdit - 1].setNameOffice(newNamePostOffice);
    savePostOffice(office, getCountPostOffice());
}

void PostOfficeControl::savePostOffice(vector<PostOffice> arr, const int& n) {
    ofstream file("filePostOffice.txt");
    if (!file.is_open()) {
        cout << "Error: could not open file.txt for saving" << endl;
        return;
    }
    file << n << endl;
    for (int i = 0; i < n; ++i) {
        file << arr[i].getIndex() << " " << arr[i].getNameOffice() << " " << arr[i].getCoordinateX() << " " << arr[i].getCoordinateY() << std::endl;
    }
    file.close();
};

vector<PostOffice> PostOfficeControl::readPostOffice() {
    int countPostOffice;
    int index;
    string name;
    int x;
    int y;
    std::ifstream file("filePostOffice.txt");
    if (!file.is_open()) {
        std::cout << "Error: could not open file.txt for loading" << std::endl;
        return {};
    }
    file >> countPostOffice;
    vector<PostOffice> arrayPostOffice(countPostOffice);
    for (int i = 0; i < countPostOffice; ++i) {
        file >> index >> name >> x >> y;
        arrayPostOffice[i].setIndex(index);
        arrayPostOffice[i].setNameOffice(name);
        arrayPostOffice[i].setCoordinateX(x);
        arrayPostOffice[i].setCoordinateY(y);
    }
    file.close();
    return arrayPostOffice;
}

int PostOfficeControl::getCountPostOffice() {
    int n = 0;
    std::ifstream file("filePostOffice.txt");
    if (!file.is_open()) {
        std::cout << "Error: could not open file.txt for loading" << std::endl;
        return n;
    }
    file >> n;
    file.close();
    return n;
}