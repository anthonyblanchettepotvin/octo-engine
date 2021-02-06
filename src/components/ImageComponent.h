#pragma once

#include "ofMain.h"
#include "RenderableComponent.h"

class ImageComponent : public RenderableComponent
{
public:
	ImageComponent(ofImage* image);

	void draw();

private:
	ofImage* image = nullptr;
};
