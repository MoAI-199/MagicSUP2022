/*
�錾
    void rectMode( int mode )
�T�v
    �l�p�̕\���ʒu�̎w����@��ύX���܂��BCENTER�͎l�p�̒��S�̍��W���w�肷�郂�[�h�ł��B
����
    mode : CENTER
�߂�l
    ����
*/
#include "Magic.h"
MAGIC_BEGIN

ImagePtr photoImage;

void setup( ) {
    createCanvas( 600, 600 );
    background( 228 );
    rectMode( CENTER );
}

void draw( ) {
    fill( 100 );
    rotate( 45 );
    rect( 300, 300, 150, 150 );
}


MAGIC_END
