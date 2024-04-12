#include<string>
#include<iostream>
#pragma once
class Community
{
private:
	std::string _name;
	std::string _description;
	int _members;
public:
	std::string GetName();
	void SetName(std::string name);

	std::string GetDescription();
	void SetDescription(std::string description);

	int GetMembers();
	void SetMembers(const int members);

friend std::ostream &operator <<(std::ostream& out, Community& r);
friend std::istream &operator >>(std::istream& in, Community& r);
};