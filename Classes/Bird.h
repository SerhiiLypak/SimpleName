#ifndef __BIRD_H__
#define __BIRD_H__

#include "cocos2d.h"
class Bird
{
public:
    Bird( cocos2d::Layer *layer );
    
    void Fall( );
    void Fly( ) { isFalling = false; };
    void StopFlying( ) { isFalling = true; }
	
	cocos2d::Sprite *flappyBird;
private:
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    

    bool isFalling;
    
};

#endif // __BIRD_H__
