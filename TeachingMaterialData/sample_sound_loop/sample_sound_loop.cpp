/*
�N���X
	Sound
�錾
	void loop( );
�T�v
	���[�v�Đ�����
����
	�Ȃ�
�߂�l
	�Ȃ�
*/
#include "Magic.h"
MAGIC_BEGIN

SoundPtr sound;
void setup( ) {
	sound = loadSound( "cancel_0.mp3" );
	sound->loop( );
}

void draw( ) {

}

MAGIC_END
