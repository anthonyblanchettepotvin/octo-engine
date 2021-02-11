#pragma once

#include "ofMain.h"
#include "components/RenderableComponent.h"

class SceneRenderer
{
public:
	void setup();
	void draw(const vector<RenderableComponent*> components);

private:
	ofShader shader;
};
