/*
�N���X
	Image
�錾
		int getWidth( );
�T�v
		�摜�̉������擾����
����
		�Ȃ�
�߂�l
		�摜�̉���
*/
#include "Magic.h"
MAGIC_BEGIN

ImagePtr image;

void setup( ) {
	image = loadImage( "logo.png" );
}

void draw( ) {
	int width = image->getWidth(  );
}

MAGIC_END
