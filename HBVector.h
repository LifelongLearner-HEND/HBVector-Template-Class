#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <iterator>
using namespace std;

#define TMP template <class T>

TMP
class Iterator
{
private:
	T* ptr;
	
public:
	Iterator(T* ptr) : ptr(ptr) {}
	Iterator(Iterator<T> const& itr) : ptr(itr.ptr) {}
	Iterator& operator++() { ptr++; return *this; }
	Iterator operator++(int) { Iterator tmp(*this); operator++(); return tmp; }
	bool operator==(const Iterator& rhs) { return ptr == rhs.ptr; }
	bool operator!=(const Iterator& rhs) { return ptr != rhs.ptr; }
	T& operator*() { return *ptr; }
};

TMP
class HBVector {
private:
	T* data;
	int Size, Capacity;
public:
	// Constructors and Big 4 
	HBVector(int cap);								// Initialize by specific capacity
		// No content is added, size = 0
		// Assign a default size value
	HBVector(T* arr, int  n);						// Initialize by n items from array 
	HBVector(const HBVector& other);					// Initialize with a copy
	~HBVector();									// Delete allocated memory
	HBVector& operator=(const HBVector& other);			// Copy assignment  
	HBVector& operator=(const HBVector&& other);		// Move assignment 

	// Access operations 
	T& operator[](int index); // Access item by reference 

	// Throw an exception if out of range 
///////////////////////////////////////////////////////////////////////////////////
	
// Modifying operations 
	int push_back(T element);										// Add item to end of vec & return # of items 
																	// Increase capacity of needed
	T pop_back();													// Remove and return last element in vec 
	void erase(Iterator<T> itr);									// Remove item at iterator
																	// Throw exception if invalid iter 
	void erase(Iterator<T> iterator1, Iterator<T> iterator2);		// Remove items between 
																	// iterator 1 <= iterator 2 otherwise do nothing
																	// Throw exception if any iterator outside range
	void clear();													// Delete all vector content
	void insert(Iterator<T>, T);									// Insert item at iterator 
																	// Throw exception if invalid 

	// Iterators 								// Supports *, + and ++ operations at least
	// Can use: typedef T* iterator 
												// Or u can use std::iterator so you can 
	// apply STL algorithms on HBVector
		Iterator<T> begin();						// Return an iterator (T*) 
		Iterator<T> end();							// Return an iterator (T*) 
///////////////////////////////////////////////////////////////////////////////////
	// Comparison operations 
		bool operator==(const HBVector<T>&);		// Return true if ==  
		bool operator< (const HBVector<T>&);			// Compares item by item
	// Return true if first different item in this is < in other

	// Capacity operations 
		int size() const;						// Return current size of vec
		int capacity() const;					// Return size of current allocated array  
		void resize(int newCap);				// Relocate to bigger space
		bool empty();							// Return true if size is 0

	// Friends 
		friend ostream &operator<< (ostream& out, HBVector<T> vec);
};


#endif
