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

std::ostream& operator<<(std::ostream& os, const Item& item)
{
	item.PrintInfo();
	return os;
}
