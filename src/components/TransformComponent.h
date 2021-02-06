#pragma once

#include "ofMain.h"
#include "ofMath.h"
#include "../ActorComponent.h"

class TransformComponent : public ActorComponent
{
public:
	ofVec3f getPosition() const;
	void setPosition(const ofVec3f& position);
	ofVec3f getRotation() const;
	void setRotation(const ofVec3f& rotation);
	ofVec3f getScale() const;
	void setScale(const ofVec3f& scale);

private:
	ofVec3f position = { 0.0f, 0.0f, 0.0f };
	ofVec3f rotation = { 0.0f, 0.0f, 0.0f };
	ofVec3f scale = { 0.0f, 0.0f, 0.0f };
};
