/*
�N���X
	Sprite
�錾
	void setPos( int x, int y );
�T�v
	sprite�̍��W��ݒ肷��
����
	int x �F X�̍��W
	int y �F Y�̍��W
�߂�l
	�Ȃ�
*/

#include "Magic.h"
MAGIC_BEGIN
SpritePtr sprite;
void setup( ) {
	sprite = createSprite( 0, 200 );
}

void draw( ) {
	background( 255 );
	sprite->setPos( 0, 0 );
	drawSprite( sprite );
}

MAGIC_END