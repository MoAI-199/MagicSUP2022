/*
* �錾 int getMouseX( );
* �T�v �}�E�X�̉��̈ʒu���擾����B
* ����  �Ȃ�
* �߂�l �}�E�X�̉��̈ʒu
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
	ellipse( getMouseX( ), 100, 100 );
}

MAGIC_END