/*
�N���X
	Sprite
�錾
	void setIndex( int index );
�T�v
	�C���f�b�N�X�ԍ���ݒ肷��
����
	index�F�C���f�b�N�X�ԍ��̐��l
�߂�l
	�Ȃ�
*/

#include "Magic.h"
MAGIC_BEGIN

SpritePtr sprite[ 4 ] = {};

void setup( ) {
	for ( int i = 0; i < 4; i++ ) {
		sprite[ i ] = createSprite( 150 * i + 100, 200 );
		sprite[ i ]->setIndex( i );
	}
}

void draw( ) {
	for ( int i = 0; i < 4; i++ ) {
		if ( sprite[ i ]->getIndex( ) == 1 ) {
			sprite[ i ]->remove( );
		}
	}
	drawSprites( );
}

MAGIC_END
