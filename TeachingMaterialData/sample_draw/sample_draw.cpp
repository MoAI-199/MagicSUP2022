/*
* �錾 void draw( )
* �T�v �v���O��������~����܂ŘA���I�ɌĂяo�����
* ����  �Ȃ�
* �߂�l �Ȃ�
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	createCanvas( 600, 400 );
	background( 255 );
}

void draw( ) {
	fill( 255, 0, 0 );
	ellipse( getMouseX( ), getMouseY( ), 100 );
}

MAGIC_END

