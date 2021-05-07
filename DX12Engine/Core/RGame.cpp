#include <algorithm>
#include <iostream>
#include "RGame.h"
//#include "RWindow.h"
#include "REntity.h"

namespace R
{
	RGame::RGame()
	{
	}

	std::weak_ptr<REntity> RGame::CreateEntity()
	{
		auto entity = std::make_shared<REntity>(*this);
		entity->SetSelf(entity);
		entities.push_back(entity);
		return entity;
	}

	void RGame::KillEntity(std::weak_ptr<REntity> entity)
	{
		dyingEntities.push_back(entity);
	}

	void RGame::KillDyingEntities()
	{
		std::for_each(dyingEntities.begin(), dyingEntities.end(),
			[this](std::weak_ptr<REntity> entity) {
				entities.remove(entity.lock());
			});
		dyingEntities.clear();
	}

	bool RGame::Init()
	{
		// Create Window
		/*if (!gameWindow->Init())
		{
			return false;
		}*/

		// Create entities etc.
		Setup();

		// Start Entities;
		std::for_each(entities.begin(), entities.end(),
			[](const auto& entity) {entity->Start(); });

		return true;
	}

	void RGame::Update()
	{
		// Rendering
		//gameWindow->PreUpdate();

		// GamePlay
		ProcessGlobalInputs();
		std::for_each(entities.begin(), entities.end(),
			[](const auto& entity) {entity->Update(); });

		auto showmessage = entities.size() > 0;
		//gameWindow->PostProcess();
		//gameWindow->FinishUpdate();
		KillDyingEntities();
		//isRunning = !glfwWindowShouldClose(gameWindow->window);

		if (showmessage)
		{
			std::cout << "Num entities = " << entities.size() << "\n";
		}
	}

	void RGame::Quit()
	{
		//glfwSetWindowShouldClose(gameWindow->window, true);
	}

	const bool& RGame::GetIsRunning() const
	{
		return isRunning;
	}


	void RGame::ProcessGlobalInputs()
	{

	}
}
