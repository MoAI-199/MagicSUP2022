/*
�錾 double cos( double angle )
�T�v angle��cos�Ƃ�Ԃ�
���� angle:�p�x
�߂�l cos��
*/
#include "Magic.h"
MAGIC_BEGIN

double angle = 0;
int position_x = 0;
int position_y = 250;

void setup( ) {
	fill( 255, 255, 0 );
	noStroke( );
}

void draw( ) {
	background( 255 );
	position_x = getWidth( ) / 2 + floor( cos( angle ) * 150 );
	angle += 0.05;
	ellipse( position_y, position_y, 100 );
}

MAGIC_END
