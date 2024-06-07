#include "MyGame.h"
#include "EventEngine.h"
#include <iostream>
#include <SDL_ttf.h>

MyGame::MyGame() : AbstractGame(), numKeys(15), box{ 20, 20, 300, 300 }, eventEngine()
{
	gfx->setVerticalSync(true);

	// Draw points on random location
	for (int i = 0; i < numKeys; i++) {
		std::shared_ptr<GameKey> k = std::make_shared<GameKey>();
		k->isAlive = true;
		k->pos = Point2(getRandom(0, 750), getRandom(0, 550));
		gameKeys.push_back(k);
	}

	if (TTF_Init() == -1) {
		std::cerr << "Failed to initialize SDL_ttf: " << TTF_GetError << std::endl;
		throw std::runtime_error("SDL_ttf initialization failed");
	}
	EventEngine eventEngine;
}
MyGame::~MyGame()
{
	TTF_Quit();
}
void MyGame::handleKeyEvents()
{
	eventEngine.pollEvents();
	std::cout << "ESC key pressed" << std::endl;
	if (eventEngine.isPressed(Key::ESC)) {
		eventEngine.togglePause();
		if (eventEngine.isPaused()) {
			pause();
			renderPauseMessage();
			std::cout << "stopped" << std::endl;
		}
		else {
			resume();
		}
	}

}
void MyGame::update() {
	if (eventEngine.isPaused()) {
		return;
	}
}
void MyGame::render()
{
	gfx->setDrawColor(SDL_COLOR_RED);
	gfx->drawRect(box);
	gfx->setDrawColor(SDL_COLOR_BLUE);
	//
	gfx->fillRect(12, 2, 30, 30);
	//
	gfx->setDrawColor(SDL_COLOR_YELLOW);
	for (auto key : gameKeys)
		if (key->isAlive)
			gfx->drawCircle(key->pos, 5);

	if (eventEngine.isPaused()) {
		renderPauseMessage();
	}
}
void MyGame::renderUI(){}
void MyGame::renderPauseMessage() {
	gfx->setDrawColor(0, 0, 0, 128);
	SDL_Rect overlayRect = { 0, 0, 800, 600 };
	gfx->fillRect(overlayRect);

	TTF_Font* font = TTF_OpenFont(nullptr, 24);
	SDL_Color textColor = { 255, 255, 255, 1 };
	SDL_Texture* textTexture = gfx->createTextTexture("Game Paused", textColor, font);
	if (!textTexture) {
		TTF_CloseFont(font);
		return;
	}
	int textWidth, textHeight;
	SDL_QueryTexture(textTexture, NULL, NULL, &textWidth, &textHeight);
	SDL_Rect textRect;
	textRect.x = (800 - textWidth) / 2;
	textRect.y = (600 - textHeight) / 2;
	textRect.w = textWidth;
	textRect.h = textHeight;

	gfx->drawTexture(textTexture, NULL, &textRect);

	SDL_DestroyTexture(textTexture);
	TTF_CloseFont(font);
}