/*
�錾 
	 void background( int r, int g, int r)
	 void background( int r, int g, int r, int alpha)
	 void background( int gray )
	 void background( int gray , int alpha )
	 void background( ImagePtr img )
	 void background( ImagePtr img , int alpha )
�T�v 
	�w�i�̐F��ύX�ł���
	�w�i��alpha�l���w�肷�鎖�œ����x��ύX�ł���
����
	r : �Ԃ̐��� (0 �` 255)
	g : �΂̐��� (0 �` 255)
	b : �̐��� (0 �` 255)
	alpha : �����x ( 0 �` 255 )
	gray : �O���[�X�P�[�� (0 �` 255)�@�@�@
	img�F�w�i�摜
�߂�l
	�Ȃ�

*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	//�L�����o�X�̃T�C�Y��ݒ�
	createCanvas( 600, 400 );
	//�ԐF�̔w�i��ݒ�
	background( 255, 0, 0 );
	//���̔������̔w�i��ݒ�
	background( 0, 128 );
	ImagePtr img = loadImage( "photo05.png" );
	background( img );
}

void draw( ) {

}

MAGIC_END