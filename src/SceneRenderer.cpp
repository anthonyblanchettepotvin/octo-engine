#include "SceneRenderer.h"

void SceneRenderer::setup()
{
	// setup rendered
	ofDisableArbTex();

	// load shaders
	this->shader.load(
		"shaders/passthrough_330_vs.glsl",
		"shaders/passthrough_330_fs.glsl");
}

void SceneRenderer::draw(const vector<RenderableComponent*> components)
{
	if (this->shader.isLoaded())
	{
		this->shader.begin();

		for (auto it = components.begin(); it != components.end(); it++)
		{
			(*it)->draw(this->shader);
		}

		this->shader.end();
	}
}
