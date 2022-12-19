
#include "Header.h"

TMP
/**
* @brief Constructor
* @param capacity The capacity of the vector
*/

HBVector<T>::HBVector(int cap)
{
	if (cap <= 0)
	{
		cout << "For the Capacity, Please Enter a Number greater than Zero." << endl;
		exit(1);
	}
	data = new T[10];
	Size = 0;
	Capacity = cap;
}

/**
* @brief Constructor
* @param arr The array to copy from
* @param n The number of items to copy
*/
TMP
HBVector<T>::HBVector(T* arr, int n)
{ //!< 
	data = new T[n];
	for (int i = 0; i < n; i++)
	{
		data[i] = arr[i];
	}
	Size = n;
	Capacity = n;
}

/**
* @brief Copy Constructor
* @param other The vector to copy from
*/
TMP
HBVector<T>::HBVector(const HBVector& other)
{
	data = new T[other.Size];
	for (int i = 0; i < other.Size; i++)
	{
		data[i] = other.data[i];
	}
	Size = other.Size;
	Capacity = other.Capacity;
}

/**
* @brief Destructor
*/
TMP
HBVector<T>::~HBVector()
{
	delete[] data;
}

/**
* @brief Copy Assignment
* @param other The vector to copy from
* @return A reference to this vector
*/
TMP
HBVector<T>& HBVector<T>::operator=(const HBVector& other)
{
	if (this != &other)
	{
		delete[] data;
		data = new T[other.Size];
		for (int i = 0; i < other.Size; i++)
		{
			data[i] = other.data[i];
		}
		Size = other.Size;
		Capacity = other.Capacity;
	}
	return *this;
}

/**
* @brief Move Assignment
* @param other The vector to move from
* @return A reference to this vector
*/
TMP
HBVector<T>& HBVector<T>::operator=(const HBVector&& other)
{
	if (this != &other)
	{
		delete[] data;
		data = new T[other.Size];
		for (int i = 0; i < other.Size; i++)
		{
			data[i] = other.data[i];
		}
		Size = other.Size;
		Capacity = other.Capacity;
	}
	return *this;
}

/**
* @brief [] operator overloading
* @param index The index of the element to return
* @return the element at the given index
*/
TMP
T& HBVector<T>::operator[](int index)
{
	if (index < 0 || index >= Size)
	{
		throw "Index out of range";
	}
	return data[index];
}

/**
* @brief adding an element to the end of the vector
* @param item The item to add
*/
TMP
int HBVector<T>::push_back(T element)
{
	if (Size == Capacity)
	{
		T* temp = new T[Capacity * 2];
		for (int i = 0; i < Size; i++)
		{
			temp[i] = data[i];
		}
		delete[] data;
		data = temp;
		Capacity *= 2;
	}
	data[Size] = element;
	Size++;
	return Size;
}

/**
* @brief removing the last element from the vector
* @return the last element
*/
TMP
T HBVector<T>::pop_back()
{
	if (Size == 0)
	{
		throw "Vector is empty";
	}
	Size--;
	return data[Size];
}


/**
* @brief inserting an element where the iterator is pointing
* @param itr The iterator to insert at
* @param item The item to insert
*/
TMP
void HBVector<T>::insert(Iterator<T> itr, T element)
{
	if (itr < data || itr > data + Size)
	{
		throw "Iterator out of range";
	}
	
	if (Size == Capacity)
	{
		resize(Capacity * 2);
	}
	
	for (Iterator<T> i = data + Size; i > itr; i--)
	{
		*i = *(i - 1);
	}
	
	*itr = element;
	Size++;
}

/**
* @brief erasing an element where the iterator is pointing
* @param itr The iterator to erase at
*/
TMP
void HBVector<T>::erase(Iterator<T> itr)
{
	if (itr < data || itr >= data + Size)
	{
		throw "Invalid iterator";
	}
	for (iterator i = itr; i < data + Size - 1; i++)
	{
		*i = *(i + 1);
	}
	Size--;
}

/**
* @brief erase a range of elements
* @param start The iterator to start erasing at
* @param end The iterator to stop erasing at
*/
TMP
void HBVector<T>::erase(Iterator<T> start, Iterator<T> end)
{
	if (start < data || start >= data + Size || end < data || end >= data + Size)
	{
		throw "Invalid iterator";
	}
	
	for (iterator i = start; i < end; i++)
	{
		erase(i);
	}
	
}

/**
* @brief pointing to the first element
* @return pointer to the first element
*/
TMP
Iterator<T> HBVector<T>::begin()
{
	Iterator<T> i(data);
	return i;
}

/**
* @brief pointing to the last element
* @return pointer to the last element
*/
TMP
Iterator<T> HBVector<T>::end()
{
	Iterator<T> end(data + Size);
	return end;
}

/**
* @brief the size of the vector
* @return the size of the vector
*/
TMP
int HBVector<T>::size() const
{
	return Size;
}

/**
* @brief the capacity of the vector
* @return the capacity of the vector
*/
TMP
int HBVector<T>::capacity() const
{
	return Capacity;
}

/**
* @brief clearing the vector
*/
TMP
void HBVector<T>::clear()
{
	Size = 0;
}

/**
* @brief resizing the vector
* @param n The new size of the vector
*/
TMP
void HBVector<T>::resize(int newCap)
{
	if (newCap < Size)
	{
		throw "New capacity is too small";
	}
	T* temp = new T[newCap];
	for (int i = 0; i < Size; i++)
	{
		temp[i] = data[i];
	}
	delete[] data;
	data = temp;
	Capacity = newCap;
}

/**
* @brief checking if the vector is empty
* @return true if the vector is empty, false otherwise
*/
TMP
bool HBVector<T>::empty()
{
	return Size == 0;
}

/**
* @brief printing the vector
*/
TMP
void printVec(HBVector<T> vec)
{
	Iterator<T> i(vec.begin());
	Iterator<T> end(vec.end());
	while (i != end)
	{
		cout << *i << " ";
		i++;
	}
}

/**
* @brief printing the vector
*/
TMP
ostream &operator<< (ostream& out,HBVector<T> vec)
{
	Iterator<T> i(vec.begin());
	Iterator<T> end(vec.end());
	while (i != end)
	{
		out << *i << " ";
		i++;
	}
}
