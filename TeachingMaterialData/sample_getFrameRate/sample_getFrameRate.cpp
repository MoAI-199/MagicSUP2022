/*
�錾
	int getFrameRate( );
�T�v
	�t���[�����[�g�̎擾
����
	�Ȃ�
�߂�l
	FPS�l
*/
#include "Magic.h"
#include <string>
MAGIC_BEGIN

void setup( ) {

}

void draw( ) {
	background( 255 );
	int rate = getFrameRate( );
	std::string str = std::to_string( rate );
	text( str.c_str( ), 0, 0 );
}

MAGIC_END
