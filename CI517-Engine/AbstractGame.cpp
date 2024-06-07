#include "AbstractGame.h"
#include "EventEngine.h"
#include <iostream>
using namespace std;

AbstractGame::AbstractGame() : running(true), gameTime(0.0), paused(false)
{
    cout << "Abstract Game started" << endl;
    std::shared_ptr<XCube2Engine> engine = XCube2Engine::getInstance();

    gfx = engine->getGraphicsEngine();
    eventSystem = engine->getEventEngine();
}

AbstractGame::~AbstractGame()
{
    cout << "Abstract Game ended" << endl;

    gfx.reset();
    eventSystem.reset();
    XCube2Engine::quit();
}

int AbstractGame::runMainLoop() {

    gfx->clearScreen();
    render();
    while (running) {
        gfx->setFrameStart();
        eventSystem->pollEvents();
        if (eventSystem -> isPressed(Key::QUIT))

            running = false;

        handleKeyEvents();
        handleMouseEvents();

        if (!paused) {
            update();
            gameTime += 0.016;
        }
        else if (paused) {
            cout << "Game is paused" << endl;
            
        }

        gfx->clearScreen();
        render();
        gfx->showScreen();
        gfx->adjustFPSDelay(16);

}
    cout << "exiting game loop" << endl;
    return 0;
}

void AbstractGame::handleMouseEvents() {
    if (eventSystem->isPressed(Mouse::BTN_LEFT)) onLeftMouseButton();
    if (eventSystem->isPressed(Mouse::BTN_RIGHT)) onRightMouseButton();
}
void AbstractGame::onLeftMouseButton() {}
void AbstractGame::onRightMouseButton() {}