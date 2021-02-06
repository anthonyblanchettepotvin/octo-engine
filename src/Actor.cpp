#include "Actor.h"

void Actor::addComponent(ActorComponent* component)
{
	if (component == nullptr) throw invalid_argument("component pointer is null");

	auto& it = this->components.find(component);

	if (it == this->components.end())
	{
		this->components.insert(it, component);
	}
	else
	{
		throw invalid_argument("component already exists");
	}
}

void Actor::removeComponent(ActorComponent* component)
{
	if (component == nullptr) throw invalid_argument("component pointer is null");

	auto& it = this->components.find(component);

	if (it != this->components.end())
	{
		this->components.erase(it);
	}
	else
	{
		throw invalid_argument("component doesn't exists");
	}
}
