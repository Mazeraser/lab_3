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
	static void add(Community** arr, int* n);
	static void del(Community** arr, int* n, int del_ind);
	static void update_elem(Community** arr, int n, int found_index, int update_ind);
};

