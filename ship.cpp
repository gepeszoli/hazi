#include "ship.h"

Ship::Ship(int X, int Y, int size)
{
    this->size = size;
    this->X = X;
    this->Y = Y;
    for(int i=0; i<size; i++) {
        blocks.push_back( HEALTHY );
    }
}

Ship::Ship(const Ship& theOther) {
    this->size = theOther.size;
    for(int i=0; i<size; i++) {
        blocks.push_back( HEALTHY );
    }
    for(int i=0; i<size; i++) {
        this->blocks[i] = theOther.blocks[i];
    }
}
