#pragma once
#include <iostream>
#include "MyException.h"
using namespace std;

template <class T> 
class SafeArray{
private:
	T* m_arr;
	int m_size;
	//a boolean to check if the SafeArray was already deleted(it's array)
	//so we won't call delete more than once for a given address.
	bool wasDeleted;
	void setArr(T* arr) { this->m_arr = arr; }
public:
	//c'tor
	SafeArray(const int size);
	//copy c'tor
	SafeArray(const SafeArray<T>& sa);
	//default c'tor
	SafeArray();
	//d'tor
	~SafeArray();
	//returns the value of the array in 'index' place.
	//throws exception if the index is out of bounds.
	T getValue(int index) const;
	//sets the value of array[index] with 'val'.
	//throws exception if the index is out of bounds.
	void setValue(int index, T val);
	//returns the size of the array
	int getSize() const {return this->m_size;}
	//sets the size of the array.
	//throws exception if m_size was already initialized
	//throws exception if 'size' is 0 or smaller.
	void setSize(const int size);
	//fills the array with NULLs
	void init();
	//operates just as in regular array, returns the value in 'i' index
	//throws exception if the index is out of bounds.
	//throws exception if 'size' is 0 or smaller.
	T& operator[](const int i) const;
	//returns pointer to the next value
	//throws exception if m_size is 1 because there is no next value 
	//throws exception if m_size is 0 or smaller.
	SafeArray<T>& operator++();
	//returns the pointer arr+i
	//throws exception if the index is out of bounds.
	//throws exception if 'size' is 0 or smaller.
	SafeArray<T>& operator+(int i);
	//returns the value of arr. Usage: *(arr) 
	//throws exception if 'size' is 0 or smaller.
	T& operator*();
	//prints the array
	friend ostream& operator<< (ostream& os, const SafeArray<T>& sa) {
		//if size is not declared
		if (sa.getSize() <= 0) {
			os << "set size!, array is empty";
			return os;
		}
		int i;
		//go through array elemnts
		for (i = 0; i < sa.getSize() - 1; ++i) {
			if(sa.getValue(i) != NULL)
				os << sa.getValue(i) << ",";
			else
				os << "NULL,";
		}
		if (sa.getValue(i) != NULL)
			os << sa.getValue(i);
		else
			os << "NULL";
		return os;
	}
	//returns a pointer to the array
	T* getArr() const { return this->m_arr; }
};

template<class T> 
SafeArray<T>::SafeArray(const int size):m_size(size) {
	//check if size was not set yet or if it is illegal.
	if (size <= 0) {
		throw UndeclaredSizeException();
	}
	//define a new array
	m_arr = new T[size];
	//initialize array's values
	init();
	wasDeleted = false;
}
template<class T>
SafeArray<T>::SafeArray(const SafeArray<T>& sa) {
	//set the array size
	this->setSize(sa.getSize());
	//Not like expected the array's address is being copied, so that later we could effect both SafeArrays. 
	this->setArr(sa.getArr());
}

template<class T>
SafeArray<T>::SafeArray():m_size(0) {
	//creating an empty array
	m_arr = NULL;
	wasDeleted = false;
}

template<class T>
SafeArray<T>::~SafeArray(){
	//check if array's address was already deleted.
	if (this->wasDeleted == false) {
		//delete array.
		delete this->m_arr;
		this->m_arr = NULL;
		//set 'wasDeleted' to be true, so it won't delete the same address twice.
		this->wasDeleted = true;
	}
}

template<class T>
inline T SafeArray<T>::getValue(int index) const
{
	//check if index is in bounds
	if (index >= this->getSize() || index < 0) {
		throw OutOfBoundsException();
	}
	//return the value at index
	return *(m_arr + index);
}

template<class T>
inline void SafeArray<T>::setValue(int index, T val)
{
	//check if index is in bounds
	if (index >= this->getSize() || index < 0) {
		throw OutOfBoundsException();
	}
	//set the SafeArray value at index to be 'val' 
	*(m_arr + index) = val;
}

template<class T>
void SafeArray<T>::setSize(const int size)
{
	//check if size was already set (it must no change)
	if (this->getSize() > 0) {
		throw ChangeFixedSizeException();
	}
	//check if size was not set yet or if it is illegal.
	if (size <= 0) {
		throw UndeclaredSizeException();
	}
	//setting the size
	m_size = size;
	//create a new array
	m_arr = new T[size];
	//initialize the array with NULLs
	init();
}

template<class T>
inline void SafeArray<T>::init() {
	//for each index in the array set NULL 
	for (int i = 0; i < this->getSize(); ++i) {
		this->setValue(i, NULL);
	}
}
template<class T>
T & SafeArray<T>::operator[](const int i) const
{
	//check if i is in bounds
	if (i >= this->getSize() || i < 0) {
		throw OutOfBoundsException();
	}
	//check if size was not set yet
	if (this->getSize() <= 0) {
		throw UndeclaredSizeException();
	}
	//return the value at index 'i'
	return *(this->m_arr + i);
}
template<class T>
SafeArray<T>& SafeArray<T>:: operator++() {

	//check if size was not set yet
	if (this->getSize() <= 0) {
		throw UndeclaredSizeException();
	}
	//check if size is 1 because then operator ++ will be out of bounds
	if (this->getSize() == 1) {
		throw OutOfBoundsException();
	}
	//create a new array that will be the same as original but will start at index 1 instead of 0
	SafeArray<T> *sa = new SafeArray<T>(this->getSize() - 1);
	sa->setArr(this->getArr()+1);
	//return the new SafeArray
	return *sa;
}

template<class T>
SafeArray<T>& SafeArray<T>::operator+(int i)
{
	//check if size was not set yet
	if (this->getSize() <= 0) {
		throw UndeclaredSizeException();
	}
	//check if i is in bounds
	if (i >= this->getSize() || i < 0) {
		throw OutOfBoundsException();
	}
	//create a new array that will be the same as original but will start at index 'i' instead of 0
	SafeArray<T> *sa = new SafeArray<T>(this->getSize() - i);
	sa->setArr(this->getArr() + i);
	//return the SafeArray
	return *sa;
}

template<class T>
inline T& SafeArray<T>::operator*()
{
	//check if size was not set yet
	if (this->getSize() <= 0) {
		throw UndeclaredSizeException();
	}
	//return the value of the array at index 0
	return (this->m_arr[0]);
}
