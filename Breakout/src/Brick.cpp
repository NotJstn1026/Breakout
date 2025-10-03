#include "Brick.h"

/// <summary>
/// Constructs a Brick object and initializes it with the specified GameManager.
/// </summary>
/// <param name="a_gameManager">Pointer to the GameManager instance to associate with the Brick.</param>
Brick::Brick(GameManager* a_gameManager)
{
	m_gameManager = a_gameManager;
}

Brick::~Brick()
{
}

/// <summary>
/// Sets the position of the brick.
/// </summary>
/// <param name="a_position">The new position to assign to the brick.</param>
void Brick::SetBrickPosition(Vector2 a_position)
{
	m_position = a_position;
}

/// <summary>
/// Sets the size of the brick.
/// </summary>
/// <param name="a_size">The new size of the brick as a Vector2.</param>
void Brick::SetBrickSize(Vector2 a_size)
{
	m_brickSize = a_size;
}

/// <summary>
/// Sets the position and size of the brick.
/// </summary>
/// <param name="a_postion">The new position of the brick as a Vector2.</param>
/// <param name="a_size">The new size of the brick as a Vector2.</param>
void Brick::SetBrickPostionAndSize(Vector2 a_postion, Vector2 a_size)
{
	SetBrickPosition(a_postion);
	SetBrickSize(a_size);
}

/// <summary>
/// Sets the state of the brick to active or inactive.
/// </summary>
/// <param name="a_active">True to set the brick as active; false to set it as inactive.</param>
void Brick::SetBrickState(bool a_active)
{
	m_state = a_active;
}

/// <summary>
/// Returns the position of the brick as a Vector2.
/// </summary>
/// <returns>The position of the brick.</returns>
Vector2 Brick::GetBrickPostion() const
{
	return m_position;
}

/// <summary>
/// Returns the current state of the brick.
/// </summary>
/// <returns>True if the brick is in the active state; otherwise, false.</returns>
bool Brick::GetBrickState() const
{
	return m_state;
}

/// <summary>
/// Draws the brick on the screen at its current position and size.
/// </summary>
void Brick::Draw()
{
	DrawRectangle(m_position.x, m_position.y, m_brickSize.x, m_brickSize.y, WHITE);
}
