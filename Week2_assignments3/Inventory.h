#pragma once
#include<iostream>
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
	void Resize(); //기존에 들어있던 아이템들을 새 공간으로 모두 이사시킨 뒤, 낡은 메모리는 해제합니다. 
	// 아이템을 넣으려는데 인벤토리가 꽉 찼다면? 프로그램을 멈추지 말고 Resize를 호출하여 기존 용량의 2배로 공간을 늘린 후 아이템을 추가합니다.
	bool compareItemsByPrice(const T& a, const T& b);
	//배열의 시작 주소(pItems_), 끝 지점(pItems_ + size_), 그리고 위에서 만든 비교 함수를 전달하여 가격순(오름차순)으로 정렬합니다.
	
	


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
}
