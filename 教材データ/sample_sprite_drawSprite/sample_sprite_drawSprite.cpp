/*
�N���X
	Sprite
�錾
	void drawSprite( SpritePtr sprite );
�T�v
	sprite��`�悷��
����
	SpritePtr sprite�F�`�悷��Sprite�f�[�^
�߂�l
	����
*/
#include "Magic.h"
MAGIC_BEGIN
SpritePtr sprite;
void setup( ) {
	sprite = createSprite( 0, 200 );
}

void draw( ) {
	drawSprite( sprite );
}

MAGIC_END
