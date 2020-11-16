#include "../include/basic.h"

#include <cstdlib>

//---------------------------------------------------------------------------------------

Character::Character() : Moveable(), name("unknown"), health(10), mana(10), animation()
{
	// Inicjalizacja zmiennych dotycz�cych ruchu
	tempDelta = 0.0;
	offset = 0.0f;
	gravity = 5.0f;
	moveSpeed = 100.0f;
	jumpSpeed = 300.0f;
	groundHeight = 620.0f;
	movement = sf::Vector2f(0.0f, 0.0f);
	coords = sf::Vector2i(0, 0);

	// Ustawienie flag dotycz�cych ruchu
	faceRight = true;
	isJumping = false;
	isFalling = false;
	canMoveRight = true;
	canMoveLeft = true;
	canJump = true;
	canFall = false;
	isColliding = false;
	lastDirection = UNKNOWN;

	// Ustawienie rz�du aniamcji, tekstury i sprite'a
	row = 1;
	if (!(*texture).loadFromFile(Resources::getWarlockTexture()))
		std::cout << "Blad wczytywania tekstury!" << std::endl;
	sprite.setTexture(*texture);
	sprite.setScale(1.0f, 1.0f);
	sprite.setPosition(50.0f, 50.0f);
	sprite.setOrigin(sprite.getPosition() / 2.0f);
	pendingSpell = false;
}

//---------------------------------------------------------------------------------------

Character::Character(sf::Texture *texture_) : Moveable(), name("unknown"), health(10), mana(10), animation(texture_)
{
	// Inicjalizacja zmiennych dotycz�cych ruchu
	tempDelta = 0.0;
	offset = 0.0f;
	gravity = 5.0f;
	moveSpeed = 100.0f;
	jumpSpeed = 300.0f;
	groundHeight = 620.0f;
	movement = sf::Vector2f(0.0f, 0.0f);
	coords = sf::Vector2i(0, 0);

	// Ustawienie flag dotycz�cych ruchu
	faceRight = false;
	isJumping = false;
	isFalling = false;
	canMoveRight = true;
	canMoveLeft = true;
	canJump = true;
	canFall = false;
	isColliding = false;
	lastDirection = UNKNOWN;

	// Ustawienie rz�du aniamcji, tekstury i sprite'a
	row = 1;
	texture = texture_;
	sprite.setTexture(*texture);
	sprite.setScale(1.0f, 1.0f);
	sprite.setPosition(50.0f, 50.0f);
	sprite.setOrigin(sprite.getPosition() / 2.0f);
	pendingSpell = false;
}

//---------------------------------------------------------------------------------------

Character::Character(sf::Vector2u imageCount_, float switchTime_) : Moveable(), name("unknown"), health(10), mana(10), animation(imageCount_, switchTime_)
{
	// Inicjalizacja zmiennych dotycz�cych ruchu
	tempDelta = 0.0;
	offset = 0.0f;
	gravity = 5.0f;
	moveSpeed = 100.0f;
	jumpSpeed = 300.0f;
	groundHeight = 620.0f;
	movement = sf::Vector2f(0.0f, 0.0f);
	coords = sf::Vector2i(0, 0);

	// Ustawienie flag dotycz�cych ruchu
	faceRight = false;
	isJumping = false;
	isFalling = false;
	canMoveRight = true;
	canMoveLeft = true;
	canJump = true;
	canFall = false;
	isColliding = false;
	lastDirection = UNKNOWN;

	// Ustawienie rz�du aniamcji, tekstury i sprite'a
	row = 1;
	if (!(*texture).loadFromFile(Resources::getWarlockTexture()))
		std::cout << "Blad wczytywania tekstury!" << std::endl;
	sprite.setTexture(*texture);
	sprite.setScale(1.0f, 1.0f);
	sprite.setPosition(50.0f, 50.0f);
	sprite.setOrigin(sprite.getPosition() / 2.0f);
	pendingSpell = false;
};

//---------------------------------------------------------------------------------------

