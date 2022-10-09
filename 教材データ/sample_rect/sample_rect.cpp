/*
�錾
	void rect( int x, int y, int w, int h );
�T�v
	�l�p�`��`�悵�܂�
����
	x : �l�p�`��x���W
	y : �l�p�`��y���W
	w : �l�p�`�̕�
	h : �l�p�`�̍���
�߂�l
	�Ȃ�
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	background( 0 );
	angleMode( DEGREES );
	
}

void draw( ) {

	rotate( 45 );
	rect( 100, 0, 60, 60 ); // Draw white rectangle using RADIUS mode

	fill( 100 );
	rotate( 90 );
	rect( 100, 0, 60, 60 ); // Draw gray rectangle using CENTER mode

}

MAGIC_END
