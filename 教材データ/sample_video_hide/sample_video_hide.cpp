/*
�錾
		void hide( );
�T�v
		������\���ɂ��܂��B
����
		�Ȃ�
�߂�l
		�Ȃ�
*/
#include "Magic.h"
MAGIC_BEGIN

VideoPtr video;

void setup( ) {
	video = createVideo( "video.mp4" );
}

void draw( ) {
	background( 255 );
	video->loop( );
	if ( isMousePressed( ) ) {
		video->hide( );
	} else {
		video->image( 100, 100 );
	}
}


MAGIC_END

/*�@����
[hide]�̏�ɕK��[background]�������Ă��������B
*/