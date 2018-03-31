#include "coordinates.h"

Coordinates::Coordinates()
{
    initialize(ORIGIN_X, ORIGIN_Y, ORIGIN_Z);
}

Coordinates::Coordinates(float X, float Y, float Z)
{
    initialize(X, Y, Z);
}

Coordinates::~Coordinates()
{
    // TODO
}

float Coordinates::getX()
{
    return x;
}

float Coordinates::getY()
{
    return y;
}

float Coordinates::getZ()
{
    return z;
}

void Coordinates::initialize(float X, float Y, float Z)
{
    x = X;
    y = Y;
    z = Z;
}