Character::Character(sf::Texture *texture_, sf::Vector2u imageCount_, float switchTime_) : Moveable(), name("unknown"), health(10), mana(10), animation(texture_, imageCount_, switchTime_)
{
	// Inicjalizacja zmiennych dotycz�cych ruchu
	tempDelta = 0.0;
	offset = 0.0f;
	gravity = 5.0f;
	moveSpeed = 100.0f;
	jumpSpeed = 300.0f;
	groundHeight = 620.0f;
	movement = sf::Vector2f(0.0f, 0.0f);
	coords = sf::Vector2i(0, 0);

	// Ustawienie flag dotycz�cych ruchu
	faceRight = false;
	isJumping = false;
	isFalling = false;
	canMoveRight = true;
	canMoveLeft = true;
	canJump = true;
	canFall = false;
	isColliding = false;
	lastDirection = UNKNOWN;

	// Ustawienie rz�du aniamcji, tekstury i sprite'a
	row = 1;
	if (!(*texture).loadFromFile(Resources::getWarlockTexture()))
		std::cout << "Blad wczytywania tekstury!" << std::endl;
	sprite.setTexture(*texture);
	sprite.setScale(1.0f, 1.0f);
	sprite.setPosition(50.0f, 50.0f);
	sprite.setOrigin(sprite.getPosition() / 2.0f);
	pendingSpell = false;
};

//---------------------------------------------------------------------------------------

Character::~Character()
{
	if (this->texture != nullptr)
	{
		delete this->texture;
		this->texture = nullptr;
	}
}

//---------------------------------------------------------------------------------------

int Character::getHealth()
{
	return this->health;
}

//---------------------------------------------------------------------------------------

Direction Character::getLastDirection()
{
	return this->lastDirection;
}

//---------------------------------------------------------------------------------------

sf::Vector2f Character::getLastMovement()
{
	return this->lastMovement;
}

//---------------------------------------------------------------------------------------

void Character::setX(float x_)
{
	this->coords.x = x_;
}

//---------------------------------------------------------------------------------------

void Character::setY(float y_)
{
	this->coords.y = y_;
}

//---------------------------------------------------------------------------------------

// Metoda ustawiaj�ca imi� postaci
void Character::setName(const std::string &name_)
{
	this->name = name_;
}
//---------------------------------------------------------------------------------------

// Metoda ustawiaj�ca �ycie postaci
void Character::setHealth(int health_)
{
	this->health = health_;
}

//---------------------------------------------------------------------------------------

// Metoda ustawiaj�ca ilo�� many postaci
void Character::setMana(int mana_)
{
	this->mana = mana_;
}

//---------------------------------------------------------------------------------------

// True - porusza si� w prawo, false - porusza si� w lewo
void Character::setDirection(bool goRight)
{
	if (!goRight)
		this->faceRight = false;
	else
		this->faceRight = true;
}

//---------------------------------------------------------------------------------------

void Character::setCollisionState(bool collision)
{
	this->isColliding = collision;
}

//---------------------------------------------------------------------------------------

// Metoda sprawdzaj�ca czy posta� porusza si� w prawo
bool Character::isFacingRight()
{
	if (!(this->faceRight))
		return false;
	else
		return true;
}

//---------------------------------------------------------------------------------------

