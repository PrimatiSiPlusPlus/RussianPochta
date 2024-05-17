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
    cout << "��� �����������: ";
    in >> parcel.senderName;
    cout << "������� �����������: ";
    in >> parcel.senderSurname;
    cout << "��� ����������: ";
    in >> parcel.recipientName;
    cout << "������� ����������: ";
    in >> parcel.recipientSurname;
    cout << "������: " << endl;
    //��� ����� ������ �� �������� �������...
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
    out << "����-�����: " << parcel.trackNumber << std::endl;
    out << "�����������: " << parcel.senderName << " " << parcel.senderSurname << std::endl;
    out << "����������: " << parcel.recipientName << " " << parcel.recipientSurname << std::endl;
    out << "���������� �� ���������: " << parcel.from << std::endl;
    out << "����� ��������: " << parcel.where << std::endl;
    out << "���: " << parcel.weight << " ���������" << std::endl;
    out << "������: " << (parcel.state ? "� ����" : "����������") << std::endl;
    out << "����� ��������: " << buffer1 << endl;
    out << "����� ��������: " << buffer2 << "\n" << endl;
    return out;
}