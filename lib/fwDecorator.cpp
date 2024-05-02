#include "fwDecorator.h"

void fwDecorator::InitialisePatterns()
{
    decorator_commands__g_DecorRegistrationsLocked = hook::get_pattern<bool>(
                                                        "80 3D ? ? ? ? ? 8B DA 75 29 48 8B D1 33 C9", 3);
}
