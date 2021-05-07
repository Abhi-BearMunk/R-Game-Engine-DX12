#include "RComponent.h"
#include "REntity.h"

namespace R
{
	RComponent::RComponent(const std::weak_ptr<REntity> _entity)
		:entity(_entity)
	{
	}

	RComponent::~RComponent()
	{
	}

	const RGame& RComponent::GetGame() const
	{
		return entity.lock()->GetGame();
	}
}