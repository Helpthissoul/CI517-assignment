#include <stdio.h>
#include "XCube2d.h"
#include "EventEngine.h"



class AbstractGame {
private:
    

    void handleMouseEvents();

protected:
    AbstractGame();
    virtual ~AbstractGame();

    std::shared_ptr<GraphicsEngine> gfx;
    std::shared_ptr<EventEngine> eventSystem;

    bool running;
    bool paused;
    double gameTime;
    virtual void update() = 0;
    virtual void render() = 0;

    virtual void handleKeyEvents() = 0;
    virtual void onLeftMouseButton();
    virtual void onRightMouseButton();

    void pause() { paused = true; }
    void resume() { paused = false; }

public:
    int runMainLoop();
    virtual void renderPauseMessage() = 0;
};

