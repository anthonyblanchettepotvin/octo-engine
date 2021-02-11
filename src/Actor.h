#pragma once

#include "ofMain.h"
#include "ActorComponent.h"
#include "components/TransformComponent.h"

class Actor
{
public:
	Actor();
	~Actor();

	TransformComponent* getTransformComponent() const;

	template <class T>
	T* getComponent();

	template <class T>
	vector<T*> getComponents();

	void addComponent(ActorComponent* component);
	void removeComponent(ActorComponent* component);

private:
	void registerComponent(ActorComponent* component);
	void unregisterComponent(ActorComponent* component);

	TransformComponent* transformComponent = nullptr;
	set<ActorComponent*> components;
};

template<class T>
inline vector<T*> Actor::getComponents()
{
	vector<T*> components;

	for (auto& it = this->components.begin(); it != this->components.end(); it++) {
		if (T* component = dynamic_cast<T*>(*it)) {
			components.push_back(component);
		}
	}

	return components;
}

template<class T>
inline T* Actor::getComponent()
{
	for (auto& it = this->components.begin(); it != this->components.end(); it++) {
		if (T* component = dynamic_cast<T*>(*it)) {
			return component;
		}
	}
}
