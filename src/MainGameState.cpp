#include "MainGameState.hpp"
#include "Game.hpp"

MainGameState::MainGameState() {

}

MainGameState::~MainGameState() {

}

void MainGameState::init() {
  this->textureManager.create("Player", "Data/test.png");
  this->entityManager.create(1,1,32,32,this->textureManager.get("Player"), 0,0);
}

void MainGameState::update() {
  this->entityManager.update();
}

void MainGameState::render() {
  this->entityManager.draw(Game::Instance()->getWindow());
}

void MainGameState::cleanup() {

}
