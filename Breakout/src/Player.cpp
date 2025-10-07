#include "Player.h"

/// <summary>
/// Initializes a Player object with a starting position and size based on the screen dimensions.
/// </summary>
Player::Player(ShapeType a_playerShape) : RectangleGameObject(a_playerShape)
{
	float startHeight = (float)GetScreenHeight() * 7 / 8; //Take one-eighth of the screen height for the start point
	m_size = Vector2{ (float)GetScreenWidth() / 8, 8 };
	float startPostionX = ((float)GetScreenWidth() / M_HALFSCREEN);
	m_position = Vector2{ startPostionX - m_size.x * 0.5f, startHeight };
}

Player::~Player()
{
}

/// <summary>
/// Returns the current position of the player.
/// </summary>
/// <returns>The player's position as a Vector2 object.</returns>
Vector2 Player::GetPostion() const
{
	return m_position;
}

/// <summary>
/// Returns the size of the player as a Vector2.
/// </summary>
/// <returns>The size of the player represented as a Vector2 object.</returns>
Vector2 Player::GetSize() const
{
	return m_size;
}

/// <summary>
/// Draws the player on the screen at its current position and size.
/// </summary>
void Player::Draw()
{
	DrawRectangle(m_position.x, m_position.y, m_size.x, m_size.y, WHITE);
}

/// <summary>
/// Updates the player's movement based on keyboard input.
/// </summary>
void Player::Update()
{
	if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
	{
		Movement(MOVEMENTDIRECTION::DM_LEFT);
	}

	if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
	{
		Movement(MOVEMENTDIRECTION::DM_RIGHT);
	}
}

Rectangle Player::ReturnRectangle()
{
	Rectangle rec = { m_position.x,m_position.y,m_size.x,m_size.y };
	return rec;
}

/// <summary>
/// Updates the player's horizontal position based on the specified movement direction.
/// </summary>
/// <param name="a_movementDirection">The direction in which the player should move (e.g., left or right).</param>
void Player::Movement(MOVEMENTDIRECTION a_movementDirection)
{
	float newPostionX{ 0 };
	if (MOVEMENTDIRECTION::DM_LEFT == a_movementDirection)
	{
		m_position.x -= m_speed;
	}
	else
	{
		m_position.x += m_speed;
	}
}