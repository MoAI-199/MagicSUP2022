/*
* �錾 void noStroke( )
* �T�v �g��������
* ���� �Ȃ�
* �߂�l �Ȃ�
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	createCanvas( 600, 400 );
	background( 255 );
}

void draw( ) {
	//�g���̂���~��`��
	fill( 255, 0, 0 );
	ellipse( 100, 100, 100 );
	//�g���̂Ȃ��~��`��
	noStroke( );
	ellipse( 200, 100, 100 );
}

MAGIC_END

