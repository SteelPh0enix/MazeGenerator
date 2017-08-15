#ifndef MAZEBUILDER_HPP
#define MAZEBUILDER_HPP
#include <exception>
#include <map>
#include <memory>
#include <string>
#include "maze.hpp"
#include "rbmaze.hpp"

class MazeBuilder {
 public:
  enum class MazeType {
    RecursiveBacktracker
  };

  static std::map<std::string, MazeType> MazeTypes;

  static Maze* createMaze(MazeType type, unsigned difficulty);
  static Maze* createMaze(std::string type, unsigned difficulty);
};

#endif // MAZEBUILDER_HPP
