/*
�錾
	void imageMode( int mode )
�T�v
	�摜�̕\���ʒu�̎w����@��ύX���܂��B�f�t�H���g��CORNER�ŁA����͍���p�̍��W�Ŏw�肷�郂�[�h�ł��BCORNERS�͍���ƉE���̊p�̍��W���w�肷�郂�[�h�ACENTER�͉摜�̒��S�̍��W���w�肷�郂�[�h�ł��B
����
	mode : CENTER�ACORNERS�ACORNER�̂����ꂩ
�߂�l
	�Ȃ�
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	ImagePtr img = loadImage( "logo.png" );

	imageMode( CORNERS );
	image( img, getWidth( ) / 2, getHeight( ) / 2, getWidth( ), getHeight( ) );

	imageMode( CENTER );
	image( img, getWidth( ) / 2, getHeight( ) / 2, 100, 100 );

	imageMode( CORNER );
	image( img, getWidth( ) / 2, getHeight( ) / 2, 100, 100 );
}

void draw( ) {

}

MAGIC_END