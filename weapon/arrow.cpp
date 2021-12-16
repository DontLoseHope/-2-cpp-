#ifndef _ARROW_
#define _ARROW_
#include "weapon_base.cpp"
#include <string>
using namespace std;

class arrow : public weapon_base
{
private:
    string name;
public:
    static int const identity = 2;
    arrow() : name(string("arrow")) {};
    ~arrow();
    string const &get_name(void) const;
};

string const &arrow::get_name(void) const {
    return name;
}
arrow::~arrow()
{
}
#endif