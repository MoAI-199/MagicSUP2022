/*
�N���X
	Sprite
�錾
	double getScale( );
�T�v
	sprite�̊g�嗦���擾����
����
	�Ȃ�
�߂�l
	�X�v���C�g�̊g�嗦
*/

#include "Magic.h"
MAGIC_BEGIN
SpritePtr sprite = nullptr;
SpritePtr sprite_big = nullptr;

void setup( ) {
	sprite = createSprite( 100, 100 );
	sprite_big = createSprite( 300, 300 );
	sprite_big->setScale( 1.5 );
}

void draw( ) {
	background( 255 );
	double scale = sprite_big->getScale( );
	drawSprites( );
}

MAGIC_END