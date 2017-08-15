#include "maze.hpp"

Maze::Maze(Maze::size_type width, Maze::size_type height) : width_{width}, height_{height} {
  maze_.resize(width * height, false);
}
