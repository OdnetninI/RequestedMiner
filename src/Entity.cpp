#include "Entity.hpp"

Entity::Entity() {
  this->x = 0;
  this->y = 0;
  this->w = 0;
  this->h = 0;
  this->tx = 0;
  this->ty = 0;
  this->stateUpdated = true;

  for (int i = 0; i < 4; i++) {
    this->vertex[i].position = sf::Vector2f(0,0);
    this->vertex[i].texCoords = sf::Vector2f(0,0);
  }
}

Entity::~Entity() {

}

void Entity::setPosition (int32_t x, int32_t y) {
  this->x = x;
  this->y = y;
  this->stateUpdated = false;
}

void Entity::setSize (uint16_t w, uint16_t h) {
  this->w = w;
  this->h = h;
  this->stateUpdated = false;
}

void Entity::setTexturePos(uint16_t x, uint16_t y) {
  this->tx = x;
  this->ty = y;
  this->stateUpdated = false;
}

void Entity::update() {
  if (!this->stateUpdated) {
    this->vertex[0].position = sf::Vector2f(this->x, this->y);
    this->vertex[0].texCoords = sf::Vector2f(this->tx, this->ty);
    this->vertex[1].position = sf::Vector2f(this->x + this->w , this->y);
    this->vertex[1].texCoords = sf::Vector2f(this->tx + this->w, this->ty);
    this->vertex[2].position = sf::Vector2f(this->x + this->w, this->y + this->h);
    this->vertex[2].texCoords = sf::Vector2f(this->tx + this->w, this->ty + this->h);
    this->vertex[3].position = sf::Vector2f(this->x, this->y + this->h);
    this->vertex[3].texCoords = sf::Vector2f(this->tx, this->ty + this->h);
    this->stateUpdated = true;
  }
}

void Entity::setTexture(sf::Texture* texture) {
  this->renderState.texture = texture;
}

void Entity::render(sf::RenderWindow* window) {
  window->draw(this->vertex, 4,sf::PrimitiveType::TrianglesFan, this->renderState);
}
