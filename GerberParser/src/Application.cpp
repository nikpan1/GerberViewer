#include "Parser.h"
#include "Core.cpp"
#include "Drawer.h"
#include <SFML/Graphics.hpp>

int main(int argc, char** argv) {
  gvLOG("Starting the main.cpp.")
  gvASSERT(argc == 2, "Wrong amount of inputs.");

  std::string str = argv[1];
    
  sf::Image image;
  unsigned int width = 100;
  unsigned int height = 100;
  image.create(width, height);

  // Fill the image with a color (e.g., white)
  sf::Color fillColor = sf::Color::Black;
  for (unsigned int x = 0; x < width; ++x) {
    for (unsigned int y = 0; y < height; ++y) {
      image.setPixel(x, y, fillColor);
    }
  }

  auto v = gv::Parser(str);
  auto path = v.Run();
  auto drawer = new Drawer(v);
  
  drawer.Draw(image);


  gvLOG(path);
  gvLOG("Finished.");
  return 0;
}

