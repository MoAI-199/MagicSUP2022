/*
�N���X
	Sprite
�錾
	void setScale( double scale );
�T�v
	sprite�̊g�嗦��ݒ肷��
����
	double scale �F �X�v���C�g�̊g�嗦
�߂�l
	�Ȃ�
*/

#include "Magic.h"
MAGIC_BEGIN
SpritePtr sprite;
SpritePtr sprite_big;

void setup( ) {
	sprite = createSprite( 100, 100 );
	sprite_big = createSprite( 300, 300 );
	sprite_big->setScale( 1.5 );
}

void draw( ) {
	background( 255 );
	drawSprites( );
}

MAGIC_END