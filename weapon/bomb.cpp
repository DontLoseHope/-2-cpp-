#ifndef _BOMB_
#define _BOMB_
#include "weapon_base.cpp"
#include <string>
using namespace std;

class bomb : public weapon_base
{
private:
    string name;
public:
    static int const identity = 1;
    bomb() : name(string("bomb")) {};
    std::string const &get_name(void) const;
    ~bomb();
};

std::string const& bomb::get_name(void) const{
    return name;
}

bomb::~bomb()
{
}
#endif