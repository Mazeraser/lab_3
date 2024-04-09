#include"FileManager.h"
#include"Array.h"
#include"Community.h"
#include<iostream>

using namespace std;

int main()
{
	int n = 1;
	int stop = 0;
	Community* arr=new Community[n];
	while (stop == 0) {
		char key=' ';
		cout << "|choose action"
				"\n|-- 1 - create new database"
				"\n|-- 2 - save current database to file"
				"\n|-- 3 - print current database"
				"\n|-- 4 - read database from file"
				"\n|-- 5 - find in current database"
				"\n|-- write any symbol to stop app"
				"\nenter:\n";
		cin >> key;
		switch (key) {
			case '1':
				FileManager::create(&arr,&n);
				break;
			case '2':
				break;
			case '3':
				FileManager::print(arr,n);
				break;
			case '4':
				break;
			case '5':
				break;
			default:
				stop = 1;
		}
	}
	return 0;
}