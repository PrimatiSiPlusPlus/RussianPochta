#include <iostream>
#include <sstream>
#include <cctype>
#include <vector>
#include <locale>
#include "Pochta.h"

using namespace PostOfficeControl;
using namespace std;

int main() {
    vector<Parcel> parcels;
    vector<PostOffice> offices;
    int number;

    cout << "1. Admin" << endl;
    cout << "2. User" << endl;
    cout << "3. Alla Vladimirovna" << endl;
    cout << "Who are you?" << endl;

    while (true) {
        number = inputInteger();
        if (number <= 0 || number > 3) {
            cout << "Are you trying to find a secret option? Please choose from the given options." << endl;
            continue;
        }
        break;
    }

    if (number == 1) { // Admin
        while (true) {
            checkStatusParcels();
            cout << "/------------------------------\\" << endl;
            cout << "|        Russian Post          |" << endl;
            cout << "|------------------------------|" << endl;
            cout << "| 1. Create a post office      |" << endl;
            cout << "| 2. Delete a post office      |" << endl;
            cout << "| 3. Edit a post office        |" << endl;
            cout << "| 4. Send a parcel             |" << endl;
            cout << "| 5. Display                   |" << endl;
            cout << "| 6. Find a parcel             |" << endl;
            cout << "| 7. Receive a parcel          |" << endl;
            cout << "| 8. Fast forward time         |" << endl;
            cout << "| 9. Parcel status             |" << endl;
            cout << "| 10. Exit                     |" << endl;
            cout << "\\------------------------------/" << endl;
            int choice;
            choice = inputInteger();
            switch (choice) {
            case 1:
                cout << "How many post offices do you want to create: ";
                int n;
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
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please select an option between 1 and 10." << endl;
                break;
            }
        }
    }
    else if (number == 2) { // User
        while (true) {
            checkStatusParcels();
            cout << "/------------------------------\\" << endl;
            cout << "|        Russian Post          |" << endl;
            cout << "|------------------------------|" << endl;
            cout << "| 1. Send a parcel             |" << endl;
            cout << "| 2. Find a parcel             |" << endl;
            cout << "| 3. Receive a parcel          |" << endl;
            cout << "| 4. Parcel status             |" << endl;
            cout << "| 5. Exit                      |" << endl;
            cout << "\\------------------------------/" << endl;
            int choice;
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
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please select an option between 1 and 5." << endl;
                break;
            }
        }
    }
    else if (number == 3) { // Alla Vladimirovna
        checkStatusParcels();
        cout << "Everything is working, you don't need to check, just give an automatic grade :)";
        return 0;
    }

    return 0;
}
