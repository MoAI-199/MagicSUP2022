/*
�錾 double sin( double angle )
�T�v angle��sin�Ƃ�Ԃ�
���� angle:�p�x
�߂�l sin��
*/
#include "Magic.h"
MAGIC_BEGIN

double angle = 0;
int positionX = 500;
int positionY = 0;

void setup( ) {
	fill( 255, 255, 0 );
	noStroke( );
}

void draw( ) {
	background( 255 );
	positionY = getHeight( ) / 2 + ( int )sin( angle ) * 150;
	angle += 0.05;
	ellipse( positionX, positionY, 100 );
}

MAGIC_END
