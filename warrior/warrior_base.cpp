#ifndef _WARRIOR_BASE_
#define _WARRIOR_BASE_
class warrior_base
{
private:
    int id;
    int hp;

public:
    warrior_base(int Id, int Hp) : id(Id), hp(Hp) {};
    virtual void print_warrior_feature(void) const = 0;
    virtual ~warrior_base();
};

warrior_base::~warrior_base()
{
}

#endif