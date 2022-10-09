/*
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

void setup( ) {
	createCanvas( 40, 30 );
}

void draw( ) {
	fill( 255, 0, 0 );
	ellipse( 15, 15, 10 );
	loadPixels( );

	for ( int i = 0; i < getHeight( ); i++ ) {
		for ( int j = 0; j < getWidth( ); j++ ) {
			int index = ( j + i * 40 ) * 4;
			if ( getPixel( index ) == 255 ) {
				setPixel( index, 0 );
			}
		}
	}
	updatePixels( );
}

MAGIC_END