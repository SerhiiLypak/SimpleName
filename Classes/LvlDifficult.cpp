#include "LvlDifficult.h"
#include "Definitions.h"
#include "GameScene.h"
USING_NS_CC;

Scene* LvlDifficult::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = LvlDifficult::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool LvlDifficult::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backgroundSprite = Sprite::create("bg.jpg");
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(backgroundSprite);



	


	auto easy = MenuItemImage::create("Easy.png","EasyClick.png ", CC_CALLBACK_1(LvlDifficult::Easy, this));
	auto hard = MenuItemImage::create("Hard.png","HardClick.png", CC_CALLBACK_1(LvlDifficult::Hard, this));
	auto insane = MenuItemImage::create("Insane.png","InsaneClick.png", CC_CALLBACK_1(LvlDifficult::Insane, this));
	easy->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y+30));
	hard->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2.2 + origin.y));
	insane->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2.4 + origin.y-30));

	


	auto menu = Menu::create(easy, hard, insane,  NULL);
	menu->setPosition(Point::ZERO);

	this->addChild(menu);
	
	//this->scheduleUpdate();

	return true;
}

void LvlDifficult::Easy(cocos2d::Ref *sender) {
	sc = 0;
	auto scene = GameScene::createScene(sc );
	Director::getInstance()->replaceScene(scene);
}
void LvlDifficult::Hard(cocos2d::Ref *sender) {
	sc = 1;
	auto scene = GameScene::createScene(sc );
	Director::getInstance()->replaceScene(scene);
}
void LvlDifficult::Insane(cocos2d::Ref *sender) {
	sc = 2;
	auto scene = GameScene::createScene(sc);
	Director::getInstance()->replaceScene(scene);
}




