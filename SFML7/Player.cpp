#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight):
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	row = 0;
	faceRight = true;

	body.setSize(sf::Vector2f(100.0f, 150.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(206.0f, 206.0f);
	body.setTexture(texture);
}

void Player::Update(float deltaTime)
{
	velocity.x = 0.0f; //i.e. u can increase it to take more time to stop the sprite

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		velocity.x -= speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		velocity.x += speed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
	{
		canJump = false;
		velocity.y = -sqrt(2.0f * 981.0f * jumpHeight); //i.e. kinematic eqn, 9.81f->981.0f (for meter reference) ,value set as -ve to correct frames w.r.t origin
	}

	velocity.y += 981.0f * deltaTime;

	if (velocity.x == 0.0f)
		row = 0;
	else
	{
		row = 1;

		if (velocity.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}
	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime);
}

void Player::Draw(sf::RenderWindow &window)
{
	window.draw(body);
}

void Player::OnCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		velocity.x = 0.0f; //i.e. collision on left
	}
	else if (direction.x > 0.0f)
	{
		velocity.x = 0.0f; //i.e. collision on right
	}
	if (direction.y < 0.0f)
	{
		velocity.y = 0.0f; //i.e. collision on bottom
		canJump = true;
	}
	else if (direction.y > 0.0f)
	{
		velocity.y = 0.0f; //i.e. collision on top
	}
}
