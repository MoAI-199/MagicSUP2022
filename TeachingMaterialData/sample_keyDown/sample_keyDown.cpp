/*
�錾
	bool keyDown( const char * key_str )
�T�v
	�w�肵��������ɑΉ������L�[��������Ă��邩�H
����
	key_str :
		"LEFT" ���L�[�̍�
		"RIGHT" ���L�[�̉E
		"UP" ���L�[�̏�
		"DOWN" ���L�[�̉�
�߂�l
	������Ă��� : true
	������Ă��Ȃ� : false
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
}

void draw( ) {
	background( 255 );

	if ( keyDown( "LEFT" ) ) {
		text( "LEFT", 0, 0 );
	}
	if ( keyDown( "RIGHT" ) ) {
		text( "RIGHT", 0, 0 );
	}
	if ( keyDown( "UP" ) ) {
		text( "UP", 0, 0 );
	}
	if ( keyDown( "DOWN" ) ) {
		text( "DOWN", 0, 0 );
	}
}

MAGIC_END