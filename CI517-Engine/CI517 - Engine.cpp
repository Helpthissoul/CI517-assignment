#include <stdio.h>
#include <iostream>
#include "MyGame.h"
using namespace std;

int main(int argc, char* argv[])
{
    try
    {
        MyGame game;
        game.runMainLoop();
    }
    catch (exception e)
    {
        cout << "error: " << endl;
    }
    return 0;
}

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