#ifndef _WEAPON_BASE_
#define _WEAPON_BASE_
#define TYPE_MAX 3
#include <string>

class weapon_base
{
private:
    std::string name;
public:
    weapon_base(/* args */);
    virtual ~weapon_base();
    virtual std::string const& get_name(void) const = 0;
};

weapon_base::weapon_base(/* args */)
{
}

weapon_base::~weapon_base()
{
}
#endif