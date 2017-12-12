#include "Authors.h"
#include "MainMenuScene.h"
#include "Definitions.h"
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

	

	auto Pashkevuch = Label::createWithTTF("Pashkevuch Oleksiy: Sound Manager", "fonts/Marker Felt.ttf", 24);
	Pashkevuch->setPosition(Point(0, visibleSize.height / 5 * 1 + origin.y));
	//Pashkevuch->setColor(Color3B::MAGENTA);
	authors->addChild(Pashkevuch);

	auto kukjak = Label::createWithTTF("Kukjak Andriy: Developer", "fonts/Marker Felt.ttf", 24);
	kukjak->setPosition(Point(0, visibleSize.height / 5 * 2 + origin.y));
	authors->addChild(kukjak);


	auto Matiiv =  Label::createWithTTF("Matiiv Vasyl: Developer", "fonts/Marker Felt.ttf", 24);
	Matiiv->setPosition(Point(0,visibleSize.height/ 5*3 + origin.y));
	authors->addChild(Matiiv);

	auto Lupak = Label::createWithTTF("Lupak Sergiy: Developer", "fonts/Marker Felt.ttf", 24);
	Lupak->setPosition(Point(0, visibleSize.height / 5 * 4 + origin.y));
	authors->addChild(Lupak);

	auto Pavluchynskyi = Label::createWithTTF("Pavluchynskyi Vladuslav: Designer", "fonts/Marker Felt.ttf", 24);
	Pavluchynskyi->setPosition(Point(0, visibleSize.height / 5 * 5 + origin.y));
	authors->addChild(Pavluchynskyi);

	auto Created = Label::createWithTTF("Created by:", "fonts/Marker Felt.ttf", 24);
	Created->setPosition(Point(0, visibleSize.height / 5 * 6 + origin.y));
	authors->addChild(Created);
	auto move = MoveBy::create(5,Vec2(0,visibleSize.height));
	
	authors->runAction(move);
	this->addChild(authors);

	auto listener1 = EventListenerTouchOneByOne::create();
	listener1->setSwallowTouches(true);
	listener1->onTouchBegan = CC_CALLBACK_2(Authors::backToMainMenu, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener1, this);

	return true;
}
bool Authors::backToMainMenu(cocos2d::Touch *touch, cocos2d::Event *event) {
	auto scene = MainMenuScene::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
	return true;
}