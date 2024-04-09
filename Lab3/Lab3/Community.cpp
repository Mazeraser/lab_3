#include "Community.h"
using namespace std;

string Community::GetName() { return _name; }
void Community::SetName(std::string name) { _name = name; }

string Community::GetDescription() { return _description; }
void Community::SetDescription(std::string description) { _description = description; }

int Community::GetMembers() { return _members; }
void Community::SetMembers(const int members) { _members = members; }