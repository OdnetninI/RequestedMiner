#include "MainGameState.hpp"
#include "Game.hpp"
#include "AnimatedEntity.hpp"

MainGameState::MainGameState():tiledScreen(&tileRetriever) {
  this->camera.setPosition(1000*16,1000*16);

  verde = new Map(990,1040,1019,1049);
  verde->load(false, 0, "Data/Pallet_Town_Down_0.csv");

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
  route1->addAyacente(verde);
  verde->addAyacente(route1);
  tileRetriever.posFinder.insertar(pallet);
  tileRetriever.posFinder.insertar(route1);
  tileRetriever.posFinder.insertar(verde);
}

MainGameState::~MainGameState() {
  delete pallet;
  delete route1;
  delete verde;
}
#include "Logger.hpp"
void MainGameState::init() {
  this->textureManager.create("Player", "Data/test.png");
  this->textureManager.create("Tileset", "Data/tileset.png");
  this->textureManager.create("Ball", "Data/ball.png");

  mapBall.getEntity().setTexture(this->textureManager.get("Ball"));
  mapBall.getEntity().setSize(24,24);
  mapBall.getEntity().setTexturePos(0,0);
  mapBall.setCamera(&camera);

  _player.setCamera(&camera);
  _player.setPosition(sf::Vector2<uint64_t>(16*1000,16*1000));

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
  player = &_player.getEntity();
  player->setPosition(64,64);
  player->setSize(16,16);
  player->setTimePerFrame(6);
  player->setAnimation(this->animationManager.get("Down"));
  player->setLoop(true);
  player->stop();

  camera.lockEntity(&_player);
}

#include "Logger.hpp"
void MainGameState::update() {
  if (Game::Instance()->getFocus()) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
      Game::Instance()->getWindow()->close();
    player->stop();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
      _player.move(1,0);
      player->setAnimation(this->animationManager.get("Right"));
      player->play();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
      _player.move(-1,0);
      player->setAnimation(this->animationManager.get("Left"));
      player->play();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
      _player.move(0,-1);
      player->setAnimation(this->animationManager.get("Up"));
      player->play();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
      _player.move(0,1);
      player->setAnimation(this->animationManager.get("Down"));
      player->play();
    }
  }

  this->camera.update();
  this->_player.update();
  this->pallet->update();
  mapBall.update();
  this->tiledScreen.setPos(-(camera.getX() % TILE_SIZE), -(camera.getY() % TILE_SIZE));
  this->tiledScreen.update(camera.getX(), camera.getY());
}

void MainGameState::render() {
  this->tiledScreen.drawUnder(Game::Instance()->getWindow());
  this->player->render(Game::Instance()->getWindow());
  mapBall.getEntity().render(Game::Instance()->getWindow());
  this->tiledScreen.drawUpper(Game::Instance()->getWindow());
}

void MainGameState::cleanup() {

}
