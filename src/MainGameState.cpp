#include "MainGameState.hpp"
#include "Game.hpp"
#include "AnimatedEntity.hpp"

MainGameState::MainGameState() {

}

MainGameState::~MainGameState() {

}

void MainGameState::init() {
  this->textureManager.create("Pickaxe", "Data/Pick.png");
  Animation* anim = new Animation();
  anim->addFrame(0,0);
  anim->addFrame(0,32);
  anim->addFrame(0,64);
  anim->addFrame(0,96);
  anim->addFrame(0,64);
  anim->addFrame(0,32);
  anim->setTexture(this->textureManager.get("Pickaxe"));
  this->animationManager.add("Pick", anim);
  pickaxe = new AnimatedEntity();
  pickaxe->setPosition(64,64);
  pickaxe->setSize(32,32);
  pickaxe->setTimePerFrame(3);
  pickaxe->setAnimation(anim);
  pickaxe->setLoop(true);
  pickaxe->play();
  this->entityManager.insert(pickaxe);
}

void MainGameState::update() {

  if (Game::Instance()->getFocus()) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P)) {
      pickaxe->pause();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
      pickaxe->play();
    }
  }

  this->entityManager.update();
}

void MainGameState::render() {
  this->entityManager.draw(Game::Instance()->getWindow());
}

void MainGameState::cleanup() {

}
