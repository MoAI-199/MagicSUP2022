/*
* �錾 void strokeWeight( int weight )
* �T�v �g���̑�����ς���
* ����  weight : �g���̑���
* �߂�l �Ȃ�
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	createCanvas( 600, 400 );
	background( 255 );
}

void draw( ) {
	//�g�����ׂ����F�̉~��`��
	strokeWeight( 1 );
	ellipse( 100, 100, 100 );

	//�g���̑������ĉ~��`��
	strokeWeight( 10 );
	ellipse( 300, 100, 100 );
}

MAGIC_END