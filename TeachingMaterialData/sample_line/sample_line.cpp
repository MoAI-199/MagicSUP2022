/*
�錾
	void line( int x1, int y1, int x2, int y2 );
�T�v
	����`�悵�܂�
����
	x1, y1 : �`�悷����̋N�_���W
	x2, y2 : �`�悷����̏I�_���W
�߂�l
	�Ȃ�
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
}

void draw( ) {
	rotate( 45 );
	translate( getWidth( ) / 2, getHeight( ) / 2 );
	line( 0, 0, -100, -100 );
}

MAGIC_END