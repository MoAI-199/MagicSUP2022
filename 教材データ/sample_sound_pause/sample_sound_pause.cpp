/*
�N���X
	Sound
�錾
	void pause( );
�T�v
	��~����
����
	�Ȃ�
�߂�l
	�Ȃ�
*/
#include "Magic.h"
MAGIC_BEGIN

SoundPtr sound;
void setup( ) {
	sound = loadSound( "mySound.mp3" );
	sound->play( );
}

void draw( ) {
	if ( isMousePressed( ) ) {
		sound->pause( );
	}
}
MAGIC_END
