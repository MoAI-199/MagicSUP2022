/*
�錾
	void textAlign( align );
�T�v
	������\������ʒu�̑�������ݒ肵�܂��B������(LEFT)�A��������(CENTER)�A�E����(RIGHT)��3��ނ���I�ׂ܂��B
����
	align : LEFT,CENTER,RIGHT�̂����ꂩ
�߂�l
	�Ȃ�
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	textAlign( LEFT );
	text( "LEFT", getWidth( ) / 2, 100 );
	textAlign( CENTER );
	text( "CENTER", getWidth( ) / 2, 200 );
	textAlign( RIGHT );
	text( "RIGHT", getWidth( ) / 2, 300 );
}

void draw( ) {
}

MAGIC_END
