/*
* �錾 int getMouseY( );
* �T�v �}�E�X�̏c�̈ʒu���擾
* ����  �Ȃ�
* �߂�l �}�E�X�̏c�̈ʒu
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	createCanvas( 600, 400 );
	background( 255 );
}

void draw( ) {
	//�g���̑������ĉ~��`��
	fill( 255, 0, 0 );
	ellipse( 100, getMouseY( ), 100 );
}

MAGIC_END