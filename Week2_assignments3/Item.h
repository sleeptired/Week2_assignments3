#pragma once
#include<string>
#include<iostream>

class Item
{
public:
	Item();
	Item(std::string name, int price);
	~Item();
	void PrintInfo() const;
	int GetPrice() const;

	friend std::ostream& operator<<(std::ostream& os, const Item& item);
private:
	std::string name_ = "";
	int price_ = 0;
};

//bool compareItemsByPrice(const Item& a, const Item& b) 
//{
//	return a.GetPrice() < b.GetPrice();
//}