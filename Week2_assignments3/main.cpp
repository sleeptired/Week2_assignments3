#include<iostream>
#include"Inventory.h"
#include"Item.h"

int main() 
{
	Inventory<int> test(50);
	test.AddItem(10);
	test.AddItem(20);
	test.AddItem(30);
	test.PrintAllItems();
	test.RemoveLastItem();
	test.PrintAllItems();

	Inventory<Item> test2;
	test2.AddItem(Item("Add", 10));
	test2.AddItem(Item("ndd", 30));
	test2.PrintAllItems();
}