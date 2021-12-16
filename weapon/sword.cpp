#ifndef _SWORD_
#define _SWORD_
#include "weapon_base.cpp"

class sword : public weapon_base
{
private:
    std::string name;
public:
    static int const identity = 0;
    sword(/* args */) : name(std::string("sword")) {};
    ~sword();
    virtual std::string const& get_name(void) const;
};

std::string const& sword::get_name(void) const{
    return name;
}

sword::~sword()
{
}
#endif