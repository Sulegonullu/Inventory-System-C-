#include <iostream>
#include <fstream>
#include "Inventory.h"

using namespace std;

// Eþya ekleme
void Inventory::addItem()
{
    if (items.size() >= MAX_ITEMS)
    {
        cout << "Envanter dolu!\n";
        return;
    }

    Item newItem;

    cout << "Esya adi: ";
    cin >> newItem.name;

    cout << "Esya turu: ";
    cin >> newItem.type;

    cout << "Nadirlik (Common/Rare/Epic/Legendary): ";
    cin >> newItem.rarity;

    cout << "Miktar: ";
    cin >> newItem.quantity;

    items.push_back(newItem);

    cout << "Esya eklendi!\n";
}

// Envanteri göster
void Inventory::showItems()
{
    cout << "\n--- ENVANTER ---\n";

    for (Item item : items)
    {
        cout << item.name
            << " [" << item.type << "] "
            << "[" << item.rarity << "] "
            << "x" << item.quantity
            << endl;
    }
}

// Eþya silme
void Inventory::removeItem()
{
    string itemName;

    cout << "Silinecek esya adi: ";
    cin >> itemName;

    for (int i = 0; i < items.size(); i++)
    {
        if (items[i].name == itemName)
        {
            items.erase(items.begin() + i);

            cout << "Esya silindi!\n";
            return;
        }
    }

    cout << "Esya bulunamadi!\n";
}

// Dosyaya kaydet
void Inventory::saveToFile()
{
    ofstream file("inventory.txt");

    for (Item item : items)
    {
        file << item.name << " "
            << item.type << " "
            << item.rarity << " "
            << item.quantity
            << endl;
    }

    file.close();

    cout << "Kaydedildi!\n";
}

// Dosyadan yükle
void Inventory::loadFromFile()
{
    items.clear();
    ifstream file("inventory.txt");

    Item item;

    while (file >> item.name
        >> item.type
        >> item.rarity
        >> item.quantity)
    {
        items.push_back(item);
    }

    file.close();
}

// Eþya kullan
void Inventory::useItem()
{
    string itemName;

    cout << "Kullanilacak esya: ";
    cin >> itemName;

    for (int i = 0; i < items.size(); i++)
    {
        if (items[i].name == itemName)
        {
            items[i].quantity--;

            cout << "Esya kullanildi!\n";

            if (items[i].quantity <= 0)
            {
                items.erase(items.begin() + i);
            }

            return;
        }
    }

    cout << "Esya bulunamadi!\n";
}

// Eþya ara
void Inventory::findItem()
{
    string itemName;

    cout << "Aranacak esya: ";
    cin >> itemName;

    for (Item item : items)
    {
        if (item.name == itemName)
        {
            cout << "\nBulundu!\n";

            cout << item.name
                << " [" << item.type << "] "
                << "[" << item.rarity << "] "
                << "x" << item.quantity
                << endl;

            return;
        }
    }

    cout << "Esya bulunamadi!\n";
}