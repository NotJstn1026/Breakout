#include "Brick.h"
#include "GameManager.h"

/// <summary>
/// Constructs a Brick object and initializes it with the specified GameManager.
/// </summary>
/// <param name="a_gameManager">Pointer to the GameManager instance to associate with the Brick.</param>
Brick::Brick(GameManager* a_gameManager, ShapeType a_brickShape) : RectangleGameObject(a_brickShape), m_gameManager(a_gameManager)
{
	
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
	m_size = a_size;
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
/// Returns the position of the brick as a Vector2.
/// </summary>
/// <returns>The position of the brick.</returns>
Vector2 Brick::GetBrickPostion() const
{
	return m_position;
}

void Brick::DestroyBrick()
{
	m_gameManager->DestroyBrick(this);
}

/// <summary>
/// Draws the brick on the screen at its current position and size.
/// </summary>
void Brick::Draw()
{
	DrawRectangle(m_position.x, m_position.y, m_size.x, m_size.y, WHITE);
}
