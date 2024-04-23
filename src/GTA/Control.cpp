#include "Control.h"

namespace revenant
{
    bool Control::IsEnabled(CONTROL_TYPE controlType, CONTROL_ACTION controlAction)
    {
        return PAD::IS_CONTROL_ENABLED(static_cast<int>(controlType), static_cast<int>(controlAction));
    }

    bool Control::IsPressed(CONTROL_TYPE controlType, CONTROL_ACTION controlAction)
    {
        return PAD::IS_CONTROL_PRESSED(static_cast<int>(controlType), static_cast<int>(controlAction));
    }

    bool Control::IsReleased(CONTROL_TYPE controlType, CONTROL_ACTION controlAction)
    {
        return PAD::IS_CONTROL_RELEASED(static_cast<int>(controlType), static_cast<int>(controlAction));
    }

    bool Control::IsJustPressed(CONTROL_TYPE controlType, CONTROL_ACTION controlAction)
    {
        return PAD::IS_CONTROL_JUST_PRESSED(static_cast<int>(controlType), static_cast<int>(controlAction));
    }

    bool Control::IsJustReleased(CONTROL_TYPE controlType, CONTROL_ACTION controlAction)
    {
        return PAD::IS_CONTROL_JUST_RELEASED(static_cast<int>(controlType), static_cast<int>(controlAction));
    }

    bool Control::IsUsingKeyboardAndMouse(CONTROL_TYPE controlType)
    {
        return PAD::IS_USING_KEYBOARD_AND_MOUSE(static_cast<int>(controlType));
    }

    bool Control::IsUsingMouse(CONTROL_TYPE controlType)
    {
        return PAD::IS_USING_CURSOR(static_cast<int>(controlType));
    }

    int Control::GetControlValue(CONTROL_TYPE controlType, CONTROL_ACTION controlAction)
    {
        return PAD::GET_CONTROL_VALUE(static_cast<int>(controlType), static_cast<int>(controlAction));
    }

    float Control::GetControlNormal(CONTROL_TYPE controlType, CONTROL_ACTION controlAction)
    {
        return PAD::GET_CONTROL_NORMAL(static_cast<int>(controlType), static_cast<int>(controlAction));
    }

    void Control::SetMousePosition(Vector2 position)
    {
        PAD::SET_CURSOR_POSITION(position.x, position.y);
    }

    void Control::EnableControl(CONTROL_TYPE controlType, CONTROL_ACTION controlAction, bool enableRelatedActions)
    {
        PAD::ENABLE_CONTROL_ACTION(static_cast<int>(controlType), static_cast<int>(controlAction), enableRelatedActions);
    }

    void Control::DisableControl(CONTROL_TYPE controlType, CONTROL_ACTION controlAction, bool disableRelatedActions)
    {
        PAD::DISABLE_CONTROL_ACTION(static_cast<int>(controlType), static_cast<int>(controlAction), disableRelatedActions);
    }

    void Control::EnableAll(CONTROL_TYPE controlType)
    {
        PAD::ENABLE_ALL_CONTROL_ACTIONS(static_cast<int>(controlType));
    }

    void Control::DisableAll(CONTROL_TYPE controlType)
    {
        PAD::DISABLE_ALL_CONTROL_ACTIONS(static_cast<int>(controlType));
    }
}