/*
�N���X
	Sound
�錾
	int isPlaying( );
�T�v
	�Đ��������ׂ�
����
	�Ȃ�
�߂�l
	�P�@�F�Đ���
�@	�O�@�F�Đ�����Ă��Ȃ�
	�|�P�F�G���[����
*/
#include "Magic.h"
MAGIC_BEGIN

SoundPtr sound;
int count = 0;

void setup( ) {
	sound = loadSound( "mySound.mp3" );
	sound->loop( );
}

void draw( ) {
	if( count % 120 == 0) {
		if ( sound->isPlaying(  ) == 0 ) {
			sound->play( );
		} else if ( sound->isPlaying( ) == 1 ) {
			sound->pause( );
		}
	}

	if ( sound->isPlaying( ) == 0 ) {
		fill( 255, 0, 0 );
		ellipse( getWidth( ) / 2, getHeight( ) / 2, 100 );
	} else if ( sound->isPlaying( ) == 1 ) {
		fill( 0, 0, 255 );
		ellipse( getWidth( ) / 2, getHeight( ) / 2, 100 );
	}
	count++;
}

MAGIC_END
