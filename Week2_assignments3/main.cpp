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

	//Inventory<Item> test2(3);
	//std::cout << "test2의 Size:" << test2.GetSize() << " Capacity: " << test2.GetCapacity() << std::endl;
	//test2.AddItem(Item("Add", 10));
	//test2.AddItem(Item("ndd", 30));
	//test2.AddItem(Item("ddd", 20));
	//std::cout << "test2의 Size:" << test2.GetSize() << " Capacity: " << test2.GetCapacity() << std::endl;
	//test2.AddItem(Item("zdd", 5));
	//test2.AddItem(Item("edd", 1));
	//test2.RemoveLastItem();
	//std::cout << "test2의 Size:" << test2.GetSize() << " Capacity: " << test2.GetCapacity() << std::endl;
	//test2.PrintAllItems();
	//
	//Inventory<Item> test3(test2);
	//test3.PrintAllItems();
	//
	//Inventory<Item> test4;
	//test4.AddItem(Item("bdd", 10));
	//test4.AddItem(Item("zdd", 30));
	//test4.Assign(test2);
	//test4.PrintAllItems();
	//
	//test4.SortItems();
	//test4.PrintAllItems();

	Inventory<Item> Default;
	std::cout << "Default의 Size:" << Default.GetSize() << " Capacity: " << Default.GetCapacity() << std::endl;
	std::cout << "=============================================" << std::endl;
	std::cout << "Add함수 구현 부분" << std::endl;
	Default.AddItem(Item("Apple", 50));
	Default.AddItem(Item("banna", 20));
	std::cout << "=============================================" << std::endl;
	std::cout << "RemoveLastItem 구현 부분" << std::endl;
	Default.RemoveLastItem();
	std::cout << "=============================================" << std::endl;
	std::cout << "꽉 찼을 때 Resize 구현 부분" << std::endl;
	Default.AddItem(Item("Orange", 42));
	Default.AddItem(Item("Grape", 90));
	Default.AddItem(Item("Strawberry", 70));
	Default.AddItem(Item("Watermelon", 30));
	Default.AddItem(Item("Pineapple", 15));
	Default.AddItem(Item("Mango", 25));
	Default.AddItem(Item("Peach", 55));
	Default.AddItem(Item("Cherry", 65));
	Default.AddItem(Item("Lemon", 32));
	Default.AddItem(Item("Kiwi", 92));
	std::cout << "Default의 Size:" << Default.GetSize() << " Capacity: " << Default.GetCapacity() << std::endl;
	std::cout << "=============================================" << std::endl;
	std::cout << "PrintAllItems 함수" << std::endl;
	Default.PrintAllItems();
	std::cout << "=============================================" << std::endl;
	std::cout << "Default 인벤토리를 Copy 인벤토리 ";
	Inventory<Item> Copy(Default);
	std::cout << "=============================================" << std::endl;
	std::cout << "Assign ";
	Inventory<Item> Assign;
	Assign.Assign(Default);
	std::cout << "Assign 인벤토리 PrintAllItems 함수" << std::endl;
	Assign.PrintAllItems();
	std::cout << "=============================================" << std::endl;
	std::cout << "SortItems 함수 구현" << std::endl;
	std::cout << "Assign 인벤토리 ";
	Assign.SortItems();
	Assign.PrintAllItems();
}