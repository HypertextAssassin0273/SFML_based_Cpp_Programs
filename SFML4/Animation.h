#pragma once
#include <SFML/Graphics.hpp>

class Animation
{
public:
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	sf::IntRect uvRect;
	void Update(int row, float deltaTime, bool faceRight);
private:
	sf::Vector2u imageCount, currentImage;
	float totalTime, switchTime;
};
/*Note: You can enable Texture Repeat by calling (i.e. sf::Texture object) object.setRepeated(bool) or the smooth filter by calling object.setSmooth(bool).
		This will make pixels less noticible.
*/