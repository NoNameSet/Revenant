#ifndef REVENANT_REVENANT_PCH_H
#define REVENANT_REVENANT_PCH_H

#pragma once

#include <windows.h>
#include <d3d11.h>

#include <cassert>
#include <cinttypes>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <atomic>
#include <chrono>
#include <deque>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <memory>
#include <mutex>
#include <optional>
#include <sstream>
#include <stack>
#include <string>
#include <thread>
#include <type_traits>
#include <unordered_map>
#include <vector>
#include <variant>

#define REVENANT_WIDE_IMPL(str) L ## str
#define REVENANT_WIDE(str) REVENANT_WIDE_IMPL(str)

#define REVENANT_STRINGIZE_IMPL(x) #x
#define REVENANT_STRINGIZE(x) REVENANT_STRINGIZE_IMPL(x)

#define REVENANT_NAME "Revenant"

namespace revenant
{
    namespace fs = std::filesystem;

    inline std::atomic_bool g_Running = true;
}

#include "../../../external/ScriptHookV/include/types.h"
#include "../../../external/ScriptHookV/include/natives.hpp"
#include "../../../external/ScriptHookV/include/enums.h"
#include "../../../external/ScriptHookV/include/main.h"

#include "Logger.h"

#endif //REVENANT_REVENANT_PCH_H