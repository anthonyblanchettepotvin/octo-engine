#pragma once

#include "ofMain.h"
#include "ActorComponent.h"

class Actor
{
public:
	void addComponent(ActorComponent* component);
	void removeComponent(ActorComponent* component);

private:
	set<ActorComponent*> components;
};
