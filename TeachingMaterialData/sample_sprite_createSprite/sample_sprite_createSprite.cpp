/*
�N���X
	Sprite
�錾
	void createSprite( int x, int y );
�T�v
	sprite�𐶐�����
����
	int x�FX���W
	int y�FY���W
�߂�l
	Sprite�̃f�[�^
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
