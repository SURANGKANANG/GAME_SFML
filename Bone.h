#pragma once
#include<iostream>
#include<SFML\Graphics.hpp>


class Bone
{
public:
	Bone(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~Bone();

	void Draw(sf::RenderWindow& window) {
		window.draw(bone);
	}
	
	/*sf::FloatRect getGlobalBounds() {
		return bone.getGlobalBounds();
	}*/
	void setPosition(sf::Vector2f newPosition) {
		bone.setPosition(newPosition);
	}
private:
	sf::RectangleShape bone;
};
