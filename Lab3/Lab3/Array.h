#pragma once
template<typename T>
class Array
{
private:
	T* _arr;
public:
	~Array();
	void SetElement(const int index,const T n);
    T GetElement(const int index);
	void SetLength(const int n);
};

