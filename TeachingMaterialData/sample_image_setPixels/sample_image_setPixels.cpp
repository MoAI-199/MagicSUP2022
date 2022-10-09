/*
�N���X
	Image
�錾
	void setPixel( int index, int color );
�T�v
	index�Ŏw�肵���A�摜�̃s�N�Z���̐F��color�ɕύX���܂��B
����
	index�F�s�N�Z���̗v�f�ԍ�
	color�F�F
�߂�l
	�Ȃ�
*/

#include "Magic.h"
MAGIC_BEGIN

ImagePtr img;
void setup( ) {
	img = loadImage( "test_pixel.png" );
	image( img, 20, 20 );
}

void draw( ) {
	img->loadPixels( );

	for ( int i = 0; i < img->getHeight( ); i++ ) {
		for ( int j = 0; j < img->getWidth( ); j++ ) {
			int index = ( j + i * img->getWidth( ) ) * 4;
			if ( img->getPixel( index ) == 255 ) {
				img->setPixel( index, 0 );
			}
		}
	}

	img->updatePixels( );
}

MAGIC_END