bool Character::isSpellPending()
{
	if (pendingSpell)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//---------------------------------------------------------------------------------------

void Character::move(sf::Vector2f newMovement)
{
	this->sprite.move(newMovement);
}

//---------------------------------------------------------------------------------------

void Character::slow(float delta)
{
	if (!debuffActive)
	{
		this->moveSpeed = 25.0f;
		this->tempDelta = delta;
		this->debuffActive = true;
	}
}

//---------------------------------------------------------------------------------------

void Character::hurt(float delta)
{
	if (!debuffActive)
	{
		this->health--;
		this->tempDelta = delta;
		this->debuffActive = true;
	}
}

//---------------------------------------------------------------------------------------

// Metoda aktualizuj�ca pozycj� gracza
void Character::update(float diff)
{
	movement = sf::Vector2f(0.0f, 0.0f);

	// Gdy posta� chce si� przesun�� w lewo
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (canMoveLeft)
		{
			movement.x -= moveSpeed * diff;
			row = 1;
			lastDirection = LEFT;
			faceRight = false;
		}
	}

	// Gdy posta� chce si� przesun�� w prawo
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (canMoveRight)
		{
			movement.x += moveSpeed * diff;
			row = 2;
			lastDirection = RIGHT;
			faceRight = true;
		}
	}

	// Gdy posta� chce skoczy�
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (canJump)
		{
			if (isJumping == false && isFalling == false)
			{
				isJumping = true;
				isFalling = false;
				offset = jumpSpeed;
				lastDirection = UP;
			}
		}
	}

	// Je�eli posta� skacze
	if (isJumping == true)
	{
		offset -= gravity;
		movement.y -= offset * diff;
		// Je�eli posta� osi�gnie maksymaln� d�ugo�� skoku
		if (offset <= 0)
		{
			isJumping = false;
			isFalling = true;
			offset = 0.0f;
		}
		lastDirection = UP;
	}

	// Je�eli posta� spada
	if (isFalling == true)
	{
		offset += gravity;
		movement.y += offset * diff;
		lastDirection = DOWN;

		// Dop�ki posta� nie dotyka poziomu pod�o�a
		if (this->getSprite().getPosition().y > groundHeight) // + this->getSprite().getGlobalBounds().height
		{
			isJumping = false;
			isFalling = false;
			offset = 0.0f;
			movement.y = 0;
			lastDirection = RIGHT;
		}
	}

	// Zdejmij debuffy z postaci
	if (debuffActive == true)
	{
		if (clock.getElapsedTime().asSeconds() > tempDelta)
		{
			moveSpeed = 100.0f;
			tempDelta = 0.0;
			clock.restart().asSeconds();
			debuffActive = false;
		}
	}

	// Je�eli posta� nie porusza si�
	if (movement.x == 0.0f && movement.y == 0.0f)
	{
		return;
	}
	// Je�eli zosta� dokonany jaki� ruch
	else
	{
		animation.update(row, diff, faceRight);
		sprite.setTextureRect(animation.getIntRect());
		sprite.move(movement);
		// std::cout << "Player moved " << movement.x << "," << movement.y << std::endl;
		lastMovement = movement;
		// std::cout << "Move: " << movement.x << std::endl;
		return;
	}
}

//---------------------------------------------------------------------------------------

// Metoda rysuj�ca posta�
void Character::draw(sf::RenderWindow &window_)
{
	window_.draw(sprite);
}

//---------------------------------------------------------------------------------------

bool Character::collision(Entity *entity)
{
	if (typeid(*entity) == typeid(Tile))
	{
		switch (entity->getID())
		{
		case TileType::STONE_1: // Stone
		case TileType::BRICK_1:
		case TileType::BRICK_2:
		{
			isColliding = true;

			// Collision from right
			if (this->getLastMovement().x > 0)
			{
				this->move(sf::Vector2f(-std::abs(this->getLastMovement().x), 0));

				if (this->getSprite().getPosition().y + this->getSprite().getGlobalBounds().height < groundHeight && isJumping == false)
				{
					this->isFalling = true;
				}
			}

			// Collision from left
			else if (this->getLastMovement().x < 0)
			{
				this->move(sf::Vector2f(std::abs(this->getLastMovement().x), 0));

				if (this->getSprite().getPosition().y + this->getSprite().getGlobalBounds().height < groundHeight && isJumping == false)
				{
					this->isFalling = true;
				}
			}

			// Collision from down
			if (this->getLastMovement().y < 0)
			{
				this->isJumping = false;
				this->isFalling = true;
				this->move(sf::Vector2f(0, std::abs(this->getLastMovement().y)));
			}

			// Kolizja from up
			else if (this->getLastMovement().y > 0)
			{
				this->isJumping = false;
				this->isFalling = false;
				this->move(sf::Vector2f(0, -std::abs(this->getLastMovement().y)));
				this->movement.y = 0;
			}

			break;
		}

		case TileType::LAVA_1:
		case TileType::LAVA_2:
		{
			this->hurt(3);
		}
		case TileType::WATER_1:
		{
			this->slow(1);
		}
		default:
		{
			break;
		}
		}
	}
	else if (typeid(*entity) == typeid(Coin))
	{
		// TODO: add points when interacting with coin
	}
	else if (typeid(*entity) == typeid(Enemy))
	{
		this->hurt(3);
	}

	return true;
}

//---------------------------------------------------------------------------------------