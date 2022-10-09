/*
�N���X
	Video
�錾
	void setPixel( int index, int color );
�T�v
	index�Ŏw�肵���s�N�Z���̐F��color�ɕύX���܂��B
����
	index�F�s�N�Z���̗v�f�ԍ�
	color�F�F
�߂�l
	�Ȃ�
*/

#include "Magic.h"
MAGIC_BEGIN

VideoPtr video;
void setup( ) {
	video = createVideo( "video.mp4" );
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