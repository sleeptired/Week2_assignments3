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

std::ostream& operator<<(std::ostream& os, const Item& item)
{
	//os << "[이름: " << item.name_ << ", 가격: " << item.price_ << "G]";
	item.PrintInfo();
	return os;
}
