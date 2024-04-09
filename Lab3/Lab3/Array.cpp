#include "Array.h"

template<typename T>
Array<T>::~Array() {
	delete[]_arr;
}

template<typename T>
void Array<T>::SetElement(const int index, const T n) {
	_arr[index] = n;
}

template<typename T>
T Array<T>::GetElement(const int index) {
	return _arr[index];
}

template<typename T>
void Array<T>::SetLength(const int n) {
	_arr = new T[n];
}