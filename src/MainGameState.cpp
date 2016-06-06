#include "MainGameState.hpp"
#include "Game.hpp"

MainGameState::MainGameState() {

}

MainGameState::~MainGameState() {

}

void MainGameState::init() {
  Entity* entity = new Entity();
  entity->setPosition(1,1);
  entity->setSize(32,32);
  entity->setTexturePos(0,0);
  text.loadFromFile("Data/test.png");
  entity->setTexture(&text);
  this->entityManager.insert(entity);
}

void MainGameState::update() {
  this->entityManager.update();
}

void MainGameState::render() {
  this->entityManager.draw(Game::Instance()->getWindow());
}

void MainGameState::cleanup() {

}
