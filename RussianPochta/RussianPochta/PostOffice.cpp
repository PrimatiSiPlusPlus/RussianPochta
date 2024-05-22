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
    std::cout << "City of the post office (without spaces): ";
    in >> office.name;
    std::cout << "Coordinate x: ";
    x = inputInteger();
    office.coordinateX = x;
    std::cout << "Coordinate y: ";
    y = inputInteger();
    office.coordinateY = y;

    std::random_device rd; // Obtain a random seed from the system
    std::mt19937 gen(rd()); // Use the seed to initialize the generator
    // Create a distribution for random numbers in the desired range
    std::uniform_int_distribution<int> distribution(100000, 999999); // Generate numbers between 100000 and 999999
    // Generate a random number
    int randomNumber = distribution(gen);
    office.index = randomNumber;
    return in;
}

std::ostream& operator<<(std::ostream& out, const PostOffice& office) {
    out << "Index: " << office.index << std::endl;
    out << "Name: " << office.name << std::endl;
    out << "Coordinate x: " << office.coordinateX << std::endl;
    out << "Coordinate y: " << office.coordinateY << "\n" << std::endl;
    return out;
}
