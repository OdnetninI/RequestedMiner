#include "States/MainGameState.hpp"
#include "Game.hpp"
#include "Entity/AnimatedEntity.hpp"
#include "Map/MapEntity/DirLook.hpp"
#include "Map/MapEvent/MapEvent.hpp"
#include "System/Logger.hpp"

MainGameState::MainGameState():tiledScreen(&tileRetriever) {
  this->camera.setPosition(1000*16,1000*16);

  verde = new Map(990,1040,1019,1049);
  verde->setName("Verde");
  verde->load(false, 0, "Data/Pallet_Town_Down_0.csv");

  route1 = new Map(991,1030,900,999);
  route1->load(false, 0, "Data/Route_1_Down_0.csv");
  route1->load(false, 1, "Data/Route_1_Down_1.csv");
  route1->load(true, 0, "Data/Route_1_Up_0.csv");
  route1->load(true, 1, "Data/Route_1_Up_1.csv");
  route1->setName("Route1");

  pallet = new Map(1000,1020,1000,1018);
  pallet->load(false, 0, "Data/Pallet_Town_Down_0.csv");
  pallet->load(false, 1, "Data/Pallet_Town_Down_1.csv");
  pallet->load(true, 0, "Data/Pallet_Town_Up_0.csv");
  pallet->load(true, 1, "Data/Pallet_Town_Up_1.csv");
  pallet->setName("Pallet");

  pallet->addAyacente(route1);
  route1->addAyacente(pallet);
  route1->addAyacente(verde);
  verde->addAyacente(route1);
  tileRetriever.posFinder.insertar(pallet);
  tileRetriever.posFinder.insertar(route1);
  tileRetriever.posFinder.insertar(verde);

  MapEvent* evento = new MapEvent();
  evento->setPos(1,1);
  pallet->getEventManager()->add(evento);
}

MainGameState::~MainGameState() {
  delete pallet;
  delete route1;
  delete verde;
}

void MainGameState::init() {
  this->textureManager.create("Player", "Data/test.png");
  this->textureManager.create("Tileset", "Data/tileset.png");
  this->textureManager.create("Ball", "Data/ball.png");

  mapBall.getEntity().setTexture(this->textureManager.get("Ball"));
  mapBall.getEntity().setSize(24,24);
  mapBall.getEntity().setTexturePos(0,0);
  mapBall.setCamera(&camera);
  mapBall.setPosition(16000,16000);

  _player.setCamera(&camera);
  _player.setPosition(16*1003,16*1003);

  controller.setCharacter(&_player);

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
  player->setTimePerFrame(4);
  player->setLoop(true);

  _player.setWalkingAnimation(DIR_DOWN, this->animationManager.get("Down"));
  _player.setWalkingAnimation(DIR_UP, this->animationManager.get("Up"));
  _player.setWalkingAnimation(DIR_LEFT, this->animationManager.get("Left"));
  _player.setWalkingAnimation(DIR_RIGHT, this->animationManager.get("Right"));

  camera.lockEntity(&_player);
}

void MainGameState::update() {
  if (Game::Instance()->getFocus()) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
      Game::Instance()->getWindow()->close();
    controller.update();
  }

  this->camera.update();
  this->_player.update();
  // Positioning ERROR
  // Only update actual map
  // What i must update? Actualmap, oldMap, all visible map?
  Map* actualmap = this->tileRetriever.getMap((this->_player.getX()+TILE_SIZE)/TILE_SIZE, (this->_player.getY()+TILE_SIZE)/TILE_SIZE);
  controller.setActualMap(actualmap);
  if (actualmap) {
    actualmap->update();
    //std::cout << actualmap->getName() << "\n";
  }
  mapBall.update();
  this->tiledScreen.setPos(-(camera.getX() % TILE_SIZE), -(camera.getY() % TILE_SIZE));
  this->tiledScreen.update(camera.getX(), camera.getY());

  // Must be do only when player moves or when map or event changes
  // TODO: PLAYER POSITION ERROR, TEMPORALY CORRECTED WITH +TILE_SIZE
  if (actualmap) {
    uint64_t py = (_player.getY()+TILE_SIZE)/TILE_SIZE - actualmap->minX;
    uint64_t px = (_player.getX()+TILE_SIZE)/TILE_SIZE - actualmap->minY;
    //Logger::Instance() << "PX = " << px << " PY = " << py << "\n";
    // Events only happends on actual map, need to find how can i determine that
    actualmap->checkEvent(px, py, 1);
    //actualmap->checkEvent(px, py, 0);
  }
}

void MainGameState::render() {
  this->tiledScreen.drawUnder(Game::Instance()->getWindow());
  this->player->render(Game::Instance()->getWindow());
  mapBall.getEntity().render(Game::Instance()->getWindow());
  this->tiledScreen.drawUpper(Game::Instance()->getWindow());
}

void MainGameState::cleanup() {

}
