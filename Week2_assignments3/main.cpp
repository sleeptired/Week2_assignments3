#include<iostream>
#include"Inventory.h"

int main() 
{
	Inventory<int> test(50);
	test.AddItem(10);
	test.AddItem(20);
	test.AddItem(30);
	test.PrintAllItems();
	test.RemoveLastItem();
	test.PrintAllItems();
}