/*
�錾
	bool isKeyDown( int key_code )
�T�v
		����̃L�[��������Ă��邩��Ԃ��܂��B
����
	key_code : LEFT_ARROW�ARIGHT_ARROW�AUP_ARROW�ADOWN_ARROW�̂����ꂩ
�߂�l
	�w�肵���L�[��������Ă��邩
*/

#include "Magic.h"
MAGIC_BEGIN

int x = 0;
int y = 250;

void setup( ) {

}

void draw( ) {
	background( 120 );
	fill( 255, 0, 0 );
	ellipse( x, y, 100 );
	if ( isKeyDown( LEFT_ARROW ) ) {
		x -= 10;
	}
	if ( isKeyDown( RIGHT_ARROW ) ) {
		x += 10;
	}
}

MAGIC_END