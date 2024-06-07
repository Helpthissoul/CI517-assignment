#include <stdio.h>
#include <string>
#include <memory>
#include <iostream>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>


#include "EngineCommon.h"
#include "GameMath.h"


static const int DEFAULT_WINDOW_WIDTH = 800;
static const int DEFAULT_WINDOW_HEIGHT = 600;

static const SDL_Color SDL_COLOR_GRAY = { 0x80, 0x80, 0x80 };
static const SDL_Color SDL_COLOR_YELLOW = { 0xFF, 0xFF, 0 };
static const SDL_Color SDL_COLOR_RED = { 0xFF, 0, 0 };
static const SDL_Color SDL_COLOR_GREEN = { 0, 0xFF, 0 };
static const SDL_Color SDL_COLOR_BLUE = { 0, 0, 0xFF };
static const SDL_Color SDL_COLOR_BLACK = { 0, 0, 0 };
static const SDL_Color SDL_COLOR_WHITE = { 0xFF, 0xFF, 0xFF };
static const SDL_Color SDL_COLOR_AQUA = { 0, 0xFF, 0xFF };
static const SDL_Color SDL_COLOR_ORANGE = { 0xFF, 0xA5, 0 };
static const SDL_Color SDL_COLOR_PINK = { 0xFF, 0xC0, 0xCB };
static const SDL_Color SDL_COLOR_PURPLE = { 0x80, 0, 0x80 };
static const SDL_Color SDL_COLOR_VIOLET = { 0xEE, 0x82, 0xEE };

inline SDL_Color getRandomColor(int minRGB, int maxRGB)
{
    SDL_Color color = { (Uint8)getRandom(minRGB, maxRGB), (Uint8)getRandom(minRGB, maxRGB), (Uint8)getRandom(minRGB, maxRGB) };
    return color;
}

struct SDL_Colorf
{
    float r, g, b, a;
};

inline SDL_Colorf toSDLColorf(SDL_Color color)
{
    SDL_Colorf colorf = { color.r / 255.0f, color.g / 255.0f, color.b / 255.0f, color.a / 255.0f };
    return colorf;
}

inline SDL_Color toSDLColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_Color color = { r, g, b, a };
    return color;
}

class GraphicsEngine
{
    friend class XCube2Engine;
private:
    SDL_Window* window;
    static SDL_Renderer* renderer;
    SDL_Color drawColor;


    Uint32 fpsAverage, fpsPrevious, fpsStart, fpsEnd;

    GraphicsEngine();

public:
    ~GraphicsEngine();

    void setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    void fillRect(const SDL_Rect& rect);
 
    void clearScreen();

    
    void showScreen();

    void drawRect(const SDL_Rect&);
    void drawRect(const SDL_Rect&, const SDL_Color&);

    void drawRect(SDL_Rect*, const SDL_Color&);
    void drawRect(SDL_Rect*);
    void drawRect(const int& x, const int& y, const int& w, const int& h);

    void fillRect(SDL_Rect*);
    void fillRect(const int& x, const int& y, const int& w, const int& h);

    void drawPoint(const Point2&);
    void drawLine(const Line2i&);
    void drawLine(const Point2& start, const Point2& end);
    void drawCircle(const Point2& center, const float& radius);
    void drawEllipse(const Point2& center, const float& radiusX, const float& radiusY);
    


    void setDrawColor(const SDL_Color&);
    void setDrawScale(const Vector2f&);    


    void setWindowIcon(const char* fileName);
    void setWindowSize(const int&, const int&);
    void setWindowTitle(const char* title);
    void setWindowTitle(const std::string&);
    void setFullscreen(bool);
    void setVerticalSync(bool);
   
    void showInfoMessageBox(const std::string& info, const std::string& title = "");

    Dimension2i getCurrentWindowSize();

    Dimension2i getMaximumWindowSize();

    void setFrameStart();
    void adjustFPSDelay(const Uint32&);
    Uint32 getAverageFPS();

    static SDL_Texture* createTextureFromSurface(SDL_Surface*);
    SDL_Texture* createTextTexture(const std::string& text, const SDL_Color& color, TTF_Font* font);
    void drawTexture(SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dst);

};

typedef GraphicsEngine GFX;


