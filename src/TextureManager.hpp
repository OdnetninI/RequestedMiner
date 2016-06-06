#ifndef __TEXTUREMANAGER_HPP__
#define __TEXTUREMANAGER_HPP__

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class TextureManager {
  private:
    std::map<std::string, sf::Texture*> textures;

  public:
    TextureManager();
    ~TextureManager();
    void add(std::string name, sf::Texture* texture);
    void create(std::string name, const char* filename);
    void remove(std::string name);
    sf::Texture* get(std::string name);
};

#endif // __TEXTUREMANAGER_HPP__
