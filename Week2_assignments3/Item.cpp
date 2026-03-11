#include "Item.h"
Item::Item()
{
}
Item::Item(std::string name, int price) : name_(name), price_(price)
{
}
Item::~Item()
{
}
void Item::PrintInfo() const
{
	std::cout << "[이름: " << this->name_ << ", 가격: " << this->price_ << "G]" << std::endl;
}

int Item::GetPrice() const
{
	return this->price_;
}

bool Item::operator<(const Item& other) const
{
	//return this->price_ < other.price_;
	return compareItemsByPrice(*this, other);
}

std::ostream& operator<<(std::ostream& os, const Item& item)
{
	item.PrintInfo();
	return os;
}

bool compareItemsByPrice(const Item& a, const Item& b)
{
	return a.GetPrice() < b.GetPrice();
}
