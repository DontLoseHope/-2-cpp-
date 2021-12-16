#include "warrior_base.cpp"
#include "../weapon/arrow.cpp"
#include "../weapon/bomb.cpp"
#include "../weapon/sword.cpp"
#include "../weapon/weapon_base.cpp"
#include <vector>
using namespace std;

class ninja : public warrior_base
{
private:
    vector<weapon_base *> weapon;
    static int init_hp;

public:
    ninja(int Id, int Hp = init_hp) : warrior_base(Id, Hp) {
        switch (Id % TYPE_MAX)
        {
        case arrow::identity:
            weapon.push_back((weapon_base *)new arrow);
            weapon.push_back((weapon_base *)new sword);
            break;
        case bomb::identity:
            weapon.push_back((weapon_base *)new bomb);
            weapon.push_back((weapon_base *)new arrow);
            break;
        case sword::identity:
            weapon.push_back((weapon_base *)new sword);
            weapon.push_back((weapon_base *)new bomb);
            break;
        default:
            break;
        }
    }
    ~ninja();
    static int get_init_hp(void) {
        return init_hp;
    }
    static void set_init_hp(int Hp) {
        init_hp = Hp;
    }
    void print_warrior_feature(void) const { 
        cout << "It has a " << weapon[0]->get_name() << " and a " << weapon[1]->get_name() << endl;
    }
};

ninja::~ninja()
{
    for(auto const &p : weapon) {
        delete (p);
    }
}

int ninja::init_hp = 0;
