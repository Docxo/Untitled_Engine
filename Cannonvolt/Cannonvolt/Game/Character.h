#pragma once
#include "../Engine/Rendering/2D/GameObject.h"

class Character : public GameObject {
public:
	Character();
	virtual ~Character();

	virtual bool OnCreate();
	virtual void Update(const float deltaTime_) override;

};