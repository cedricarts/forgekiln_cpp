#include <iostream>
#include <string>
#include "input.hpp"

using namespace std;

template <typename T>


void print(T message)
{
    cout << message << endl;
}

int main() {
    InputManager inputM;
    
    inputM.WaitForInput();

    float v = inputM.Vertical();
    float h = inputM.Horizontal();
}



