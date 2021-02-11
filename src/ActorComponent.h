#pragma once

class Actor;

class ActorComponent
{
public:
	Actor* getOwner() const;

protected:
	virtual void onComponentRegistered();
	virtual void onComponentUnregistered();

private:
	void setOwner(Actor* owner);

	Actor* owner = nullptr;

	friend class Actor;
};
