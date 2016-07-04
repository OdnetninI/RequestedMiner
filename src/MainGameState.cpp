#include "MainGameState.hpp"
#include "Game.hpp"
#include "AnimatedEntity.hpp"

MainGameState::MainGameState():tiledScreen(&tileRetriever) {
  sx = 0;
  sy = 0;
  x = 1000;
  y = 1000;

  route1 = new Map(991,1030,900,999);
  route1->load(false, 0, "Data/Route_1_Down_0.csv");
  route1->load(false, 1, "Data/Route_1_Down_1.csv");
  route1->load(true, 0, "Data/Route_1_Up_0.csv");
  route1->load(true, 1, "Data/Route_1_Up_1.csv");

  pallet = new Map(1000,1020,1000,1018);
  pallet->load(false, 0, "Data/Pallet_Town_Down_0.csv");
  pallet->load(false, 1, "Data/Pallet_Town_Down_1.csv");
  pallet->load(true, 0, "Data/Pallet_Town_Up_0.csv");
  pallet->load(true, 1, "Data/Pallet_Town_Up_1.csv");

  pallet->addAyacente(route1);
  route1->addAyacente(pallet);
  tileRetriever.posFinder.insertar(pallet);
  tileRetriever.posFinder.insertar(route1);
}

MainGameState::~MainGameState() {
  delete pallet;
  delete route1;
}

void MainGameState::init() {
  this->textureManager.create("Player", "Data/test.png");
  this->textureManager.create("Tileset", "Data/tileset.png");
  this->tiledScreen.setTileset(this->textureManager.get("Tileset"));
  Animation* anim = new Animation();
  anim->addFrame(16,0);
  anim->addFrame(0,0);
  anim->addFrame(16,0);
  anim->addFrame(32,0);
  anim->setTexture(this->textureManager.get("Player"));
  this->animationManager.add("Down", anim);
  anim = new Animation();
  anim->addFrame(16,16);
  anim->addFrame(0,16);
  anim->addFrame(16,16);
  anim->addFrame(32,16);
  anim->setTexture(this->textureManager.get("Player"));
  this->animationManager.add("Left", anim);
  anim = new Animation();
  anim->addFrame(16,32);
  anim->addFrame(0,32);
  anim->addFrame(16,32);
  anim->addFrame(32,32);
  anim->setTexture(this->textureManager.get("Player"));
  this->animationManager.add("Right", anim);
  anim = new Animation();
  anim->addFrame(16,48);
  anim->addFrame(0,48);
  anim->addFrame(16,48);
  anim->addFrame(32,48);
  anim->setTexture(this->textureManager.get("Player"));
  this->animationManager.add("Up", anim);
  player = new AnimatedEntity();
  player->setPosition(64,64);
  player->setSize(16,16);
  player->setTimePerFrame(6);
  player->setAnimation(this->animationManager.get("Down"));
  player->setLoop(true);
  player->stop();
  this->entityManager.insert(player);
}

#include "Logger.hpp"
void MainGameState::update() {

  if (Game::Instance()->getFocus()) {
    player->stop();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
      x++;
      player->setAnimation(this->animationManager.get("Right"));
      player->play();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
      x--;
      player->setAnimation(this->animationManager.get("Left"));
      player->play();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
      y--;
      player->setAnimation(this->animationManager.get("Up"));
      player->play();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
      y++;
      player->setAnimation(this->animationManager.get("Down"));
      player->play();
    }
  }

  this->entityManager.update();
  sx = x % TILE_SIZE;
  sy = y % TILE_SIZE;
  this->tiledScreen.setPos(sx, sy);
  this->tiledScreen.update(x,y);
}

void MainGameState::render() {
  this->tiledScreen.drawUnder(Game::Instance()->getWindow());
  this->entityManager.draw(Game::Instance()->getWindow());
  this->tiledScreen.drawUpper(Game::Instance()->getWindow());
}

void MainGameState::cleanup() {

}
