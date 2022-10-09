/*
�N���X
	Sprite
�錾
	Vec Sprite::getVelocity( );
�T�v
	sprite�̐i�s�����ւ̈ړ��ʂ��擾����
����
	�Ȃ�
�߂�l
	sprite�̐i�s�����ւ̈ړ���
*/

#include "Magic.h"
MAGIC_BEGIN
SpritePtr sprite;
double _velocity_x = 0;
double _velocity_y = 0;
void setup( ) {
	sprite = createSprite( 0, 200 );
	sprite->setVelocity( 0.5, 0.5 );
	_velocity_x = sprite->getVelocity( ).x;
	_velocity_y = sprite->getVelocity( ).y;
}

void draw( ) {
	background( 255 );
	drawSprite( sprite );
	if ( isMousePressed( ) ) {
		sprite->setVelocity( -_velocity_x, -_velocity_y );
	}
}

MAGIC_END
