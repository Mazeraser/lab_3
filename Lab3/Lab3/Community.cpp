#include "Community.h"
#include<algorithm>
using namespace std;

string Community::GetName() { return _name; }
void Community::SetName(std::string name) { _name = name; }

string Community::GetDescription() { return _description; }
void Community::SetDescription(std::string description) { _description = description; }

int Community::GetMembers() { return _members; }
void Community::SetMembers(const int members) { _members = members; }

ostream& operator <<(ostream& out, Community& r)
{
	out << "Name: " + r.GetName() << endl;
	out << "Description: " + r.GetDescription() << endl;
	out << "Members: " << r.GetMembers() << endl;
	return out;
}
istream& operator >>(istream& in, Community& r)
{
	string name;
	cout << "Name: ";
	cin >> name;
	r.SetName(name);

	string description;
	cout << "Description: ";
	cin >> description;
	r.SetDescription(description);

	int members;
	cout << "Members: ";
	cin >> members;
	r.SetMembers(members);
	return in;
}