/*
�錾 int getWidth( );
�T�v ��ʂ̉����̎擾
����  �Ȃ�
�߂�l ��ʂ̉���
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	createCanvas( 600, 400 );
	background( 255 );
}

void draw( ) {
	//�~����ʂ̍��E�ϓ��̈ʒu�ɕ`�悳����
	ellipse( getWidth( ) / 2, 100, 100 );
}

MAGIC_END