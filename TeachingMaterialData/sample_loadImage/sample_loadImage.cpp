/*
�錾
	ImagePtr loadImage( const char * filename )
�T�v
	�摜�t�@�C�����������Ƀ��[�h���܂�
����
	filename :�@���[�h����摜�A�y�ѓ���t�@�C���̃t�@�C���p�X������ւ̃|�C���^
�߂�l
	�|�P�@�@�@:�@�G���[����
	�|�P�ȊO�@:�@�O���t�B�b�N�̃n���h��
*/

#include "Magic.h"
MAGIC_BEGIN

ImagePtr img;
void setup( ) {
	img = loadImage( "logo.png" );
	image( img, 0, 0 );
}

void draw( ) {

}

MAGIC_END