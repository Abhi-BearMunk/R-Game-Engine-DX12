#pragma once
#include <memory>
#include <string>
#include "../Core/RComponent.h"

class R::REntity;
class TestComponent :
	public R::RComponent
{
public:
	TestComponent(const std::weak_ptr<R::REntity> _entity, const std::string& _name, const int& _max = 10);
	virtual void Start() override;
	virtual void Update() override;
private:
	std::string name;
	int n = 0;
	int max;
};

