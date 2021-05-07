#include "TestGame.h"
#include "TestComponent.h"
#include "../Core/REntity.h"

#define RANDOM(a,b) a + std::rand() * (b - a) / RAND_MAX

void TestGame::Setup()
{
	for (int i = 0; i < 10000; i++)
	{
		CreateEntity().lock()->AddComponent<TestComponent>("My Test Component");
	}
}


