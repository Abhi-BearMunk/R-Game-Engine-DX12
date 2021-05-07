#pragma once
#include <memory>
#include <list>
#include <vector>
#include <algorithm>

namespace R
{
	//class RWindow;
	class REntity;

	class RGame
	{
	private:
		//RWindow* gameWindow = nullptr;


		bool isRunning = true;
		void ProcessGlobalInputs();

		std::list<std::shared_ptr<REntity>> entities;
		std::list<std::weak_ptr<REntity>> dyingEntities;
		void KillDyingEntities();
	public:
		RGame();
		// Game loop
		bool Init();
		void Update();
		void Quit();
		const bool& GetIsRunning() const;

		// EC
		std::weak_ptr<REntity> CreateEntity();
		void KillEntity(std::weak_ptr<REntity> entity);

		// Rendering
		//inline RWindow& GetGameWindow() const { return *gameWindow; }

	protected:
		virtual void Setup() = 0;
	};
}

