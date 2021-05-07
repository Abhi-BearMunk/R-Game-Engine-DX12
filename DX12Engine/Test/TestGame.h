#pragma once
#include <memory>
#include "../Core/RGame.h"

class TestGame :
	public R::RGame
{
protected:
	virtual void Setup() override;
};

