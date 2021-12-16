#include "warrior_base.cpp"
#include "wolf.cpp"
#include "iceman.cpp"
#include <iostream>

using namespace std;

int main(void) {
    iceman::set_init_hp(10);
    iceman ice(1);
    wolf::set_init_hp(5);
    wolf wo(1);

    cout << "iceman " << iceman::get_init_hp() << endl;
    cout << "wolf " << wolf::get_init_hp() << endl;
    return 0;
}
