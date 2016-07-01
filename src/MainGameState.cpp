#include "MainGameState.hpp"
#include "Game.hpp"
#include "AnimatedEntity.hpp"

MainGameState::MainGameState() {
  sx = 0;
  sy = 0;
}

MainGameState::~MainGameState() {

}

void MainGameState::init() {
  this->textureManager.create("Pickaxe", "Data/Pick.png");
  this->textureManager.create("Tileset", "Data/tileset.png");
  this->tiledScreen.setTileset(this->textureManager.get("Tileset"));
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
  pickaxe->setTimePerFrame(6);
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
  sx = (sx - 1) % TILE_SIZE;
  sy = (sy - 1) % TILE_SIZE;
  this->tiledScreen.setPos(sx, sy);
}

void MainGameState::render() {
  this->tiledScreen.drawUnder(Game::Instance()->getWindow());
  this->entityManager.draw(Game::Instance()->getWindow());
  this->tiledScreen.drawUpper(Game::Instance()->getWindow());
}

void MainGameState::cleanup() {

}
