/*
�N���X
	Image
�錾
	void setPos( int x, int y );
�T�v
	Image�̍��W��ݒ肵�܂��B
����
	int x�FImage��X���W�B
	int y�FImage��Y���W�B
�߂�l
	�Ȃ��B
*/
#include "Magic.h"
MAGIC_BEGIN

ImagePtr img;
void setup( ) {
	img = loadImage( "logo.png" );
	img->setPos( 200, 200 );
}

void draw( ) {
	int pos_x = ( int )img->getPos( ).x;
	int pos_y = ( int )img->getPos( ).y;
	image( img, pos_x, pos_y );

}

MAGIC_END
