/*
�N���X
	Camera
�錾
	Global::Vec setPos( Global::Vec pos )
�T�v
	camera��pos��ύX���܂��B
����
	camera��pos
�߂�l
	�Ȃ�
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	createCanvas( 600, 400 );
	background( 120 );
}

void draw( ) {
	background( 120 );
	CameraPtr camera = getCamera( );
	Vec add;
	add.x = 0;
	add.y = 1;
	Vec c_pos = camera->getPos( );
	c_pos.x += add.x;
	c_pos.y += add.y;
	camera->setPos( c_pos );
	ellipse( 100, 100, 100 );
}

MAGIC_END