#include "MainGameState.hpp"
#include "Game.hpp"

MainGameState::MainGameState() {

}

MainGameState::~MainGameState() {

}

void MainGameState::init() {
  entity.setPosition(1,1);
  entity.setSize(32,32);
  entity.setTexturePos(0,0);
  text.loadFromFile("Data/test.png");
  entity.setTexture(&text);
}

void MainGameState::update() {
  entity.update();
}

void MainGameState::render() {
  entity.render(Game::Instance()->getWindow());
}

void MainGameState::cleanup() {

}
