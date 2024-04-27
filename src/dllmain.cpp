#include "Utils.h"
#include "ScriptManager.h"
#include "Controllers/PickupController.h"
#include "Controllers/PlayerController.h"

void OnScriptInit()
{
    using namespace revenant;

    g_Logger = std::make_unique<Logger>();
    g_Logger->Info("Revenant has been initialised.");

    InitialiseAllComponents();

    g_ScriptManager = std::make_unique<ScriptManager>();
    g_PickupController = std::make_unique<PickupController>();
    g_PlayerController = std::make_unique<PlayerController>();
    g_ScriptManager->AddScript(g_PickupController);
    g_ScriptManager->AddScript(g_PlayerController);

    // Wait for the game to finish loading before we continue.
    while (DLC::GET_IS_LOADING_SCREEN_ACTIVE())
        WAIT(500);

    while (g_Running)
    {
        WAIT(0);

        g_ScriptManager->OnTick();
    }

    g_ScriptManager.reset();
    g_PickupController.reset();
    g_PlayerController.reset();

    g_Logger->Info("Revenant has been terminated.");
    g_Logger.reset();
}

bool __stdcall DllMain(HINSTANCE hInstance, DWORD reason, LPVOID reserved)
{
    using namespace revenant;

    switch (reason)
    {
        case DLL_PROCESS_ATTACH:
            scriptRegister(hInstance, OnScriptInit);
            break;
        case DLL_PROCESS_DETACH:
            scriptUnregister(hInstance);
            break;
    }
    return true;
}