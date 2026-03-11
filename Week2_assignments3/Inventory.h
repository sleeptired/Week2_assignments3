#pragma once
#include<iostream>
#include <algorithm>
class Item;

template <typename T>
class Inventory
{
public:
	Inventory(int capacity = 10);
	Inventory(const Inventory<T>& other);
	~Inventory();
	void AddItem(const T& item);
	void RemoveLastItem();
	int GetSize() const;
	int GetCapacity() const;
	void PrintAllItems() const;

	//도전기능
	void Assign(const Inventory<T>& other);//객체에 다른 객체의 내용을 덮어씁니다.
	void Resize(int newCapacity); //기존에 들어있던 아이템들을 새 공간으로 모두 이사시킨 뒤, 낡은 메모리는 해제합니다. 
	void SortItems();// 가격순(오름차순) 정렬
	
	

private:
	T* pItems_;
	int capacity_;
	int size_;

};


template<typename T>
inline Inventory<T>::Inventory(int capacity) :size_(0)
{
	if (capacity <= 0)
	{
		capacity_ = 1;
	}
	else
	{
		capacity_ = capacity;
	}

	pItems_ = new T[capacity_];
	std::cout << "인벤토리 생성" << std::endl;
}

template<typename T>
inline Inventory<T>::Inventory(const Inventory<T>& other)
{
	capacity_ = other.capacity_;
	size_ = other.size_;
	pItems_ = new T[capacity_];
	for (int i = 0; i < size_; ++i) 
	{
		pItems_[i] = other.pItems_[i];
	}
	std::cout << "인벤토리 복사 완료" << std::endl;
}

template<typename T>
inline Inventory<T>::~Inventory()
{
	delete[] pItems_;
	pItems_ = nullptr;
}

template<typename T>
inline void Inventory<T>::AddItem(const T& item)
{
	if (this->size_ != capacity_)
	{
		this->pItems_[size_] = item;
		this->size_++;
		std::cout << "아이템 추가완료" << std::endl;
	}
	else
	{
		//std::cout << "인벤토리가 꽉 찼습니다!" << std::endl;
		std::cout << "인벤토리가 꽉 차서 " << capacity_ * 2 << "칸으로 확장합니다!" << std::endl;
		this->Resize(this->capacity_ * 2);//capacity_를 2배 늘린거를 resize함수에 넣는다.
		this->pItems_[size_] = item;
		this->size_++;
		std::cout << "아이템 추가완료" << std::endl;
	}
}

template<typename T>
inline void Inventory<T>::RemoveLastItem()
{
	if (this->size_ != 0)
	{
		this->size_--;
		std::cout << "삭제 완료" << std::endl;
	}
	else
	{
		std::cout << "인벤토리가 비어있습니다." << std::endl;
	}
}

template<typename T>
inline int Inventory<T>::GetSize() const
{
	return this->size_;
}

template<typename T>
inline int Inventory<T>::GetCapacity() const
{
	return this->capacity_;
}

template<typename T>
inline void Inventory<T>::PrintAllItems() const
{
	if (size_ != 0)
	{
		for (int i = 0; i < size_; i++)
		{
			std::cout << pItems_[i] << std::endl;
		}
	}
	else
	{
		std::cout << "비어있음" << std::endl;
	}
}

template<typename T>
inline void Inventory<T>::Assign(const Inventory<T>& other)
{
	delete[] this->pItems_;//기존에 가지고 있던 메모리는 delete[]로 먼저 비워준 뒤,

	capacity_ = other.capacity_;
	size_ = other.size_;
	pItems_ = new T[capacity_];
	for (int i = 0; i < size_; ++i) 
	{
		pItems_[i] = other.pItems_[i];
	}
	std::cout << "인벤토리 Assign 완료" << std::endl;
}

template<typename T>
inline void Inventory<T>::Resize(int newCapacity)
{
	T* temp = new T[capacity_];
	for (int i = 0; i < size_; ++i)
	{
		temp[i] = this->pItems_[i];
	}

	delete[] this->pItems_;
	//복사한걸 다 옮기고 삭제

	this->pItems_ = new T[newCapacity];
	this->capacity_ = newCapacity;
	for (int i = 0; i < size_; ++i)
	{
		this->pItems_[i] = temp[i];
	}
	//복사한값들을 이제 새로 할당한 부분에 채워넣기
}

template<typename T>
inline void Inventory<T>::SortItems()
{
	std::sort(pItems_, pItems_ + size_);
	std::cout << "정렬 완료" << std::endl;
}

