/*
�N���X�@Group
�錾 void add�i�@SpritePtr sprite �j
�T�v Group�ɐV����Spriet��ǉ�����B
����  sprite:Group�ɓo�^����Sprite
�߂�l �Ȃ�
*/

#include "Magic.h"
MAGIC_BEGIN

GroupPtr group;

void setup( ) {
	createCanvas( 600, 400 );
	background( 255 );
	group = createGroup( );
}

void draw( ) {
	background( 0 );
	int group_size = group->getSize( );
	for ( int i = 0; i < group_size; i++ ) {
		SpritePtr spr = group->getSprite( i );
		int sprite_pos_y = ( int )spr->getPos( ).y;
		int screen_height = getHeight( );
		if ( sprite_pos_y > screen_height ) {
			spr->setPos( ( int )spr->getPos( ).x, 0 );
		}
	}
	drawSprites( );
}

void mouseClicked( ) {
	int mouse_x = getMouseX( );
	int mouse_y = getMouseY( );
	SpritePtr sprite = createSprite( mouse_x, mouse_y );
	sprite->setVelocity( sprite->getVelocity( ).x, 2 );
	group->add( sprite );
}
MAGIC_END