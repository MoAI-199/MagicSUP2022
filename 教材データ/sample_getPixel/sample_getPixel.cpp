/*
�錾
	int getPixel( int index )
�T�v
	index�Ŏw�肵���s�N�Z���̐F���擾���܂��B
����
	index�F�s�N�Z���̗v�f�ԍ�
�߂�l
	�F�̒l�i0�`255�j
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