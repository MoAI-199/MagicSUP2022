/*
�N���X
	Sprite
�錾
	double setVelocity( double velocityX, double velocityX );
�T�v
	sprite�̐i�s�����ւ̈ړ��ʂ�ݒ肷��
����
	double velocityX �F X�����ւ̈ړ���
	double velocityY �F Y�����ւ̈ړ���
�߂�l
	�Ȃ�
*/

#include "Magic.h"
MAGIC_BEGIN
SpritePtr sprite;
void setup( ) {
	sprite = createSprite( 0, 200 );
	sprite->setVelocity( 0.5, 0.5 );
}

void draw( ) {
	background( 255 );
	drawSprite( sprite );
}

MAGIC_END
