#pragma once
#include <vector>
#include"Item.h"
using namespace std;

class Inventory {
public:
	vector<Item>items;
	void addItem();
	void showItems();
	void removeItem();
	void saveToFile();
	void loadFromFile();
	void useItem();
	const int MAX_ITEMS = 20;
	void findItem();
};
