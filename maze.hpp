#ifndef MAZE_HPP
#define MAZE_HPP
#include <vector>

class Maze {
 public:
  using size_type = std::vector<bool>::size_type;

  Maze(size_type width, size_type height);
  virtual ~Maze() = default;
  virtual void generate() = 0;

  size_type width() const { return width_; }
  size_type height() const { return height_; }

  bool get(size_type x, size_type y) const {
    return maze_[y * width_ + x];
  }

  void set(size_type x, size_type y, bool val) {
    maze_[y * width_ + x] = val;
  }

 private:
  std::vector<bool> maze_; //false - wall, true - empty
  size_type width_, height_;
};

#endif // MAZE_HPP
