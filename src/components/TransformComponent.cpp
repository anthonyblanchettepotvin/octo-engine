#include "TransformComponent.h"

ofVec3f TransformComponent::getPosition() const
{
	return this->position;
}

void TransformComponent::setPosition(const ofVec3f& position)
{
	this->position = position;
}

ofVec3f TransformComponent::getRotation() const
{
	return this->rotation;
}

void TransformComponent::setRotation(const ofVec3f& rotation)
{
	this->rotation = rotation;
}

ofVec3f TransformComponent::getScale() const
{
	return this->scale;
}

void TransformComponent::setScale(const ofVec3f& scale)
{
	this->scale = scale;
}
