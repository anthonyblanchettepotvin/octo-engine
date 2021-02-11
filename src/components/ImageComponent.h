#pragma once

#include "ofMain.h"
#include "RenderableComponent.h"

class ImageComponent : public RenderableComponent
{
public:
	ImageComponent(ofImage* image);

	virtual void draw();

private:
	ofShader shader;

	ofImage* image = nullptr;
};
