#include "Bone.h"

Bone::Bone(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
	bone.setSize(size);
	bone.setPosition(position);
	bone.setOrigin(size / 2.0f);
	bone.setTexture(texture);

}

Bone::~Bone()
{
}

