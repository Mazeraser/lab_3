#include<string>
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
};