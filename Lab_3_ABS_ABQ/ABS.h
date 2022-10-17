#pragma once
#include <iostream>
#include <deque>
#include <exception>
#include <stdexcept>


//#define scale_factor 2.0f;

using namespace std;


//float scale_factor;
//scale_factor = 2.0;

template <typename T>
class ABS
{
	T* data;

	int size;
	//int maxCapacity;
	int maxCapacity;
	float scale_factor;
	int totalResizes;
public:
	//constructors
	ABS();
	ABS(int pmaxCapacity);


	//copy constructor
	ABS(const ABS& d);

	//copy assignment operator
	ABS& operator=(const ABS& d);



	//void Add(T value);
	//T At(int index);
	T* getData();
	unsigned int getSize();
	//int GetmaxCapacity();
	unsigned int getMaxCapacity();

	//Destructor
	~ABS();

	void push(T data);
	T pop();
	T peek();
	unsigned int getTotalResizes();
};

template<typename T>
inline ABS<T>::ABS()
{
	//Default constructor. Maximum maxCapacity should
	//be set to 1, and current size set to 0;
	data = nullptr;
	size = 0;
	maxCapacity = 2;
	totalResizes = 0;
}

template<typename T>
inline ABS<T>::ABS(int pmaxCapacity)
{
	//Constructor for an ABQ with the specified
	//starting maximum maxCapacity.
	maxCapacity = pmaxCapacity;
	size = 0;
	data = new T[pmaxCapacity];
	scale_factor = 2.0;
}

template<typename T>
inline ABS<T>::ABS(const ABS& d)
{
	//copy Constructor
	data = nullptr;
	size = d.size;
	maxCapacity = d.data;
	//1. allocate space for some data
	data = new int[d.maxCapacity];
	//2. copy existing data into new space
	for (int i = 0; i < size; i++)
		data[i] = d.data[i];
}

template<typename T>
ABS<T>& ABS<T>::operator=(const ABS& d)
{
	// assignment operator
	//1. copy non-dynamic variables
	size = d.size;
	maxCapacity = d.maxCapacity;
	//4. delete old data
	delete[] data;
	//2. allocate space for some data
	data = new int[d.maxCapacity];
	//1.50. copy existing data into new space
	for (int i = 0; i < size; i++)
		data[i] = d.data[i];
	//5. reassign old data pointer to new data
	return *this;
}

template<typename T>
inline T* ABS<T>::getData()
{
	return data;
}

template<typename T>
inline unsigned int ABS<T>::getSize()
{
	return size;
}

template<typename T>
inline unsigned int ABS<T>::getMaxCapacity()
{
	return maxCapacity;
}

template<typename T>
inline ABS<T>::~ABS()
{
	delete[] data;
}

template<typename T>
void ABS<T>::push(T _data)
{
	size++;
	if (data == nullptr || maxCapacity == 0)
	{
		data = new T[1];
		data[0] = _data;
		maxCapacity = 2;
		size = 1;

	}
	else if (size - 1 < maxCapacity)
	{

		T* newArray = new T[maxCapacity];
		for (int i = 0; i < size; i++)
		{
			newArray[i] = data[i];
			//cout << data[i];
		}
		newArray[size - 1] = _data;


		delete[] data;
		data = newArray;

	}
	else if (size - 1 == maxCapacity)
	{
		totalResizes++;
		T* newArray = new T[maxCapacity * 1.50];
		for (int i = 0; i < size; i++)
		{
			newArray[i] = data[i];
			//cout << data[i];
		}
		newArray[size - 1] = _data;

		maxCapacity = maxCapacity * 1.50;
		delete[] data;
		data = newArray;

	}
}

template<typename T>
T ABS<T>::pop()
{
	if (data == nullptr)
	{
		throw runtime_error("An error has occurred");
	}
	size--;
	double percent_full;
	//cout << "This is testing value of size at front " << data[0] << " and at back " << data[size-1] << endl;
	//for (int i = 0; i < size; i++)
	//{
	//	cout << "this is testing array values " << data[i] << endl;
	//}
	percent_full = (double)size / (double)maxCapacity;
	T frontItem = data[size];
	if (data == nullptr)
	{
		throw runtime_error("An error has occurred");
	}
	else if (percent_full >= (1.00/1.50))
	{
		T* newArray = new T[maxCapacity];
		for (int j = 0; j < size; j++)
		{
			newArray[j] = data[j];
		}
		delete[] data;
		data = newArray;
	}
	else if (percent_full < (1.00/1.50))
	{
		totalResizes++;
		int new_size;
		new_size = maxCapacity / 1.50;
		if (maxCapacity % 2 == 0)
		{
			T* newArray = new T[new_size];
			for (int i = 0; i < size; i++)
			{
				newArray[i] = data[i];

			}
			maxCapacity = maxCapacity / 1.50;
			delete[] data;
			data = newArray;
		}
		else if (maxCapacity % 2 != 0)
		{
			T* newArray = new T[new_size + 1];
			for (int i = 0; i < size; i++)
			{
				newArray[i] = data[i];
			}
			maxCapacity = (maxCapacity / 1.50);
			delete[] data;
			data = newArray;
		}
	}

	return frontItem;
}

template<typename T>
T ABS<T>::peek()
{
	T return_this;
	if (data == nullptr || size == 0)
	{
		throw runtime_error("An error has occurred");
	}
	else if (data != nullptr && size != 0)
	{
		return_this = data[size - 1];
	}

	return return_this;
}

template<typename T>
unsigned int ABS<T>::getTotalResizes()
{
	return totalResizes;
}
