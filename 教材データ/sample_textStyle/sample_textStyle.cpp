/*
�錾
	void textStyle( const char * style_name );
�T�v
	�����܂��͕�����̕\���X�^�C����ύX���܂��B
����
	style_name : NORMAL
	�@�@�@�@�@�@�@�@�@�@�@�@�@BOLD(����)
	                     ITALIC(�Α�)
						 BOLD_ITALIC(�����Α�)
						 ����L�̂ݎg�p�\�B
�߂�l
	�Ȃ�
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	textStyle( "BOLD" );
	text( "sample", 100, 50 );
	textStyle( "NORMAL" );
	text( "sample", 100, 70 );
	textStyle( "ITALIC" );
	text( "sample", 100, 90 );
	textStyle( "BOLD_ITALIC" );
	text( "sample", 100, 110 );
}

void draw( ) {
	
}

MAGIC_END
