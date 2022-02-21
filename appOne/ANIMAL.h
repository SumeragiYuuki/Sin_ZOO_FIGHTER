#pragma once
#include "GAME_OBJECT.h"
#include "libOne.h"
class ANIMAL :
    public GAME_OBJECT
{
public:
    struct DATA {
        int img;
        VECTOR2 pos;
        VECTOR2 centerPos;
        float fallSpeed;
        float targetPosY;
        float advSpeed;
        float angle;
        float limmitW;        
        //è’ìÀîªíËóp
        float bcRadius;
        float invincibleTime;
        float invincibleRestTime;
        int hp;
        VECTOR2 HpGaugeOfst;
        COLOR collisionColor;
        COLOR normalColor;
        COLOR color;

    };
private:
    DATA Animal;
public:
    ANIMAL(class GAME* game);
    void create();
    void init();
    void update();
     void move();
     void collision();
    void draw();
    int hp() { return Animal.hp; }
};

