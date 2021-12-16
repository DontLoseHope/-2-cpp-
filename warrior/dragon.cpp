#include "warrior_base.cpp"
#include "../weapon/arrow.cpp"
#include "../weapon/bomb.cpp"
#include "../weapon/sword.cpp"
#include "../weapon/weapon_base.cpp"

class dragon : public warrior_base
{
private:
    double morale;
    weapon_base *weapon;
    static int init_hp;

public:
    dragon(int Id, int power_remain, int Hp = init_hp) : warrior_base(Id, Hp) {
        if (Hp == 0) {
            morale = 0;
        }
        morale = power_remain / Hp;
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
    }

    ~dragon() {
        delete (weapon);
    }

    void print_warrior_feature(void) const;

    static int get_init_hp(void)
    {
        return init_hp;
    }
    static void set_init_hp(int Hp) {
        init_hp = Hp;
    }

};

int dragon::init_hp = 0;

void dragon::print_warrior_feature(void) const {
    string weapon_name;
    weapon_name = weapon->get_name();
    cout << "It has a " << weapon_name << ",and it's morale is " << morale << endl;
}