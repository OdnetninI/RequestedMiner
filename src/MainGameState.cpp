#include "MainGameState.hpp"
#include "Game.hpp"
#include "AnimatedEntity.hpp"

MainGameState::MainGameState() {

}

MainGameState::~MainGameState() {

}

void MainGameState::init() {
  this->textureManager.create("Player", "Data/test.png");
  //this->entityManager.create(1,1,32,32,this->textureManager.get("Player"), 32,0);
  AnimatedEntity* player = new AnimatedEntity();
  player->setPosition(1,1);
  player->setSize(32,32);
  player->setTimePerFrame(5);
  Animation* anim = new Animation();
  anim->setTexture(this->textureManager.get("Player"));
  anim->addFrame(0,0);
  anim->addFrame(32,0);
  anim->addFrame(64,0);
  anim->addFrame(32,0);
  player->setAnimation(anim);
  player->setLoop(true);
  player->play();
  this->entityManager.insert(player);
}

void MainGameState::update() {
  this->entityManager.update();
}

void MainGameState::render() {
  this->entityManager.draw(Game::Instance()->getWindow());
}

void MainGameState::cleanup() {

}
