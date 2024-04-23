#ifndef REVENANT_CONTROL_H
#define REVENANT_CONTROL_H

namespace revenant
{
    class Control
    {
    public:
        static bool IsEnabled(CONTROL_TYPE controlType, CONTROL_ACTION controlAction);
        static bool IsPressed(CONTROL_TYPE controlType, CONTROL_ACTION controlAction);
        static bool IsReleased(CONTROL_TYPE controlType, CONTROL_ACTION controlAction);
        static bool IsJustPressed(CONTROL_TYPE controlType, CONTROL_ACTION controlAction);
        static bool IsJustReleased(CONTROL_TYPE controlType, CONTROL_ACTION controlAction);
        static bool IsUsingKeyboardAndMouse(CONTROL_TYPE controlType);
        static bool IsUsingMouse(CONTROL_TYPE controlType);

        static int GetControlValue(CONTROL_TYPE controlType, CONTROL_ACTION controlAction);

        static float GetControlNormal(CONTROL_TYPE controlType, CONTROL_ACTION controlAction);

        static void SetMousePosition(Vector2 position);
        static void EnableControl(CONTROL_TYPE controlType, CONTROL_ACTION controlAction, bool enableRelatedActions);
        static void DisableControl(CONTROL_TYPE controlType, CONTROL_ACTION controlAction, bool disableRelatedActions);
        static void EnableAll(CONTROL_TYPE controlType);
        static void DisableAll(CONTROL_TYPE controlType);
    };
}

#endif //REVENANT_CONTROL_H