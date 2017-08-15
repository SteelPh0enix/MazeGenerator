#include "rbmaze.hpp"

RBMaze::RBMaze(unsigned difficulty) : Maze{difficulty, difficulty}, difficulty_{difficulty} {}

void RBMaze::generate() {
  set(difficulty_ / 2, difficulty_ / 2, true);
}
