#include "FileManager.h"
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
		for (int i = 0; i < *n; i++) {
			string name;
			string description;
			int members;

			cout << "enter name:";
			cin >> name;

			cout << "enter description:";
			cin >> description;

			cout << "enter members count:";
			cin >> members;

			(*arr)[i].SetName(name);
			(*arr)[i].SetDescription(description);
			(*arr)[i].SetMembers(members);
			
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
		f << arr[i].GetName() + " " + arr[i].GetDescription() + " " << arr[i].GetMembers()<<endl;
	f.close();
}
void FileManager::read(Community**  arr, int* n, const  std::string name)
{
	ifstream f(name + ".txt");
	if(!f.is_open()) 
	{
		cout << "Error: file is not found" << endl;
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
		cout << "Name: " + (arr)[i].GetName() << endl;
		cout << "Description: " + (arr)[i].GetDescription() << endl;
		cout << "Members: " << (arr)[i].GetMembers() << endl;
		cout << endl;
	}
}