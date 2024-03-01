#ifndef DEPRECATEDEXPRESSION_H
#define DEPRECATEDEXPRESSION_H

#include "Expression.h"

namespace gv {

class DeprExpression : Expression {
public:
    DeprExpression() {}    

    int GCode;


      void draw(sf::Image& image) {

        if(D == 0 && GCode == 1) {
          sf::CircleShape point(5); // You can adjust the radius to change the size of the point
          point.setFillColor(sf::Color::Red);
          point.setPosition(400.f, 300.f);
          image.setPixel(X, Y, sf::Color::White);
        }
        if(D == 1 && GCode == 0) {
          float x_c = 500.f;
          float y_c = 400.f;
       
          // Create a vertex array for the line
          sf::VertexArray line(sf::Lines, 2);
          line[0].position = sf::Vector2f(X, Y);
          line[0].color = sf::Color::Red;
          line[1].position = sf::Vector2f(x_c, y_c);
          line[1].color = sf::Color::Blue;
       
          // Draw the line on the image
          sf::RenderTexture renderTexture;
          renderTexture.create(800, 600);
          renderTexture.clear(sf::Color::White);
          renderTexture.draw(line);
          renderTexture.display();
       
          // Get the texture from the render texture
          const sf::Texture& texture = renderTexture.getTexture();
       
          // Copy the pixels to the image
          sf::Image lineImage = texture.copyToImage();
          image.copy(lineImage, static_cast<unsigned int>(X), static_cast<unsigned int>(Y));

        }
      }
};
}


#endif
