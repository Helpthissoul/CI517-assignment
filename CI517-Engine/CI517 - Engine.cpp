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
        cout << "mam " << endl;
    }
    return 0;
}
