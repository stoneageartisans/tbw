#ifndef COORDINATES_H
#define COORDINATES_H

#define ORIGIN_X 0.0
#define ORIGIN_Y 0.0
#define ORIGIN_Z 0.0

class Coordinates
{
public:
    Coordinates();
    Coordinates(float X, float Y, float Z);
    virtual ~Coordinates();
    float getX();
    float getY();
    float getZ();
    
private:
    void initialize(float X, float Y, float Z);
    float x;
    float y;
    float z;
};

#endif /* COORDINATES_H */
