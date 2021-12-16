#ifndef _WOLF_
#define _WOLF_
#include "warrior_base.cpp"
class wolf : public warrior_base
{
private:
    /* data */
    static int init_hp;
public:
    wolf(int Id, int Hp = init_hp) : warrior_base(Id, Hp) {};
    ~wolf();
    static int get_init_hp(void) {
        return init_hp;
    }
    static void set_init_hp(int Hp) {
        init_hp = Hp;
    }
    void print_warrior_feature(void) const {}
};

wolf::~wolf()
{
}

int wolf::init_hp = 0;

#endif