/*
�錾  
		VideoPtr createVideo( const char* filename );
�T�v 
		����t�@�C���̃��[�h
����
		filename :�@�������ɓǂ݂��ޓ���t�@�C���̃t�@�C����
�߂�l
		Video�C���X�^���X
*/
#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	VideoPtr video = createVideo( "video.mp4" );
}

void draw( ) {
}

MAGIC_END
