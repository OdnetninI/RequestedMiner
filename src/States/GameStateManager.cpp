#include "States/GameStateManager.hpp"

GameStateManager* GameStateManager::instance = nullptr;

GameStateManager* GameStateManager::Instance() {
  if (!instance) instance = new GameStateManager();
  return instance;
}

GameStateManager::GameStateManager() {

}

GameStateManager::~GameStateManager() {
  instance = nullptr;
  while (!this->states.empty()) {
    this->states.top()->cleanup();
    delete this->states.top();
    this->states.pop();
  }
}

void GameStateManager::insert(GameState* state) {
  if (state != nullptr) {
    state->init();
    this->states.push(state);
  }
}

void GameStateManager::extract() {
  if (!this->states.empty()) {
    this->states.top()->cleanup();
    delete this->states.top();
    this->states.pop();
  }
}

GameState* GameStateManager::getState() {
  if (!this->states.empty()) return this->states.top();
  return nullptr;
}
