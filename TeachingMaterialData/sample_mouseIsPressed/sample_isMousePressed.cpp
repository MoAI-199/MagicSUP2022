/*
* �錾 bool isMousePressed( );
* �T�v �}�E�X��������Ă��邩
* ����  �Ȃ�
* �߂�l true : ������Ă���
�@�@�@�@ false: ������Ă��Ȃ�
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	createCanvas( 600, 400 );
	background( 255 );
}

void draw( ) {
	background( 255 );
	if ( isMousePressed( ) ) {
		fill( 0, 0, 255, 20 );
		ellipse( 300, 100, 100 );
	}
}

MAGIC_END