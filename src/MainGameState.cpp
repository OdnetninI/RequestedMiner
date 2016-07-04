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

#include "Logger.hpp"
void MainGameState::update() {

  if (Game::Instance()->getFocus()) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P)) {
      pickaxe->pause();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
      pickaxe->play();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
      x++;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
      x--;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
      y--;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
      y++;
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
