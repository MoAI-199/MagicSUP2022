/*
�N���X
	Video
�錾
		int getWidth( );
�T�v
		����̉������擾����
����
		�Ȃ�
�߂�l
		����̉���
*/
#include "Magic.h"
MAGIC_BEGIN

VideoPtr video;

// �S�̂̏������i�ŏ��Ɉ�񂾂��Ă΂��j
void setup( ) {
	createCanvas( 600, 600 );
	video = createVideo( "video.mp4" );
}


// �v�Z�ƕ\��
void draw( ) {
	fill( 100 );
	rect( 0, video->getHeight( ), video->getWidth( ), video->getHeight( ) );
	video->image( 0, 0 );
}


MAGIC_END
