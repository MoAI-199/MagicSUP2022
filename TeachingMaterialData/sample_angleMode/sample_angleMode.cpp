/*
�錾
	void angleMode( int mode )
�T�v
	�p�x��DEGREES��RADIANS�ɐݒ肷��B�@RADIANS�̓f�t�H���g�B
����
	mode : DEGREES
				RADIANS
�߂�l
	�Ȃ�
*/

#include "Magic.h"
MAGIC_BEGIN

int angle = 0;

void setup( ) {
	createCanvas( 500, 500 );
	angleMode( DEGREES );
}

void draw( ) {
	background( 255 );
	int width = getWidth( );
	int height = getHeight( );
	int mouse_x = getMouseX( );
	translate( width / 2, height / 2 );
	rotate( mouse_x );
	line( 0, 0, 100, 100 );
}

MAGIC_END