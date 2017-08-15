#include "mazebuilder.hpp"

Maze* MazeBuilder::createMaze(MazeType type, unsigned difficulty) {
  if (difficulty < 1 || difficulty > 100) throw std::range_error{"Difficulty must be in range 1 - 100"};

  switch (type) {
    case MazeType::RecursiveBacktracker:
      return new RBMaze{difficulty};
  }
  return nullptr; //it should be not possible to get here, but for the sake of -Wpedantic and -Werror, i've added that
}

Maze* MazeBuilder::createMaze(std::string type, unsigned difficulty) {
  if (auto mazeType = MazeTypes.find(type); mazeType != MazeTypes.end()) {
    return createMaze(mazeType->second, difficulty);
  } else
    throw std::invalid_argument{"Wrong maze type!"};
}

std::map<std::string, MazeBuilder::MazeType> MazeBuilder::MazeTypes{
{"RecursiveBacktracker", MazeType::RecursiveBacktracker}};
