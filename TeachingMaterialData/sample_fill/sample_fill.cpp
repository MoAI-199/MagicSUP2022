/*
�錾
	void fill( int r,int g, int b ,int alpha )
	void fill( int r,int g, int b )
	void fill( int grey ,int alpha )
	void fill( int grey )
�T�v
	�F��ύX�ł���
	alpha�l���w�肷�鎖�œ����x��ύX�ł���
����
	r : �Ԃ̐��� (0 �` 255)
	g : �΂̐��� (0 �` 255)
	b : �̐��� (0 �` 255)
	alpha : �����x ( 0 �` 255 )
	gray : �O���[�X�P�[�� (0 �` 255)
�߂�l
	�Ȃ�
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	createCanvas( 600, 400 );
	background( 255 );
	//�ԐF�̉~�𓧖��x20�ŕ`��
	fill( 255, 0, 0, 20 );
	ellipse( 100, 100, 100 );
	//255�����鐔�l�̏ꍇ255�ɗ}������
	fill( 500, 500, 0 );
	ellipse( 100, 200, 100 );
}

void draw( ) {
	//�F�̉~��`��
	fill( 0, 0, 255 );
	ellipse( 200, 100, 100 );
	//�O���[�X�P�[����ݒ肵�ĉ~��`��
	fill( 80 );
	ellipse( 300, 100, 100 );

}

MAGIC_END

