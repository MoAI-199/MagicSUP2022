/*
�N���X
	Sprite
�錾
	int getPos( );
�T�v
	sprite�̍��W���擾����
����
	�Ȃ�
�߂�l
	sprite�̍��W
*/

#include "Magic.h"
MAGIC_BEGIN
SpritePtr sprite;
SpritePtr sprite2;
void setup( ) {
	sprite = createSprite( 0, 200 );
	sprite2 = createSprite( 200, 400 );
}

void draw( ) {
	int pos_x = ( int )sprite->getPos( ).x;
	int pos_y = ( int )sprite->getPos( ).y;
	background( 255 );
	sprite2->setPos( pos_x, pos_y + 5 );
	drawSprite( sprite );
	drawSprite( sprite2 );
}

MAGIC_END
