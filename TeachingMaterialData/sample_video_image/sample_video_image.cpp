/*
�錾
		void image( int x, int y );
�T�v
		����t�@�C���̍Đ�
����
		    x :  �����\������x���W 
		    y :  �����\������y���W 
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
}

MAGIC_END
