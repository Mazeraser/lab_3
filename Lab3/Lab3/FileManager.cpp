#include "FileManager.h"
#include "Community.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void FileManager::create(Community** arr, int* n)
{
retry:
	cout << "n=";
	cin >> *n;
	if (*n <= 0) {
		cout << "Error: n less or equal than 0, write again.";
		goto retry;
	}
	else {
		*arr = new Community[*n];
		for (int i = 0; i < *n; i++)
		{
			cout << "ID: " << i << endl;
			cin >> (*arr)[i];
		}
	}
}
void FileManager::write(Community* arr, int n, const  std::string name)
{
	ofstream f(name + ".txt");
	if (!f.is_open())
	{
		cout << "Error: file is not found" << endl;
		return;
	}
	f << n << endl;
	for (int i = 0; i < n; i++)
		f << arr[i].GetName() + " " + arr[i].GetDescription() + " " << arr[i].GetMembers() << endl;
	f.close();
	cout << "|database saved succesfull" << endl;
}
void FileManager::read(Community**  arr, int* n, const  std::string name)
{
	ifstream f(name + ".txt");
	if(!f.is_open()) 
	{
		cout << "|Error: file is not found" << endl;
		return;
	}
	f >> *n;
	*arr = new Community[*n];
	string* words = new string[3];
	for (int i = 0; i < *n; i++)
	{
		f >> words[0] >> words[1] >> words[2];
		(*arr)[i].SetName(words[0]);
		(*arr)[i].SetDescription(words[1]);
		(*arr)[i].SetMembers(stoi(words[2]));
	}
	f.close();
	cout << "|database loaded succesfull" << endl;
}
void FileManager::found(Community* arr, int n, const  int found_index)
{
	string findKey;
	Community object;
	bool initFlag = false;
	cout << "|Enter key what you want find object : ";
	cin >> findKey;
	switch (found_index) {
		case 1:
			for (int i = 0; i < n; i++) {
				if ((arr)[i].GetName() == findKey)
				{
					object = arr[i];
					initFlag = true;
					break;
				}
			}
			break;
		case 2:
			for (int i = 0; i < n; i++) {
				if ((arr)[i].GetDescription() == findKey)
				{
					object = arr[i];
					initFlag = true;
					break;
				}
			}
			break;
		case 3:
			for (int i = 0; i < n; i++) {
				if ((arr)[i].GetMembers() == stoi(findKey))
				{
					object = arr[i];
					initFlag = true;
					break;
				}
			}
			break;
	}
	if (initFlag)
		print(new Community[1]{ object }, 1);
	else
		cout << "Error: object is not found" << endl;
}
void FileManager::print(Community* arr, int n)
{
	for (int i = 0; i < n; i++) {
		cout << "ID: " << i << endl;
		cout << arr[i];
	}
}
void FileManager::add(Community** arr, int* n)
{
	int n2;
	Community* old_arr = *arr;
	Community* add_arr;

	cout << "Enter a count of new elements: ";
	cin >> n2;

	*arr = new Community[*n + n2];
	add_arr = new Community[n2];

	for (int i = 0; i < n2; i++)
		cin >> add_arr[i];

	for (int i = 0; i < *n; i++)
		(*arr)[i] = old_arr[i];
	for (int i = 0; i < n2; i++)
		(*arr)[*n + i] = add_arr[i];

	*n = *n + n2;
}
void FileManager::del(Community** arr, int* n, int del_ind) 
{
	*n=*n-1;

	Community* old_arr = *arr;
	Community* new_arr = new Community[*n];
	for (int i = 0; i < *n; i++)
	{
		if (i >= del_ind)
			new_arr[i] = old_arr[i + 1];
		else
			new_arr[i] = old_arr[i];
	}
	*arr = new_arr;
}
void FileManager::update_elem(Community** arr, int n, int elem_index, int update_ind) {
	string stringField;
	int members;
	switch (update_ind)
	{
	case 1:
		cout << "Enter new name: ";
		cin >> stringField;
		(*arr)[elem_index].SetName(stringField);
		break;
	case 2:
		cout << "Enter new description: ";
		cin >> stringField;
		(*arr)[elem_index].SetDescription(stringField);
		break;
	case 3:
		cout << "Enter new members count: ";
		cin >> members;
		(*arr)[elem_index].SetMembers(members);
		break;
	}
}