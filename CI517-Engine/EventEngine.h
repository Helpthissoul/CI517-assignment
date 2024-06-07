#include <stdio.h>
#include <string>
#include <thread>
#include <unordered_map>

#include <SDL.h>

#include "EngineCommon.h"
#include "GameMath.h"

#ifndef IPUT_ENUMS_H
#define IPUT_ENUMS_H
enum Key
{
    W, S, A, D, ESC, SPACE, UP, DOWN, LEFT, RIGHT, QUIT, LAST
};

enum Mouse {
    BTN_LEFT, BTN_RIGHT, BTN_LAST
};

#endif // IPUT_ENUMS_H

#ifndef EVENTENGINE_H
#define EVENTENGINE_H

class EventEngine {
    friend class XCube2Engine;
private:
    static const int NUM_KEYS = Key::LAST;
    static const int NUM_BUTTONS = Mouse::BTN_LAST;
    SDL_Event event;
    bool keys[NUM_KEYS];
    bool buttons[NUM_BUTTONS];

    void updateKeys(const SDL_Keycode&, bool keyDown);

    
public:
     EventEngine();
    ~EventEngine();

    void pollEvents();
    

    bool running;
    bool paused;
    bool isPressed(Key);
    bool isPressed(Mouse);

    void setPressed(Key);
    void setPressed(Mouse);

    void setMouseRelative(bool);

    Point2 getMouseDPos();

    Point2 getMousePos();

    bool isPaused() const { return paused; }
    void togglePause();

   
};

#endif // EVENTENGINE_H


