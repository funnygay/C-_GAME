#include "SettingScene.h"

USING_NS_CC;
Scene *Setting::createScene()
{
	auto scene = Scene::create();

	auto layer = Setting::create();

	scene->addChild(layer);

	return scene;
}
bool Setting::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	Sprite *bg = Sprite::create("menu.png");
	bg->setPosition(Point(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2));
	this->addChild(bg);

	//ÒôÐ§  
	auto soundOnMenuItem = MenuItemImage::create(
		"menu.png",
		"menu.png");
	auto soundOffMenuItem = MenuItemImage::create(
		"menu.png",
		"menu.png");

	auto soundToggleMenuItem = MenuItemToggle::createWithCallback(
		CC_CALLBACK_1(Setting::menuSoundToggleCallback, this),
		soundOnMenuItem,
		soundOffMenuItem,
		NULL);
	soundToggleMenuItem->setPosition(Director::getInstance()->convertToGL(Point(818, 220)));

	//ÒôÀÖ  
	auto musicOnMenuItem = MenuItemImage::create(
		"menu.png",
		"menu.png");
	auto musicOffMenuItem = MenuItemImage::create(
		"menu.png",
		"menu.png");
	auto musicToggleMenuItem = MenuItemToggle::createWithCallback(
		CC_CALLBACK_1(Setting::menuMusicToggleCallback, this),
		musicOnMenuItem,
		musicOffMenuItem,
		NULL);
	musicToggleMenuItem->setPosition(Director::getInstance()->convertToGL(Point(818, 362)));

	//Ok°´Å¥  
	auto okMenuItem = MenuItemImage::create(
		"menu.png",
		"menu.png",
		CC_CALLBACK_1(Setting::menuOkCallback, this));

	okMenuItem->setPosition(Director::getInstance()->convertToGL(Point(600, 510)));

	Menu* mn = Menu::create(soundToggleMenuItem,
		musicToggleMenuItem, okMenuItem, NULL);
	mn->setPosition(Point::ZERO);
	this->addChild(mn);

	return true;
}

void Setting::menuOkCallback(Ref*pSender)
{
	Director::getInstance()->popScene();
}
void Setting::menuSoundToggleCallback(Ref*pSender)
{}
void Setting::menuMusicToggleCallback(Ref*pSender)
{}

