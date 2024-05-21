#include <iostream>
#include "Pochta.h"
#include <random>
using namespace PostOfficeControl;
using namespace std;

int PostOffice::getCoordinateX() {
    return coordinateX;
}
int PostOffice::getIndex() {
    return index;
}
int PostOffice::getCoordinateY() {
    return coordinateY;
}
string PostOffice::getNameOffice() {
    return name;
}
void PostOffice::setIndex(int Index) {
    index = Index;
}
void PostOffice::setCoordinateX(int X) {
    coordinateX = X;
}
void PostOffice::setCoordinateY(int Y) {
    coordinateY = Y;
}
void PostOffice::setNameOffice(string Name) {
    name = Name;
}

std::istream& operator>>(std::istream& in, PostOffice& office) {
    int x;
    int y;
    std::cout << "����� ���������(��� ��������): ";
    in >> office.name;
    std::cout << "���������� x: " << std::endl;
    x = inputInteger();
    office.coordinateX = x;
    std::cout << "���������� y: " << std::endl;
    y = inputInteger();
    office.coordinateY = y;
    std::random_device rd; // �������� ��������� ��������� �������� �� �������
    std::mt19937 gen(rd()); // ���������� ���������� �������� ��� ������������� ����������
    // ������� ������������� ��������� ����� � ������ ���������
    std::uniform_int_distribution<int> distribution(100000, 999999); // ���������� ����� �� 0 �� ������������� �������� long long
    // ���������� ��������� �����
    int randomNumber = distribution(gen);

    office.index = randomNumber;
    return in;
}

std::ostream& operator<<(std::ostream& out, const PostOffice& office) {
    std::cout << "������: " << office.index << std::endl;
    std::cout << "��������: " << office.name << std::endl;
    std::cout << "���������� x: " << office.coordinateX << std::endl;
    std::cout << "���������� y: " << office.coordinateY << "\n" << std::endl;
    return out;
}