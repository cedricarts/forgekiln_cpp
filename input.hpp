#ifndef forge_input // 1. Include Guard: Prevents duplicate definitions
#define forge_input

#include <windows.h>

using namespace std;

class InputManager
{
    float left_input = -1;
    float down_input = -1;
    float right_input = 1;
    float up_input = 1;

    short isDown = 0x8000;
    float h_input, v_input;

public:
    float Horizontal()
    {
        h_input = 0;
        if (GetKeyState('A') & isDown)
        {
            h_input = left_input;
        }
        else if (GetKeyState('D') & isDown)
        {
            h_input = right_input;
        }
        else
        {
            h_input = 0;
        }

        return h_input;
    }

    float Vertical()
    {
        v_input = 0;
        if (GetKeyState('W') & isDown)
        {
            v_input = up_input;
        }
        else if (GetKeyState('S') & isDown)
        {
            v_input = down_input;
        }
        else
        {
            v_input = 0;
        }
        return v_input;
    }

    void WaitForInput()
    {
        float v, h;

        while (true)
        {
            Sleep(10);

            v = Vertical();
            h = Horizontal();

            if (v == 1) {
                cout << "Up" << endl;
            } else if (h == 1) {
                cout << "Right" << endl;
            } else if (h == -1) {
                cout << "Left" << endl;
            } else if (v == -1){
                cout << "Down" << endl;
            }
        }
    }
};

#endif