/*
�錾 double floor( double num )
�T�v �����_�ȉ��؂�̂�
����	num:����
�߂�l�@�����_�ȉ���؂�̂Ă�����
*/
#include "Magic.h"
MAGIC_BEGIN

double angle = 0;
int positionX = 500;
int positionY = 500;
double size1 = 0;
double size2 = 0;

void setup( ) {
	noStroke( );
}

void draw( ) {
	background( 255 );
	size1 = sin( angle ) * 150;
	size2 = sin( floor( angle ) ) * 150;
	angle += 0.1;
	fill( 255, 0, 0 );
	ellipse( positionX, positionY, ( int )size1 );
	fill( 0, 0, 255 );
	ellipse( positionX + 150, positionY, ( int )size2 );
}
MAGIC_END
