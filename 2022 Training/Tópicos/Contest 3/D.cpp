#include <bits/stdc++.h>

using namespace std;

struct Hero
{
    string name;
    int ac, sp, st;

    Hero(string name = "", int ac = 0, int sp = 0,int st = 0) : name(name), ac(ac), sp(sp),st(st) {}

    bool operator<(const Hero &a)
    {
        if (a.ac != ac) {
            return a.ac < ac;
        } else {
            if (a.sp != sp) {
                return a.sp < sp;
            } else {
                if (a.st != st) {
                    return a.st > st;
                } else {
                    return a.name > name;
                }
                
            }
        } 
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<Hero> ar;
    while (n--) {
        Hero hero;
        string name;
        int ac, sp, st;
        cin >> name >> ac >> sp >> st;
        hero.name = name;
        hero.ac = ac;
        hero.sp = sp;
        hero.st = st;
        ar.push_back(hero);
    }

    sort(ar.begin(), ar.end());

    for (auto it: ar) {
        cout << it.name << endl;
    }
   

    return 0;
}
