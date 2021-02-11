#include "ActorComponent.h"

void ActorComponent::onComponentRegistered()
{

}

void ActorComponent::onComponentUnregistered()
{

}

Actor* ActorComponent::getOwner() const
{
	return this->owner;
}

void ActorComponent::setOwner(Actor* owner)
{
	this->owner = owner;
}
