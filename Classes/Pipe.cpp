#include "Pipe.h"
#include "Definitions.h"

USING_NS_CC;

Pipe::Pipe( )
{
    visibleSize = Director::getInstance( )->getVisibleSize( );
    origin = Director::getInstance( )->getVisibleOrigin( );
}

void Pipe::SpawnPipe( cocos2d::Layer *layer )
{
    
    auto topPipe = Sprite::create( "Ball.png" );
    auto bottomPipe = Sprite::create( "Ball.png" );
    
    auto topPipeBody = PhysicsBody::createBox( topPipe->getContentSize( ) );
    auto bottomPipeBody = PhysicsBody::createBox( bottomPipe->getContentSize( ) );
    
    auto random = CCRANDOM_0_1( );
    
    if ( random < LOWER_SCREEN_PIPE_THRESHOLD )
    {
        random = LOWER_SCREEN_PIPE_THRESHOLD;
    }
    else if ( random > UPPER_SCREEN_PIPE_THRESHOLD )
    {
        random = UPPER_SCREEN_PIPE_THRESHOLD;
    }
    
    auto topPipePosition = ( random * visibleSize.height ) + ( topPipe->getContentSize( ).height / 2 );
    
    topPipeBody->setDynamic( false );
    bottomPipeBody->setDynamic( false );
    
    topPipeBody->setCollisionBitmask( OBSTACLE_COLLISION_BITMASK );
    bottomPipeBody->setCollisionBitmask( OBSTACLE_COLLISION_BITMASK );
    topPipeBody->setContactTestBitmask( true );
    bottomPipeBody->setContactTestBitmask( true );
    
    topPipe->setPhysicsBody( topPipeBody );
    bottomPipe->setPhysicsBody( bottomPipeBody );
    
    topPipe->setPosition( Point( visibleSize.width + topPipe->getContentSize( ).width + origin.x, topPipePosition ) );
    bottomPipe->setPosition( Point( topPipe->getPositionX(), topPipePosition - ( Sprite::create( "Ball.png" )->getContentSize( ).height * PIPE_GAP ) - topPipe->getContentSize().height ) );
    
    layer->addChild( topPipe );
    layer->addChild( bottomPipe );
    
    auto topPipeAction = MoveBy::create( PIPE_MOVEMENT_SPEED * visibleSize.width, Point( -visibleSize.width * 1.5, 0 ) );
    auto bottomPipeAction = MoveBy::create( PIPE_MOVEMENT_SPEED * visibleSize.width, Point( -visibleSize.width * 1.5, 0 ) );
    
    topPipe->runAction( topPipeAction );
    bottomPipe->runAction( bottomPipeAction );
    
    auto pointNode = Node::create( );
    auto pointBody = PhysicsBody::createBox( Size( 1, Sprite::create( "Ball.png" )->getContentSize( ).height * PIPE_GAP ) );
    
    pointBody->setDynamic( false );
    pointBody->setCollisionBitmask( POINT_COLLISION_BITMASK );
    pointBody->setContactTestBitmask( true );
    
    pointNode->setPhysicsBody( pointBody );
//	pointNode->setAnchorPoint(Vec2(0, 0));
    pointNode->setPosition( Point( topPipe->getPositionX( ), topPipe->getPositionY( ) -  ( topPipe->getContentSize( ).height/2 ) - ( ( Sprite::create( "Ball.png" )->getContentSize( ).height * PIPE_GAP ) /2 ) ) );
    
    layer->addChild( pointNode );


	auto topPointNode = Node::create();
	auto topPointBody = PhysicsBody::createBox(Size(1, Sprite::create("Ball.png")->getContentSize().height * MINUS_PIPE_GAP));

	topPointBody->setDynamic(false);
	topPointBody->setCollisionBitmask(MINUS_POINT_COLLISION_BITMASK);
	topPointBody->setContactTestBitmask(true);

	topPointNode->setPhysicsBody(topPointBody);
	 //	pointNode->setAnchorPoint(Vec2(0, 0));
	topPointNode->setPosition(Point(topPipe->getPositionX(), topPipe->getPositionY() + (topPipe->getContentSize().height / 2) + ((Sprite::create("Ball.png")->getContentSize().height * MINUS_PIPE_GAP) / 2)));

	layer->addChild(topPointNode);

	auto botPointNode = Node::create();
	auto botPointBody = PhysicsBody::createBox(Size(1, Sprite::create("Ball.png")->getContentSize().height * MINUS_PIPE_GAP));

	botPointBody->setDynamic(false);
	botPointBody->setCollisionBitmask(MINUS_POINT_COLLISION_BITMASK);
	botPointBody->setContactTestBitmask(true);

	botPointNode->setPhysicsBody(botPointBody);
	//	pointNode->setAnchorPoint(Vec2(0, 0));
	botPointNode->setPosition(Point(bottomPipe->getPositionX(), bottomPipe->getPositionY() - (bottomPipe->getContentSize().height / 2) - ((Sprite::create("Ball.png")->getContentSize().height * MINUS_PIPE_GAP) / 2)));

	layer->addChild(botPointNode);

	auto botPointNodeAction = MoveBy::create(PIPE_MOVEMENT_SPEED * visibleSize.width, Point(-visibleSize.width * 1.5, 0));
	botPointNode->runAction(botPointNodeAction);


	auto topPointNodeAction = MoveBy::create(PIPE_MOVEMENT_SPEED * visibleSize.width, Point(-visibleSize.width * 1.5, 0));
	topPointNode->runAction(topPointNodeAction);

    auto pointNodeAction = MoveBy::create( PIPE_MOVEMENT_SPEED * visibleSize.width, Point( -visibleSize.width * 1.5, 0 ) );
//	topPointNode->runAction(pointNodeAction);
    pointNode->runAction( pointNodeAction );
	
}







