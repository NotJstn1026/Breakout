#include "Brick.h"
#include "GameManager.h"


Brick::Brick(GameManager* a_gameManager, ShapeType a_brickShape) : RectangleGameObject(a_brickShape), m_gameManager(a_gameManager)
{
	
}

Brick::~Brick()
{
}


void Brick::SetBrickPosition(Vector2 a_position)
{
	m_position = a_position;
}


void Brick::SetBrickSize(Vector2 a_size)
{
	m_size = a_size;
}


void Brick::SetBrickPostionAndSize(Vector2 a_postion, Vector2 a_size)
{
	SetBrickPosition(a_postion);
	SetBrickSize(a_size);
}


Vector2 Brick::GetBrickPostion() const
{
	return m_position;
}

void Brick::DestroyBrick()
{
	m_gameManager->DestroyBrick(this);
}

void Brick::Draw()
{
	DrawRectangle(m_position.x, m_position.y, m_size.x, m_size.y, m_color);
}
