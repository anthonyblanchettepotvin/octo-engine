#include "Actor.h"

Actor::Actor()
{
	this->transformComponent = new TransformComponent();

	this->registerComponent(this->transformComponent);
}

Actor::~Actor()
{
	this->unregisterComponent(this->transformComponent);

	delete this->transformComponent;

	for (auto& it = this->components.begin(); it != this->components.end(); it++)
	{
		this->unregisterComponent(*it);

		delete *it;
	}
}

TransformComponent* Actor::getTransformComponent() const
{
	return this->transformComponent;
}

void Actor::addComponent(ActorComponent* component)
{
	if (component == nullptr) throw invalid_argument("component pointer is null");

	auto& it = this->components.find(component);

	if (it == this->components.end())
	{
		this->components.insert(it, component);

		this->registerComponent(component);
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

		this->unregisterComponent(component);

		delete component;
	}
	else
	{
		throw invalid_argument("component doesn't exists");
	}
}

void Actor::registerComponent(ActorComponent* component)
{
	if (component == nullptr) throw invalid_argument("component pointer is null");

	component->setOwner(this);

	component->onComponentRegistered();
}

void Actor::unregisterComponent(ActorComponent* component)
{
	if (component == nullptr) throw invalid_argument("component pointer is null");

	component->setOwner(nullptr);

	component->onComponentUnregistered();
}
