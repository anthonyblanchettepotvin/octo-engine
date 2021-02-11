#include "Scene.h"

#include "components/RenderableComponent.h"

Scene::Scene(SceneRenderer* renderer) : renderer(renderer)
{

}

void Scene::setup()
{
	if (this->renderer != nullptr)
	{
		this->renderer->setup();
	}
}

void Scene::draw()
{
	vector<RenderableComponent*> components;

	for (auto& it = this->actors.begin(); it != this->actors.end(); it++)
	{
		vector<RenderableComponent*> renderables = (*it)->getComponents<RenderableComponent>();

		components.insert(components.begin(), renderables.begin(), renderables.end());
	}

	if (this->renderer != nullptr)
	{
		this->renderer->draw(components);
	}
}

void Scene::addImage(ofImage* image)
{
	if (image == nullptr) throw invalid_argument("image pointer is null");

	auto& it = this->images.find(image);

	if (it == this->images.end())
	{
		this->images.insert(it, image);

		this->onImageAdded.notify(*image);
	}
	else
	{
		throw invalid_argument("image already exists");
	}
}

void Scene::deleteImage(ofImage* image)
{	
	if (image == nullptr) throw invalid_argument("image pointer is null");

	auto& it = this->images.find(image);

	if (it != this-> images.end())
	{
		this->images.erase(it);
	}
	else
	{
		throw invalid_argument("image doesn't exists");
	}

	delete image;
}

set<ofImage*> Scene::getImages() const
{
	return this->images;
}

void Scene::addActor(Actor* actor)
{
	if (actor == nullptr) throw invalid_argument("actor pointer is null");

	auto& it = this->actors.find(actor);

	if (it == this->actors.end())
	{
		this->actors.insert(it, actor);

		this->onActorAdded.notify(*actor);
	}
	else
	{
		throw invalid_argument("actor already exists");
	}
}

void Scene::deleteActor(Actor* actor)
{
	if (actor == nullptr) throw invalid_argument("actor pointer is null");

	auto& it = this->actors.find(actor);

	if (it != this->actors.end())
	{
		this->actors.erase(it);
	}
	else
	{
		throw invalid_argument("actor doesn't exists");
	}

	delete actor;
}

set<Actor*> Scene::getActors() const
{
	return this->actors;
}

ofImage* Scene::getFirstImage()
{
	auto& it = this->images.begin();

	return *it;
}
