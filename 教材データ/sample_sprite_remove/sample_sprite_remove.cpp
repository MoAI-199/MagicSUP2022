/*
�N���X
	Sprite
�錾
	void remove( );
�T�v
	sprite���폜����
����
	�Ȃ�
�߂�l
	�Ȃ�
*/

#include "Magic.h"
MAGIC_BEGIN

SpritePtr sprite;

void setup( ) {
	sprite = createSprite( 200, 0 );
}

void draw( ) {
	background( 255 );
	if ( isMousePressed( ) ) {
		sprite->remove( );

	}
	drawSprite( sprite );
	drawSprites( );
}

MAGIC_END
