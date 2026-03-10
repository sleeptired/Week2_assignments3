#pragma once
#include<iostream>
template <typename T>
class Inventory
{
public:
	Inventory(int capacity = 10);
	~Inventory();
	void AddItem(const T& item);
	void RemoveLastItem();
	int GetSize() const;
	int GetCapacity() const;

	void PrintAllItems() const;

	//void PrintInfo() const;
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
	}
	else
	{
		std::cout << "인벤토리가 꽉 찼습니다!" << std::endl;
	}
}

template<typename T>
inline void Inventory<T>::RemoveLastItem()
{
	if (this->size_ != 0)
	{
		this->size_--;
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
