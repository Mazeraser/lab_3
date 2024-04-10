#include"Community.h"
#include"Array.h"
#include<string>
#pragma once

class FileManager
{
public:
	static void create(Community** arr, int* n);
	static void write(Community* arr, int n, const  std::string name);
	static void read(Community** arr, int* n, const  std::string name);
	static void found(Community* arr, int n, const  int found_index);
	static void print(Community* arr,int n);
};

