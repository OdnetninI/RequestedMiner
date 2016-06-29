#include "TiledScreen.hpp"

TiledScreen::TiledScreen() {
  for (int16_t x = 0; x < MAP_WIDTH; x++) {
    for (int16_t y = 0; y < MAP_HEIGTH; y++) {
      for (int16_t l = 0; l < UP_LAYERS; l++) {
        
      }
      for (int16_t l = 0; l < DOWN_LAYERS; l++) {

      }
    }
  }
}

TiledScreen::~TiledScreen() {

}
