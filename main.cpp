#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <utility>
#include "mazebuilder.hpp"
#include "mazedrawer.hpp"

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::string exePath = std::string{argv[0]};
    std::cout
    << "Usage:\n"
    << exePath.substr(exePath.find_last_of('\\') + 1)
    << " maze_type difficulty\n\n"
    << "Currently supported mazes types are:\n";
    for (const auto& type : MazeBuilder::MazeTypes) {
      std::cout << type.first << '\n';
    }
    std::cout.flush();
    return 0;
  }

  Maze* maze{};

  try {
    maze = MazeBuilder::createMaze(std::string{argv[1]}, std::stoul(argv[2]));
  } catch (std::range_error) {
    std::cout << "Range error occurred!" << std::endl;
    return 1;
  } catch (std::invalid_argument) {
    std::cout << "Invalid argument!" << std::endl;
    return 2;
  } catch (std::out_of_range) {
    std::cout << "Out of range error!" << std::endl;
    return 3;
  } catch (...) {
    std::cout << "Unknown error occurred" << std::endl;
    return 4;
  }

  maze->generate();

  sf::RenderWindow window{sf::VideoMode{800, 600}, "SteelPh0enix's Maze Generator"};
  MazeDrawer drawer{window, maze};

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear(sf::Color::Red);
    drawer.draw();
    window.display();
  }
}
