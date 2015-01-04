#include <iostream>
#include <cmath>
#include <set>

inline int sumDigits(int x)
{
    int d = 0;
    int n = x;
    while (n > 0) {
        d += (n % 10);
        n /= 10;
    }
    return d;
}

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
    int ax = std::abs(p.x);
    int ay = std::abs(p.y);

    int sd = sumDigits(ax) + sumDigits(ay);
    if (sd <= 19) {
        return true;
    } else {
        return false;
    }
}

inline void checkAndAdd(std::set<pt> &s, const pt &u);
void move(std::set<pt> &s, const pt &cur);

inline void checkAndAdd(std::set<pt> &s, const pt &u)
{
    if (feasible(u) && s.count(u) == 0) {
        s.insert(u);
        move(s, u);
    }
    return;
}

void move(std::set<pt> &s, const pt &cur)
{
    pt u = { cur.x, cur.y + 1 };
    pt d = { cur.x, cur.y - 1 };
    pt l = { cur.x - 1, cur.y };
    pt r = { cur.x + 1, cur.y };

    checkAndAdd(s, u);
    checkAndAdd(s, d);
    checkAndAdd(s, l);
    checkAndAdd(s, r);
    return;
}

int main()
{
    pt start = { 0, 0 };
    std::set<pt> allmoves;
    allmoves.insert(start);
    move(allmoves, start);
    std::cout << allmoves.size();
    return 0;
}
