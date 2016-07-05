#include "Game.hpp"
#include "MainGameState.hpp"
#include <iostream>
#include "Logger.hpp"

#define NO_ERRORS 0
#define SCALE_FACTOR 3
#define MAX_FRAMESKIP 10
#define FPS_UPS_SHOWN 0
#define UPS 60
#define UPS_TICK_TIME 1000/UPS

Game* Game::instance = nullptr;

Game* Game::Instance() {
  if (!instance) instance = new Game();
  return instance;
}

void Game::destroy() {
  if (instance) delete instance;
  instance = nullptr;
}

Game::Game() {
  Logger::Instance().toTerminal();
  Logger::Instance() << "==============================\n";
  Logger::Instance() << "=         Game Log           =\n";
  Logger::Instance() << "==============================\n";
  this->view.reset(sf::FloatRect(0,0,SCREEN_X,SCREEN_Y));
  this->glContextSettings.antialiasingLevel = 0;
  this->window.create(sf::VideoMode(SCALE_FACTOR*SCREEN_X,SCALE_FACTOR*SCREEN_Y), "Requested Miner", sf::Style::Close | sf::Style::Titlebar , this->glContextSettings);
  this->window.setView(this->view);
  this->running = true;
  this->stateManager = GameStateManager::Instance();
  this->currentState = nullptr;

  this->ticks = 0;
  this->oldTick = 0;
  this->actualTick = 0;
  this->frameSkip = 0;
  this->frameTicks = 0;
  this->isFocused = true;

  this->stateManager->insert(new MainGameState());
}

Game::~Game() {
  instance = nullptr;
}

int Game::gameLoop() {
  while (this->window.isOpen() && running) {

    this->currentState = this->stateManager->getState();

    if (this->gameSpeedTimer.getElapsedTime().asMilliseconds() >= UPS_TICK_TIME) {
      this->ticks++;
      this->gameSpeedTimer.restart();
    }

    if (this->actualTick <= this->ticks) {
      this->update();
      this->actualTick++;
    }
    if (this->actualTick >= this->ticks || this->frameSkip > MAX_FRAMESKIP) {
      this->render();
      if (this->frameSkip > MAX_FRAMESKIP) this->actualTick = this->ticks;
      this->frameTicks++;
      this->frameSkip = 0;
    }
    else this->frameSkip++;

    if (this->ticks - this->oldTick >= UPS-1) {
      #if FPS_UPS_SHOWN == 1
        Logger::Instance() << "FPS: " << this->frameTicks << "\n";
        Logger::Instance() << "UPS: " << this->actualTick <<  "\n";
      #endif
      this->frameTicks = 0;
      this->ticks = 0;
      this->actualTick = 0;
      this->oldTick = this->ticks;
    }

  }

  this->window.close();

  return NO_ERRORS;
}

void Game::update() {
  while (this->window.pollEvent(this->events)) {
    if (this->events.type == sf::Event::Closed)
      this->running = false;
    else if (this->events.type == sf::Event::LostFocus)
      this->isFocused = false;
    else if (this->events.type == sf::Event::GainedFocus)
      this->isFocused = true;
  }

  if (this->currentState != nullptr) this->currentState->update();

}

void Game::render() {
  window.clear();
  if (this->currentState != nullptr) this->currentState->render();
  window.display();
}

sf::RenderWindow* Game::getWindow() {
  return &this->window;
}

bool Game::getFocus() {
  return this->isFocused;
}
