/*
�錾
		void pause( );
�T�v
		����̈ꎞ��~
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
	video->image( 100, 100 );

	video->pause( );
}

MAGIC_END
