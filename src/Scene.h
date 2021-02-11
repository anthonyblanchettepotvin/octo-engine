#pragma once

#include "ofMain.h"
#include "SceneRenderer.h"
#include "Actor.h";

class Scene
{
public:
	Scene(SceneRenderer* renderer);

	void setup();
	void draw();

	void addImage(ofImage* image);
	void deleteImage(ofImage* image);
	set<ofImage*> getImages() const;

	void addActor(Actor* actor);
	void deleteActor(Actor* actor);
	set<Actor*> getActors() const;

	ofImage* getFirstImage();

	ofEvent<ofImage> onImageAdded;
	ofEvent<Actor> onActorAdded;

private:
	SceneRenderer* renderer = nullptr;

	set<ofImage*> images;
	set<Actor*> actors;
};
