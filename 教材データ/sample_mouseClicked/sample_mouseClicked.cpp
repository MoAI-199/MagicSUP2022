/*
�錾
		void mouseClicked( );
�T�v
		�N���b�N���ꂽ���ɏ��������֐�
����
		�Ȃ�
�߂�l
		�Ȃ�
*/
#include "Magic.h"
MAGIC_BEGIN

VideoPtr video;
bool pause = false;

void setup( ) {
	video = createVideo( "video.mp4" );

}

void draw( ) {
	video->image( 100, 100 );
	if ( pause ) {
		video->pause( );
	} else {
		video->loop( );
	}

}

void mouseClicked( ) {
	pause = !pause;
}

MAGIC_END
