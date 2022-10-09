/*
�N���X
	Video
�錾
	void loadPixel( );
�T�v
	����̃s�N�Z���f�[�^��pixels�Ƀ��[�h���܂��B
����
	�Ȃ�
�߂�l
	�Ȃ�
*/

#include "Magic.h"
MAGIC_BEGIN

VideoPtr video;
void setup( ) {
	video = createVideo( "video.mp4" );
	//createCanvas( 800, 800 );
}

void draw( ) {
	video->loop( );
	video->loadPixels( );

	for ( int i = 0; i < video->getHeight( ); i++ ) {
		for ( int j = 0; j < video->getWidth( ); j++ ) {
			int index = ( j + i * video->getWidth( ) ) * 4;
			if ( video->getPixel( index + 2 ) > 10 ) {
				video->setPixel( index + 1, 255 );
			}
		}
	}

	video->updatePixels( );
}

MAGIC_END