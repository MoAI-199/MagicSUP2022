/*
�錾
		void loop( );
�T�v
		��������[�v�����܂��B
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
bool pause = false;

void draw( ) {
	video->image( 100, 100 );
	video->loop( );
}



MAGIC_END
