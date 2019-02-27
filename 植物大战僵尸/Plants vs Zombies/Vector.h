#pragma once
#include <algorithm>
#include<cstdio>

template <typename Object>
class Vector
{
public:
	static const int SPARE_CAPACITY = 16; 

	explicit Vector(int initSize = 0) :theSize{ initSize }, theCapacity{ initSize + SPARE_CAPACITY }
	{
		objects = new Object[theCapacity];
	}
	~Vector()
	{
		delete[]objects;
	}
	
	void reserve(int newCapacity)
	{
		if (newCapacity < theSize)
			return;
		Object *newArray = new Object[newCapacity];
		for (int k = 0; k < theSize; ++k)
			newArray[k] = std::move(objects[k]);

		theCapacity = newCapacity;
		std::swap(objects, newArray);
		delete[] newArray;
	}

	Object & at(int index)
	{
		if (index<0 || index>theSize){}
//			printf("out of range!\n");
		else
		{
			return objects[index];
		}
	}
	const Object & at(int index)const
	{
		if (index<0 || index>theSize){}
//			printf("out of range!\n");
		else
		{
			return objects[index];
		}
	}

	void push_back(const Object &x)
	{
		if (theSize == theCapacity-1)
			reserve(2 * theCapacity + 1);
		objects[theSize++] = x;
	}
	void push_back(Object && x)
	{
		if (theSize == theCapacity-1)
			reserve(2 * theCapacity + 1);
		objects[theSize++] = std::move(x);
	}

	int size() const
	{
		return theSize;
	}

	bool empty() const
	{
		return size() == 0;
	}

	void clear()
	{
		delete[] objects;
		theSize = 0;
		theCapacity = 0;
	}

	const Object & pop()
	{
		return objects[theSize--];
	}
private:
	int theSize;
	int theCapacity;
	Object *objects;
};