#include "REntity.h"
#include "REntity.h"
#include "RComponent.h"
#include "RGame.h"

namespace R
{
	REntity::REntity(RGame& _game)
		:game(_game)
	{
	}

	void REntity::Start()
	{
		std::for_each(components.begin(), components.end(),
			[](const auto& component) {component->Start(); });
	}

	void REntity::Update()
	{
		std::for_each(components.begin(), components.end(),
			[](const auto& component) {component->Update(); });
	}

	void REntity::Kill()
	{
		game.KillEntity(self);
	}
}

