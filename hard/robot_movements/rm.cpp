#include <iostream>
#include <cmath>
#include <set>

typedef struct ps { 
    int x;
    int y;
    friend bool operator==(const struct ps &a, const struct ps &b);
    friend bool operator<(const struct ps &a, const struct ps &b);
} pt;

bool operator==(const pt &a, const pt &b) {
    return (a.x == b.x && a.y == b.y);
}

bool operator<(const pt &a, const pt &b) {
    if (a.x == b.x) {
        return (a.y < b.y);
    } else {
        return (a.x < b.x);
    }
}

inline bool feasible(const pt &p)
{
    return (p.x >= 0 && p.x <= 3 &&
        p.y >= 0 && p.y <= 3);
}

void move(std::set<pt> &s, const pt &cur, const pt &dest, double &count);

void move(std::set<pt> &s, const pt &cur, const pt &dest, double &count)
{
    s.insert(cur);
    if (cur == dest) {
        count++;
    } else {
        pt u = { cur.x, cur.y + 1 };
        pt d = { cur.x, cur.y - 1 };
        pt l = { cur.x - 1, cur.y };
        pt r = { cur.x + 1, cur.y };


        if (s.count(u) == 0 && feasible(u)) {
            std::set<pt> su(s);
            move(su, u, dest, count);
        }
        if (s.count(d) == 0 && feasible(d)) {
            std::set<pt> sd(s);
            move(sd, d, dest, count);
        }
        if (s.count(l) == 0 && feasible(l)) {
            std::set<pt> sl(s);
            move(sl, l, dest, count);
        }
        if (s.count(r) == 0 && feasible(r)) {
            std::set<pt> sr(s);
            move(sr, r, dest, count);
        }
    }

    return;
}

int main()
{
    pt start = { 0, 3 };
    pt dest = { 3, 0 };
    double count = 0;
    std::set<pt> allmoves;
    allmoves.insert(start);
    move(allmoves, start, dest, count);
    std::cout << count;
    return 0;
}
