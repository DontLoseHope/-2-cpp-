#include "headQuater.cpp"

int main(void) {
    dragon::set_init_hp(3);
    ninja::set_init_hp(4);
    iceman::set_init_hp(5);
    lion::set_init_hp(6);
    wolf::set_init_hp(7);

    headQuater red("red", 20, vector<string>{"iceman", "lion", "wolf", "ninja", "dragon"});
    headQuater blue("blue", 20, vector<string>{"lion", "dragon", "ninja", "iceman", "wolf"});
    int time = 0;
    while (!red.stopped_make_warrior() || !blue.stopped_make_warrior())
    {
        red.warrior_birth(time);
        blue.warrior_birth(time);
        time++;
    }

    return 0;
}