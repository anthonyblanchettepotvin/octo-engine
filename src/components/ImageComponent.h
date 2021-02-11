#pragma once

#include "ofMain.h"
#include "RenderableComponent.h"

class ImageComponent : public RenderableComponent
{
public:
	ImageComponent(ofImage* image);

	virtual void draw(ofShader& shader);

private:
	ofImage* image = nullptr;
};
