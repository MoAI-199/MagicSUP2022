/*
�錾
	void setFrameRate( int rate );
�T�v
	�t���[�����[�g�̐ݒ�
����
	rate : FPS�l
�߂�l
	�Ȃ�
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	setFrameRate( 60 );
}

int x = 0;

void draw( ) {
	background( 255 );
	x++;
	if ( x == 300 ) {
		setFrameRate( 10 );
	}
	ellipse( x, getHeight( ) / 2, 100 );
}

MAGIC_END
