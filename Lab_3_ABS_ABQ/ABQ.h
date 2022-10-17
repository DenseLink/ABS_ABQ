#pragma once
#include <iostream>
#include <deque>
#include <exception>
#include <stdexcept>

//#define scale_factor 1.50f;

using namespace std;


//float scale_factor;
//scale_factor = 1.50;

template <typename T>
class ABQ
{
	T* data;

	int size;
	//int maxCapacity;
	int maxCapacity;
	float scale_factor;
	int totalResizes;
public:
	//constructors
	ABQ();
	ABQ(int pmaxCapacity);


	//copy constructor
	ABQ(const ABQ& d);

	//copy assignment operator
	ABQ& operator=(const ABQ& d);



	//void Add(T value);
	//T At(int index);
	T* getData();
	unsigned int getSize();
	//int GetmaxCapacity();
	unsigned int getMaxCapacity();

	//Destructor
	~ABQ();

	void enqueue(T data);
	T dequeue();
	T peek();
	unsigned int getTotalResizes();
};

template <typename T>
ABQ<T>::ABQ()
{
	//Default constructor. Maximum maxCapacity should
	//be set to 1, and current size set to 0;
	data = nullptr;
	size = 0;
	maxCapacity = 2;

}

template <typename T>
ABQ<T>::ABQ(int pmaxCapacity)
{
	//Constructor for an ABQ with the specified
	//starting maximum maxCapacity.
	maxCapacity = pmaxCapacity;
	size = 0;
	data = new T[pmaxCapacity];
	scale_factor = 1.50;
	totalResizes = 0;
}

template<typename T>
ABQ<T>::ABQ(const ABQ& d)
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
ABQ<T>& ABQ<T>::operator=(const ABQ& d)
{
	// assignment operator
	//1. copy non-dynamic variables
	size = d.size;
	maxCapacity = d.maxCapacity;
	//4. delete old data
	delete[] data;
	//2. allocate space for some data
	data = new int[d.maxCapacity];
	//3. copy existing data into new space
	for (int i = 0; i < size; i++)
		data[i] = d.data[i];
	//5. reassign old data pointer to new data
	return *this;
}

template <typename T>
ABQ<T>::~ABQ()
{
	delete[] data;
}
template<typename T>
void ABQ<T>::enqueue(T _data)
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
		T* newArray = new T[maxCapacity * 1.5];
		for (int i = 0; i < size; i++)
		{
			newArray[i] = data[i];
			//cout << data[i];
		}
		newArray[size - 1] = _data;

		maxCapacity = maxCapacity * 1.5;
		delete[] data;
		data = newArray;
		totalResizes++;
	}
}
template<typename T>
T ABQ<T>::dequeue()
{
	//Remove the item at front of the queue, resizes if
	//necessary, and return the value removed.
	//	Throws a runtime_error if the queue is empty.
	//1. if queue is empty throw error
	//T frontItem;
	//frontItem = NULL;
	//if (data[0] == NULL)
	//	throw runtime_error("An error has occurred");
	if (data == nullptr)
	{
		throw runtime_error("An error has occurred");

	}
	size--;
	double percent_full;
	percent_full = (double)size / (double)maxCapacity;
	/*cout << "This is testing the percent full " << percent_full << endl;
	cout << "This is testing the scale factor " << scale_factor << endl;*/
	/*for (int i = 0; i < size+1; i++)
	{
		cout << "this is testing array values " << data[i] << endl;
	}*/
	T frontItem = data[0];

	if (data == nullptr)
	{
		throw runtime_error("An error has occurred");

	}

	else if (percent_full >= (1.00/1.5))
	{
		//T value;
		//value = data[0];
		/*cout << "This is testing the data at front of array before function " << value << endl;
		cout << "this is testing the data at the end of the array before function " << data[size] << endl;*/
		//data[j].pop_front(j+1);
	//	T* newArray = data[0];
//		for (int i = 0; i < size; i++)
	//	{
	//		newArray[i] = data[i];
	//	}
		//int new_size;
		//new_size = maxCapacity - 1;
		T* newArray = new T[maxCapacity];
		for (int j = 0; j < size; j++)
		{
			newArray[j] = data[j + 1];
		}
		//if (size == 0 && maxCapacity == 1)
		//{
		delete[] data;
		//}
		data = newArray;

	}
	else if (percent_full < (1.00/1.50))
	{

		int new_size;
		new_size = maxCapacity / 1.5;
		totalResizes++;
		// first if statement
		if (maxCapacity % 2 == 0)
		{
			T* newArray = new T[new_size];
			for (int i = 0; i < size; i++)
			{
				newArray[i] = data[i + 1];

			}
			//newArray[size] = data;
			//size = size / 2;
			maxCapacity = maxCapacity / 1.5;
			//delete[] data;
			//if (size == 0 && maxCapacity == 1)
			//{
			delete[] data;
			//}
			data = newArray;

		}

		else if (maxCapacity % 2 != 0)
		{
			T* newArray = new T[new_size + 1];
			for (int i = 0; i < size; i++)
			{
				newArray[i] = data[i + 1];

			}
			//newArray[size] = data;
			//size = size / 2;
			maxCapacity = (maxCapacity / 1.5);
			//if (size == 0 && maxCapacity == 1)
			//{
			delete[] data;
			//}
			//delete[] data;
			data = newArray;

		}

	}


	//}

	//cout << "This is a test right here for data[0] " << frontItem << endl;
	return frontItem;
}
template<typename T>
T ABQ<T>::peek()
{

	T return_this;
	if (data == nullptr || size == 0)
	{
		throw runtime_error("An error has occurred");
	}
	else if (data != nullptr && size != 0)
	{
		return_this = data[0];
	}

	return return_this;
}

template<typename T>
unsigned int ABQ<T>::getTotalResizes()
{
	return totalResizes;
}



template<typename T>
T* ABQ<T>::getData()
{
	return data;
}

template <typename T>
unsigned int ABQ<T>::getSize()
{
	return size;
}

template<typename T>
unsigned int ABQ<T>::getMaxCapacity()
{
	return maxCapacity;
}

