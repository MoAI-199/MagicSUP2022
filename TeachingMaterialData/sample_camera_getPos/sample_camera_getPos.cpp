/*
�N���X
	Camera
�錾
	Global::Vec getPos( )
�T�v
	camera��pos���擾���܂��B
����
	�Ȃ�
�߂�l
	camera��pos
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
	//�L�����o�X�ɉ~��\��
	fill( 0, 255, 0 );
	ellipse( 100, 100, 100 );
	//�J�������\�����Ă�����W�ɉ~��\��
	fill( 255, 0, 0 );
	ellipse( c_pos.x + 100 , c_pos.y + 100, 50 );
}

MAGIC_END