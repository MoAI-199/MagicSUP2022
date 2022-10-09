/*
�N���X�@Group
�錾 void collide�i SpritePtr sprite �j
�T�v Group����Spriet�̓����蔻��B
����  sprite::�^�[�Q�b�g
�߂�l �Ȃ�
*/

#include "Magic.h"
MAGIC_BEGIN

GroupPtr group;
SpritePtr sprite;

void setup( ) {
	createCanvas( 600, 400 );
	background( 255 );
	group = createGroup( );

	SpritePtr sp = createSprite( 200, 200 );
	group->add( sp );

	int mouse_x = getMouseX( );
	int mouse_y = getMouseY( );
	sprite = createSprite( mouse_x, mouse_y );

}

void draw( ) {
	background( 0 );
	int mouse_x = getMouseX( );
	int mouse_y = getMouseY( );
	sprite->setPos( mouse_x, mouse_y );

	group->collide( sprite );
	drawSprites( );

	std::string str = "x:" + std::to_string( mouse_x ) + " y:" + std::to_string( mouse_y );
	text( str.c_str( ), 0, 0 );
}

MAGIC_END