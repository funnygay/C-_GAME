#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include"SettingScene.h"
#include"SettingsScene.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	Sprite *bg = Sprite::create("background.png");
	bg->setPosition(Point(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2));
	this->addChild(bg);

	//¿ªÊ¼¾«Áé  
	Sprite *startSpriteNormal = Sprite::create("begin.png");
	Sprite *startSpriteSelected = Sprite::create("pause.png");






	MenuItemSprite*startMenuItem = MenuItemSprite::create(startSpriteNormal,
		startSpriteSelected,
		CC_CALLBACK_1(HelloWorld::menuItemStartCallback, this));
	startMenuItem->setPosition(Director::getInstance()->convertToGL(Point(200, 200)));



	MenuItemImage *beginMenuItem = MenuItemImage::create(
		"start.png",
		"start2.png",
		CC_CALLBACK_1(HelloWorld::menuItemBeginCallback, this));
	beginMenuItem->setPosition(Director::getInstance()->convertToGL(Point(250, 150)));
	//ÉèÖÃÍ¼Æ¬²Ëµ¥  
	MenuItemImage *settingMenuItem = MenuItemImage::create(
		"shezhi1.png",
		"shezhi2.png",
		CC_CALLBACK_1(HelloWorld::menuItemSettingCallback, this));
	settingMenuItem->setPosition(Director::getInstance()->convertToGL(Point(250, 200)));

	//°ïÖúÍ¼Æ¬²Ëµ¥  
	MenuItemImage *helpMenuItem = MenuItemImage::create(
		"help.png",
		"help2.png",
		CC_CALLBACK_1(HelloWorld::menuItemHelpCallback, this));
	helpMenuItem->setPosition(Director::getInstance()->convertToGL(Point(300, 200)));


	MenuItemImage *quitMenuItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
	quitMenuItem->setPosition(Director::getInstance()->convertToGL(Point(400, 200)));

	Menu * mu = Menu::create(beginMenuItem,startMenuItem, settingMenuItem, helpMenuItem,quitMenuItem, NULL);
	mu->setPosition(Point::ZERO);
	this->addChild(mu);


	auto label = LabelTTF::create("My First Game", "Arial", 24);
	label->setTag(123);
	this->scheduleUpdate();

	label->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height  - label->getContentSize().height));
	this->addChild( label , 1);

	return true;
}



void HelloWorld::update(float dt)
{
	auto label = this->getChildByTag(123);
	label->setPosition(label->getPosition() + Vec2(1, 0));
}


void HelloWorld::menuItemSettingCallback(Ref* pSender)
{
	
	//Director::getInstance()->replaceScene(sc);                                                                                  
	Director::getInstance()->pushScene(Setting::createScene());
}



void HelloWorld::menuItemBeginCallback(Ref*pSender)
{
	Director::getInstance()->pushScene(Settings::createScene());
}


void HelloWorld::menuItemHelpCallback(Ref*pSender)
{
	MenuItem* item = (MenuItem*)pSender;
	log("Touch Help %p", item);
}

void HelloWorld::menuItemStartCallback(Ref*pSender)
{
	MenuItem* item = (MenuItem*)pSender;
	log("Touch Start %p", item);
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
	unscheduleUpdate();
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    
}
