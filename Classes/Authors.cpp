#include "Authors.h"

USING_NS_CC;

Scene* Authors::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Authors::create();

	// add layer as a child to scene
	scene->addChild(layer);


	return scene;
}

// on "init" you need to initialize your instance
bool Authors::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	                                                                                         
	auto authors = Label::createWithTTF(" ","fonts/Marker Felt.ttf",24);
	authors->setPosition(Point( visibleSize.width/2 + origin.x , -(visibleSize.height / 5 * 5 + origin.y)));

	auto kukjak =  Label::createWithTTF("Kukjak: Bank meneger", "fonts/Marker Felt.ttf", 24);
	kukjak->setPosition(Point(0 , visibleSize.height/5*1 + origin.y));
	authors->addChild(kukjak);


	auto Pashkevuch = Label::createWithTTF("Pashkevuch: Pidar", "fonts/Marker Felt.ttf", 24);
	Pashkevuch->setPosition(Point(0, visibleSize.height / 5 * 2 + origin.y));
	Pashkevuch->setColor(Color3B::MAGENTA);
	authors->addChild(Pashkevuch);

	auto Matiiv =  Label::createWithTTF("Matiiv: :(", "fonts/Marker Felt.ttf", 24);
	Matiiv->setPosition(Point(0,visibleSize.height/ 5*3 + origin.y));
	authors->addChild(Matiiv);

	auto Lupak = Label::createWithTTF("Lupak: Lupak", "fonts/Marker Felt.ttf", 24);
	Lupak->setPosition(Point(0, visibleSize.height / 5 * 4 + origin.y));
	Lupak->setColor(Color3B::YELLOW);
	authors->addChild(Lupak);

	auto Pavluchynskyi = Label::createWithTTF("Pavluchynskyi: Designer", "fonts/Marker Felt.ttf", 24);
	Pavluchynskyi->setPosition(Point(0, visibleSize.height / 5 * 5 + origin.y));
	authors->addChild(Pavluchynskyi);
	auto move = MoveBy::create(5,Vec2(0,visibleSize.height));
	
	authors->runAction(move);
	this->addChild(authors);

	return true;
}
