#include <iostream>
#include "Inventory.h"

using namespace std;

int main()
{
    Inventory inventory;

    // Program açılırken kayıtlı verileri yükle
    inventory.loadFromFile();

    int choice;

    do
    {
        cout << "\n--- MENU ---\n";
        cout << "1 - Esya Ekle\n";
        cout << "2 - Envanteri Goster\n";
        cout << "3 - Esya Sil\n";
        cout << "4 - Esya Kullan\n";
        cout << "5 - Esya Ara\n";
        cout << "0 - Cikis\n";

        cout << "Seciminiz: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            inventory.addItem();
            break;

        case 2:
            inventory.showItems();
            break;

        case 3:
            inventory.removeItem();
            break;

        case 4:
            inventory.useItem();
            break;

        case 5:
            inventory.findItem();
            break;

        case 0:
            cout << "Program kapatiliyor...\n";
            break;

        default:
            cout << "Gecersiz secim!\n";
            break;
        }

    } while (choice != 0);

    // Program kapanırken kaydet
    inventory.saveToFile();

    return 0;
}