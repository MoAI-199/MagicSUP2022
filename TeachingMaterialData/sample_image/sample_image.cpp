/*
�錾
	void image( int img, int x, int y)
	void image( int img, int x, int y, int width, int height )
�T�v
	�摜����ʂɕ\�����܂�
����
	img : �\������摜
	x : �\���ʒu��x���W
	y : �\���ʒu��y���W
	width : �\�����̉摜�̕�
	height : �\�����̉摜�̍���
�߂�l
	�Ȃ�
*/

#include "Magic.h"
MAGIC_BEGIN

ImagePtr img;

void setup( ) {
	img = loadImage( "logo.png" );
	image( img, 0, 0 );
	image( img, 100, 100, 200, 200 );
}

void draw( ) {

}

MAGIC_END