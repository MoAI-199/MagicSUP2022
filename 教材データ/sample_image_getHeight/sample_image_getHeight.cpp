/*
�N���X
	Image
�錾
		int getHeight( );
�T�v
		�摜�̏c�����擾����
����
		�Ȃ�
�߂�l
		�摜�̏c��
*/
#include "Magic.h"
MAGIC_BEGIN

ImagePtr image;

void setup( ) {
	image = loadImage( "logo.png" );
}

void draw( ) {
	int height = image->getHeight( );
}

MAGIC_END
