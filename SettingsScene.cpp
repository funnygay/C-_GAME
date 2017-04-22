#include "SettingsScene.h"

USING_NS_CC;
Scene *Settings::createScene()
{
	auto scene = Scene::create();

	auto layer = Settings::create();

	scene->addChild(layer);

	return scene;
}
bool Settings::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	Sprite *bg = Sprite::create("background2.png");
	bg->setPosition(Point(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2));
	this->addChild(bg);

	
	auto okMenuItem = MenuItemImage::create(
		"return1.png",
		"return2.png",
		CC_CALLBACK_1(Settings::menuBeginCallback, this));

	okMenuItem->setPosition(Director::getInstance()->convertToGL(Point(300, 190)));

	Menu* mn = Menu::create(
		 okMenuItem, NULL);
	mn->setPosition(Point::ZERO);
	this->addChild(mn);

	auto label = LabelTTF::create("Setting Page", "Arial", 24);
	label->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - label->getContentSize().height));
	this->addChild(label, 1);

	return true;
}

void Settings::menuBeginCallback(Ref*pSender)
{
	Director::getInstance()->popScene();
}



