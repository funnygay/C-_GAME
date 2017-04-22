


#ifndef __SETTINGS_SCENE_H__
#define __SETTINGS_SCENE_H__

#include "cocos2d.h"


class Settings : public cocos2d::Layer
{
public:

	static cocos2d::Scene* createScene();


	virtual bool init();



	void menuBeginCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(Settings);
};

#endif

