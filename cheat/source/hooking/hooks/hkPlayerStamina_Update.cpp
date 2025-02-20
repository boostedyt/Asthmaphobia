#include "source/common.h"
#include "source/feature/movement/infinitestamina/infinitestamina.h"
#include "source/hooking/hooking.h"

using namespace Asthmaphobia;

void Hooks::hkPlayerStamina_Update(SDK::PlayerStamina* playerStamina, SDK::MethodInfo* methodInfo)
{
	LOG_DEBUG("Called PlayerStamina_Update");
	if (globalRunning)
		dynamic_cast<Features::Movement::InfiniteStamina*>(featureManager->GetFeatureByName("Movement::InfiniteStamina"))->OnPlayerStamina_Update(playerStamina, methodInfo);

	SDK::PlayerStamina_Update_ptr(playerStamina, methodInfo);
}
