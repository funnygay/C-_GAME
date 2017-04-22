#include "MyActionScene.h"  

USING_NS_CC;

Scene* MyAction::createScene()
{
	// 'scene' is an autorelease object  
	auto scene = Scene::create();

	// 'layer' is an autorelease object  
	auto layer = MyAction::create();

	// add layer as a child to scene  
	scene->addChild(layer);

	// return the scene  
	return scene;
}

// on "init" you need to initialize your instance  
bool MyAction::init()
{
	//////////////////////////////  
	// 1. super init first  
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto bg = Sprite::create("background2.png");
	bg->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(bg);

	sprite = Sprite::create("Plane.png");
	sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(sprite);

	auto backMenuItem = MenuItemImage::create("return1.png", "return2.png", CC_CALLBACK_1(MyAction::backMenu, this));
	backMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(200, 200)));

	auto goMenuItem = MenuItemImage::create("go1.png", "go1.png", CC_CALLBACK_1(MyAction::goMenu, this));
	goMenuItem->setPosition(visibleSize.width / 2, 200);

	Menu* mn = Menu::create(backMenuItem, goMenuItem, NULL);

	mn->setPosition(Vec2::ZERO);
	this->addChild(mn);

	this->hiddenFlag = true;//¾«ÁéÒþ²Ø  

	return true;
}

void MyAction::backMenu(Ref* pSender)
{
	auto sc = Settings::createScene();
	auto reScene = TransitionSlideInL::create(1.0f, sc);
	Director::getInstance()->replaceScene(reScene);

}


void MyAction::goMenu(Ref* pSender)
{
	log("Tag = %i", this->getTag());
	Size size = Director::getInstance()->getVisibleSize();
	Vec2 p = Vec2(CCRANDOM_0_1() * size.width, CCRANDOM_0_1() * size.height);

	switch (this->getTag())
	{
	case PUSH:
		sprite->runAction(Place::create(p));
		break;
	
	case HIDE_SHOW_TAG:
		if (hiddenFlag) 
		{
			sprite->runAction(Hide::create());
			hiddenFlag = false;
		}
		else {
			sprite->runAction(Show::create());
			hiddenFlag = true;
		}
		break;
	
	default:
		break;
	}

}
