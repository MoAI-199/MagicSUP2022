/*
�N���X
	Image
�錾
	Vec image::getPos( );
�T�v
	Image�̍��W���擾���܂��B
����
	�Ȃ��B
�߂�l
	Image�̍��W�B
*/
#include "Magic.h"
MAGIC_BEGIN

ImagePtr img;
void setup( ) {
	img = loadImage( "logo.png" );
	image( img, 40, 20 );
}

void draw( ) {
	int pos_x = ( int )img->getPos( ).x;
	int pos_y = ( int )img->getPos( ).y;
	fill( 255, 0, 0 );
	rect( pos_x, pos_y, 50, 50);
}

MAGIC_END
