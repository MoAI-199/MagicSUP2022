/*
* �錾 void stroke( int r, int g, int b  )
* �T�v �g���̕\��
*	   RGB�l���w�肵�ĐF��ύX�ł���
* ����  r : �Ԃ̐��� (0 �` 255)
* �@�@�@g : �΂̐��� (0 �` 255)
* �@�@�@b : �̐��� (0 �` 255)
* �߂�l �Ȃ�
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	createCanvas( 600, 400 );
	background( 255 );
}

void draw( ) {
	//�g���̂Ȃ��ԐF�̉~��`��
	noStroke( );
	fill( 255, 0, 0 );
	ellipse( 100, 100, 100 );
	
	//�F�̘g���̉~��`��
	stroke(0, 0, 255 );
	fill( 255, 0, 0 );
	ellipse( 200, 100, 100 ); 
}

MAGIC_END

