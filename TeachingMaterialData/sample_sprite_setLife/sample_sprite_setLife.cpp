/*
�N���X
	Sprite
�錾
	void setLife( int life );
�T�v
	������܂ł̎��Ԃ�ݒ肷��
����
	life�F������܂ł̕b��
�߂�l
	�Ȃ�
*/

#include "Magic.h"
MAGIC_BEGIN

SpritePtr sprite;

void setup( ) {
	sprite = createSprite( 200, 0 );
	sprite->setLife( 3 );
}

void draw( ) {
	background( 255 );
	drawSprite( sprite );
	drawSprites( );
	
}

MAGIC_END
