#include "MainMenuScene.h"
#include "Definitions.h"
#include "GameScene.h"
#include "LvlDifficult.h"
#include "Authors.h"
USING_NS_CC;

Scene* MainMenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainMenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto backgroundSprite = Sprite::create( "bg.jpg" );
    backgroundSprite->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y ) );
    
    this->addChild( backgroundSprite );
    

    
    auto playItem = MenuItemImage::create( "Play.png", "PlayClick.png", CC_CALLBACK_1( MainMenuScene::GoToGameScene, this ) );
	auto authors = MenuItemImage::create("Ball.png"," ", CC_CALLBACK_1(MainMenuScene::GoToAuthors, this));
    playItem->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y ) );
	authors->setPosition(Point(visibleSize.width , 0 ));
	authors->setAnchorPoint(Vec2(1, 0));
	authors->setScale(2);
    auto menu = Menu::create( playItem, authors,NULL );
    menu->setPosition( Point::ZERO );
    
    this->addChild( menu );
    
    return true;
}

void MainMenuScene::GoToGameScene( cocos2d::Ref *sender )
{
    auto scene = LvlDifficult::createScene();
    
    Director::getInstance( )->replaceScene( TransitionFade::create( TRANSITION_TIME, scene ) );
}
void MainMenuScene::GoToAuthors(cocos2d::Ref *sender)
{
	auto scene = Authors::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}




