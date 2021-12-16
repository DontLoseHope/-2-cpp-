#include "warrior_base.cpp"

class lion : public warrior_base
{
private:
    int loyal;
    static int init_hp;

public:
    lion(int Id, int Loyal, int Hp = init_hp) 
        : warrior_base(Id, Hp), loyal(Loyal){};
    ~lion();
    static int get_init_hp(void) {
        return init_hp;
    }
    static void set_init_hp(int Hp) {
        init_hp = Hp;
    }
    void print_warrior_feature(void) const {
        cout << "It's loyalty is " << loyal << endl;
    }
};

int lion::init_hp = 0;

lion::~lion()
{
}
