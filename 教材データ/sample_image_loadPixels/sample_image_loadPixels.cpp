/*
�N���X
	Image
�錾
		void loadPixels( );
�T�v
		�摜�̃s�N�Z���f�[�^��pixels�Ƀ��[�h���܂��B
����
		�Ȃ�
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
