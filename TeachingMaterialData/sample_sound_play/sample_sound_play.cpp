/*
�N���X
	Sound
�錾
	void play( );
�T�v
	�Đ�����
����
	�Ȃ�
�߂�l
	�Ȃ�
*/
#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	SoundPtr sound = loadSound( "mySound.mp3" );
	sound->play( );
}

void draw( ) {

}

MAGIC_END
