#ifndef SHIP_H
#define SHIP_H
#include <vector>
using namespace std;
const int HEALTHY = 0;
const int KILLED = 1;
class Ship
{
public:
    int size,X,Y;
    vector<int> blocks;
    Ship(int X, int Y, int size);
    Ship(const Ship& theOther);
};

#endif // SHIP_H
