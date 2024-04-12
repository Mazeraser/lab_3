#include"FileManager.h"
#include"Array.h"
#include"Community.h"
#include<iostream>

using namespace std;

int main()
{
	int n = 1;
	int stop = 0;
	int id;
	int field_index;
	Community* arr=new Community[n];
	string fileName;
	char key = ' ';
	char key2 = ' ';
	while (stop == 0) {
		cout << "|choose action"
				"\n|-- 1 - create new database"
				"\n|-- 2 - save current database to file"
				"\n|-- 3 - print current database"
				"\n|-- 4 - read database from file"
				"\n|-- 5 - find in current database"
				"\n|-- 6 - add new elements for current database"
				"\n|-- 7 - delete element by id for current database"
				"\n|-- 8 - change element by id for current database"
				"\n|-- write any symbol to stop app"
				"\n|---- enter: ";
		cin >> key;
		switch (key) {
			case '1':
				FileManager::create(&arr,&n);
				break;
			case '2':
				cout << "|Enter file name(without extension): ";
				cin >> fileName;
				FileManager::write(arr, n, fileName);
				break;
			case '3':
				FileManager::print(arr,n);
				break;
			case '4':
				cout << "|Enter file name(without extension): ";
				cin >> fileName;
				FileManager::read(&arr, &n, fileName);
				break;
			case '5':
				cout << "|Select the field what you want find object"
						"\n|-- 1-name"
						"\n|-- 2-description"
						"\n|-- 3-members count"
						"\n|---- enter: ";
				cin >> key2;
				FileManager::found(arr, n, atoi(&key2));
				break;
			case '6':
				FileManager::add(&arr, &n);
				break;
			case '7':
				cout << "Enter element id: ";
				cin >> id;
				FileManager::del(&arr, &n, id);
				break;
			case '8':
				cout << "Enter element id: ";
				cin >> id;
				cout << "Select field id what you want change"
						"\n 1-name"
						"\n 2-description"
						"\n 3-members"
						"\n enter: ";
				cin >> field_index;
				FileManager::update_elem(&arr, n, id, field_index);
				break;
			default:
				stop = 1;
		}
	}
	return 0;
}