#include <stdio.h>
#include <SDL.h>
#include "AbstractGame.h"
#include "EventEngine.h"

struct GameKey {
    Point2 pos;
    bool isAlive;
};

class MyGame : public AbstractGame
{
private:
    SDL_Rect box;

    Vector2i velocity;

    std::vector<std::shared_ptr<GameKey>> gameKeys;
    EventEngine eventEngine;

    int numKeys;
    void handleKeyEvents();
    void update();
    void render();
    void renderUI();
    void renderPauseMessage() override;
public:
    SDL_Color randomColor;
    MyGame();
    ~MyGame();
    void resume();
};
