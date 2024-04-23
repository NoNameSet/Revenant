#include "ScriptManager.h"

namespace revenant
{
    ScriptManager::ScriptManager() = default;

    ScriptManager::~ScriptManager() noexcept
    {
        for (auto&& script : m_Scripts)
        {
            script->Destroy();
        }
    }

    void ScriptManager::AddScript(std::shared_ptr<Script> script)
    {
        std::lock_guard lock(m_Mutex);
        m_Scripts.push_back(std::move(script));
    }

    void ScriptManager::RemoveScript(Script* script)
    {
        std::lock_guard lock(m_Mutex);
        for (auto it = m_Scripts.begin(), end = m_Scripts.end(); it != end; ++it)
        {
            if (it->get() == script)
            {
                (*it)->Destroy();
                m_Scripts.erase(it);
                return;
            }
        }
    }

    void ScriptManager::OnTick()
    {
        std::lock_guard lock(m_Mutex);
        for (auto&& script : m_Scripts)
        {
            if (!script->IsInitialized())
                script->Initialize();
            script->Tick();
        }
    }
}