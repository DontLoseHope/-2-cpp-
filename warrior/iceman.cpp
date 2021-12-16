#ifndef _ICEMAN_
#define _ICEMAN_
#include "warrior_base.cpp"
#include "../weapon/arrow.cpp"
#include "../weapon/bomb.cpp"
#include "../weapon/sword.cpp"
#include "../weapon/weapon_base.cpp"

class iceman : public warrior_base
{
private:
    weapon_base *weapon;
    static int init_hp;

public:
    iceman(int Id, int Hp = init_hp) : warrior_base(Id, Hp) {
        switch (Id % TYPE_MAX)
        {
        case arrow::identity:
            weapon = (weapon_base*)new arrow();
            break;
        case bomb::identity:
            weapon = (weapon_base*)new bomb();
            break;
        case sword::identity:
            weapon = (weapon_base*)new sword();
            break;
        default:
            break;
        }
    };
    ~iceman();
    static int get_init_hp(void) {
        return init_hp;
    }
    static void set_init_hp(int Hp) {
        init_hp = Hp;
    }
    void print_warrior_feature(void) const {
        std::string weapon_name;
        weapon_name = weapon->get_name();
        cout << "It has a " << weapon_name << endl;
    };
};

iceman::~iceman()
{
}

int iceman::init_hp = 0;

#endif