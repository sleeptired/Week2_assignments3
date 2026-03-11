#include<iostream>
#include"Inventory.h"
#include"Item.h"


int main() 
{
	//Inventory<int> test(10);
	//Inventory<int> test5(5);
	//test.AddItem(10);
	//test.AddItem(20);
	//test.AddItem(30);
	//test.PrintAllItems();
	//test.RemoveLastItem();
	//test.PrintAllItems();
	//test.SortItems();
	//test.PrintAllItems();

	Inventory<Item> test2(3);
	test2.AddItem(Item("Add", 10));
	test2.AddItem(Item("ndd", 30));
	test2.AddItem(Item("ddd", 20));
	test2.AddItem(Item("zdd", 5));
	test2.PrintAllItems();
	
	Inventory<Item> test3(test2);
	test3.PrintAllItems();
	
	Inventory<Item> test4;
	test4.AddItem(Item("bdd", 10));
	test4.AddItem(Item("zdd", 30));
	test4.Assign(test2);
	test4.PrintAllItems();
	
	test4.SortItems();
	test4.PrintAllItems();
}