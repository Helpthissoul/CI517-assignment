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
    bool running;
    bool paused;
    SDL_Event event;
    bool keys[NUM_KEYS];
    bool buttons[NUM_BUTTONS];

    void updateKeys(const SDL_Keycode&, bool keyDown);

    
public:
     EventEngine();
    ~EventEngine();

    /**
    * Equivalent to calling SDL_PollEvent()
    */
    void pollEvents();

    bool isPressed(Key);
    bool isPressed(Mouse);

    /**
     * Software emulation of keypresses
     */
    void setPressed(Key);
    void setPressed(Mouse);

    void setMouseRelative(bool);

    /**
    * Returns mouse's delta position
    * It's the difference between current and
    * previous mouse positions
    *
    */
    Point2 getMouseDPos();

    /**
    * Returns current mouse position relative to the window
    */
    Point2 getMousePos();

    bool isPaused() const { return paused; }
    void togglePause();
};

#endif // EVENTENGINE_H


