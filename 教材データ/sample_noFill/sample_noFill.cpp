/*
* �錾 void noFill( )
* �T�v fill�̖�����
* ���� �Ȃ�
* �߂�l �Ȃ�
*/


#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	createCanvas( 600, 400 );
	background( 120 );
}

void draw( ) {
	//�Ԃ��~��`��
	fill( 255, 0, 0 );
	ellipse( 100, 100, 100 );
	//fill�̖�����
	noFill( );
	ellipse( 200, 100, 100 );

}

MAGIC_END
