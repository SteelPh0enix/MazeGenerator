#ifndef MAZEDRAWER_HPP
#define MAZEDRAWER_HPP
#include <SFML/Graphics.hpp>
#include "mazebuilder.hpp"

class MazeDrawer {
 private:
  sf::RectangleShape tile_;
  sf::Color wallColor_, groundColor_;
  Maze* maze_;
  sf::RenderWindow& win_;

 public:
  MazeDrawer(sf::RenderWindow& window, Maze* maze);

  void draw();
  void setTileSize(float width, float height);
  void setGroundColor(sf::Color color);
  void setWallColor(sf::Color color);
};

#endif // MAZEDRAWER_HPP
