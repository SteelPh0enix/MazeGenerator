#ifndef RBMAZE_HPP
#define RBMAZE_HPP
#include "maze.hpp"

class RBMaze final : public Maze {
  unsigned difficulty_;

 public:
  RBMaze(unsigned difficulty);

  void generate() override;
};

#endif // RBMAZE_HPP
