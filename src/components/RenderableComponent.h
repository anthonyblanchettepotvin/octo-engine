#pragma once

#include "ofMain.h"
#include "../ActorComponent.h";

class RenderableComponent : public ActorComponent
{
public:
	virtual void draw(ofShader& shader);
};
