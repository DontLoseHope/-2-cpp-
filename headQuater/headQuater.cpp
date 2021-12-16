#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "../warrior/dragon.cpp"
#include "../warrior/iceman.cpp"
#include "../warrior/ninja.cpp"
#include "../warrior/wolf.cpp"
#include "../warrior/lion.cpp"
#include "../warrior/warrior_base.cpp"
#include <algorithm>
#include <unordered_map>

using namespace std;

class headQuater
{
private:
    int lifePower;
    string name;
    int leastPower;
    unordered_map<string, int> warrior_cnt;
    vector<string> birthOrder;
    vector<warrior_base *> warrior;
    bool stopped;
    int next_warrior;

public:
    headQuater(string Name, int LifePower, const vector<string> &BirthOrder, bool Stopped = false)
                        : stopped(Stopped), name(Name), next_warrior(0) {
        lifePower = LifePower;
        for (auto& wa : BirthOrder) {
            birthOrder.push_back(wa);
            warrior_cnt[wa] = 0;
        }
        leastPower = least_power();
    }
    ~headQuater(){};
    int least_power(void);
    bool stopped_make_warrior(void) const;
    void stop_make_warrior(int time);
    int total_warrior_cnt(void);
    int warrior_birth(int time);
};

int headQuater::least_power(void) {
    int least_power = INT32_MAX;
    for (const auto &wa : birthOrder) {
        if (wa.compare("dragon") == 0) {
            least_power = min(dragon::get_init_hp(), least_power);
        } else if (wa.compare("iceman") == 0) {
            least_power = min(iceman::get_init_hp(), least_power);
        } else if (wa.compare("lion") == 0) {
            least_power = min(lion::get_init_hp(), least_power);
        } else if (wa.compare("ninja") == 0) {
            least_power = min(lion::get_init_hp(), least_power);
        } else {
            least_power = min(wolf::get_init_hp(), least_power);
        }
    }
    return least_power;
}

bool headQuater::stopped_make_warrior(void) const {
    return stopped;
}
void headQuater::stop_make_warrior(int time) {
    stopped = true;
    cout << time << " " << name << " headquater stops making warriors" << endl;
}

int headQuater::total_warrior_cnt(void) {
    int ret = 0;
    for (auto const& wa : birthOrder) {
        ret += warrior_cnt[wa];
    }
    return ret;
}

int headQuater::warrior_birth(int time) {
    if (stopped) {
        return 0;
    }
    if (lifePower < leastPower) {
        stop_make_warrior(time);
        return -1;
    }

    bool quit = false;

    while (!quit) {
        for (auto const &wa : birthOrder) {
            if (wa.compare(birthOrder[next_warrior]) == 0) {
                next_warrior = (++next_warrior) % birthOrder.size();
                if (wa.compare("dragon") == 0 && dragon::get_init_hp() <= lifePower) {
                    lifePower -= dragon::get_init_hp();
                    warrior.push_back((warrior_base *)new dragon(time + 1, lifePower));
                    warrior_cnt["dragon"]++;
                    cout << time << " " << name << " dragon " << total_warrior_cnt() << "born with strength " << dragon::get_init_hp() << ","
                         << warrior_cnt["dragon"] << " in " << name << " headquater" << endl;
                    warrior.back()->print_warrior_feature();
                    quit = true;
                    break;
                } else if (wa.compare("iceman") == 0 && iceman::get_init_hp() <= lifePower) {
                    lifePower -= iceman::get_init_hp();
                    warrior.push_back((warrior_base *)new iceman(time + 1));
                    warrior_cnt["iceman"]++;
                    cout << time << " " << name << " iceman " << total_warrior_cnt() << " born with strength " << iceman::get_init_hp() << ","
                         << warrior_cnt["iceman"] << " in " << name << " headquater" << endl;
                    warrior.back()->print_warrior_feature();
                    quit = true;
                    break;
                } else if (wa.compare("lion") == 0 && lion::get_init_hp() <= lifePower) {
                    lifePower -= lion::get_init_hp();
                    warrior.push_back((warrior_base *)new lion(time + 1, lifePower));
                    warrior_cnt["lion"]++;
                    cout << time << " " << name << " lion " << total_warrior_cnt() << " born with strength " << lion::get_init_hp() << ","
                        << warrior_cnt["lion"] << " in " << name << " headquater" << endl;
                    warrior.back()->print_warrior_feature();
                    quit = true;
                    break;
                } else if (wa.compare("ninja") == 0 && ninja::get_init_hp() <= lifePower) {
                    lifePower -= ninja::get_init_hp();
                    warrior.push_back((warrior_base *)new ninja(time + 1, lifePower));
                    warrior_cnt["ninja"]++;
                    cout << time << " " << name << " ninja " << total_warrior_cnt() << " born with strength " << ninja::get_init_hp() << ","
                         << warrior_cnt["ninja"] << " in " << name << " headquater" << endl;
                    warrior.back()->print_warrior_feature();
                    quit = true;
                    break;
                } else if (wa.compare("wolf") == 0 && wolf::get_init_hp() <= lifePower) {
                    lifePower -= wolf::get_init_hp();
                    warrior.push_back((warrior_base *)new wolf(time + 1));
                    warrior_cnt["wolf"]++;
                    cout << time << " " << name << " wolf born with strength " << wolf::get_init_hp() << ","
                         << warrior_cnt["wolf"] << " in " << name << " headquater" << endl;
                    warrior.back()->print_warrior_feature();
                    quit = true;
                    break;
                } else {
                    break;
                }
            }
        }
    }

    return 0;
}