/*
�錾 int getHeight( );
�T�v ��ʂ̏c���̎擾
����  �Ȃ�
�߂�l ��ʂ̏c��
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	createCanvas( 600, 400 );
	background( 255 );
}

void draw( ) {
	//�~����ʂ̏㉺�ϓ��̈ʒu�ɕ`�悳����
	ellipse( 100, getHeight( ) / 2, 100 );
}

MAGIC_END