/*
�錾
	void rotate( int angle )
�T�v
	angle�p�����[�^�Ŏw�肳�ꂽ�l�Ő}�`����]�����܂��B
����
	angle = ��]�p
�߂�l
	�Ȃ�
*/

#include "Magic.h"
MAGIC_BEGIN

double angle = 5;

const double PI = 3.1415926535897932384626433832795;

void setup( ) {
	createCanvas( 500, 500 );
	angleMode( RADIANS );
}

void draw( ) {
	background( 220 );

	rotate( 0 );
	fill( 0, 255, 0 );
	line( 100, 0, 52, 52 );
	rotate( PI / 6.0 );  // 30�����v���ɉ�]
	fill( 0, 255, 0 );
	line( 100, 0, 52, 52 );

	rotate( PI / 6.0 );  // �X��30�����v���ɉ�]
	fill( 255, 0, 0 );
	line( 100, 0, 52, 52 );
}

MAGIC_END