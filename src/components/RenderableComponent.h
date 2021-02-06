#pragma once

#include "../ActorComponent.h";

class RenderableComponent : public ActorComponent
{
public:
	virtual void draw();
};
