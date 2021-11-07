#include "Player.h"
#include<stdio.h>
#include"Collider.h"

static const float VIEW_WIDTH = 960.0f;

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHight) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	this->jumpHight = jumpHight;
	row = 0;

	body.setSize(sf::Vector2f(150.0f, 100.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(80.0f, 200.0f);
	body.setTexture(texture);
}
Player::~Player()
{

}


void Player::Update(float deltaTime,float rr)
{
	velocity.x = 0.0f;
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		velocity.x -= speed;	
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		velocity.x += speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canJump)
	{
		canJump = false;
		velocity.y = -sqrtf(2.0f * 981.0f * jumpHight);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		velocity.x += speed*2;

	velocity.y += 981.0f * deltaTime;
	row = 0;
	animation.Update(row, deltaTime);
	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime*rr);
	//printf("%f\n", velocity.y);
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Player::OnCollosion(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		velocity.x = 0.0f;
	}

	else if (direction.x > 0.0f)
	{
		velocity.x = 0.0f;
	}

	if (direction.y < 0.0f)
	{
		velocity.y = 0.0f;
		canJump = true;
	}
	

	else if (direction.y > 0.0f)
	{
		velocity.y = 0.0f;
	}
	

}

