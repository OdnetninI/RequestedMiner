#include "TextureManager.hpp"

TextureManager::TextureManager() {

}

TextureManager::~TextureManager() {
  for (auto it = this->textures.begin(); it != this->textures.end(); it++)
    delete it->second;
}

void TextureManager::add(std::string name, sf::Texture* texture) {
  this->textures.insert(std::pair<std::string, sf::Texture*>(name, texture));
}

sf::Texture* TextureManager::create(std::string name, const char* filename) {
  sf::Texture* text = new sf::Texture();
  text->loadFromFile(filename);
  this->textures.insert(std::pair<std::string, sf::Texture*>(name, text));
  return text;
}

void TextureManager::remove(std::string name) {
  auto it = this->textures.find(name);
  if (it == this->textures.end()) return;
    delete it->second;
    this->textures.erase(it);
}

sf::Texture* TextureManager::get(std::string name) {
  auto it = this->textures.find(name);
  if (it == this->textures.end()) return nullptr;
  return it->second;
}
