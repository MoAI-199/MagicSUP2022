/*
�N���X
	Sprite
�錾
	void drawSprites( );
�T�v
	sprite�����ׂĕ`�悷��
����
	�Ȃ�
�߂�l
	����
*/
#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	SpritePtr sprite1 = createSprite( 0, 200 );
	SpritePtr sprite2 = createSprite( 300, 500 );
}

void draw( ) {
	drawSprites( );
}

MAGIC_END
