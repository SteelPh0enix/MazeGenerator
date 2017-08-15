#include "mazedrawer.hpp"
#include <iostream>

MazeDrawer::MazeDrawer(sf::RenderWindow& window, Maze* maze)
 : maze_{maze}, win_{window} {
  tile_.setOutlineThickness(0);

  setGroundColor(sf::Color::White);
  setWallColor(sf::Color::Black);
  setTileSize(10.f, 10.f);
}

void MazeDrawer::draw() {
  for (Maze::size_type y{0}; y < maze_->height(); ++y)
    for (Maze::size_type x{0}; x < maze_->width(); ++x) {
      tile_.setPosition(x * tile_.getSize().x, y * tile_.getSize().y);
      tile_.setFillColor(maze_->get(x, y) ? groundColor_ : wallColor_);
      win_.draw(tile_);
    }
}

void MazeDrawer::setTileSize(float width, float height) {
  tile_.setSize({width, height});
  win_.setSize({static_cast<unsigned>(maze_->width() * tile_.getSize().x),
                static_cast<unsigned>(maze_->height() * tile_.getSize().y)});
}

void MazeDrawer::setGroundColor(sf::Color color) {
  groundColor_ = color;
}

void MazeDrawer::setWallColor(sf::Color color) {
  wallColor_ = color;
}
