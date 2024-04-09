#include "FileManager.h"
#include<iostream>
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
void FileManager::write(Community* arr, int* n, const  std::string name){}
void FileManager::read(Community**  arr, int* n, const  std::string name){}
void FileManager::found(Community* arr, int* n, const  int found_index){}
void FileManager::print(Community* arr, int n)
{
	for (int i = 0; i < n; i++) {
		cout << "Name: " + (arr)[i].GetName() << endl;
		cout << "Description: " + (arr)[i].GetDescription() << endl;
		cout << "Members: " << (arr)[i].GetMembers() << endl;
		cout << endl;
	}
}