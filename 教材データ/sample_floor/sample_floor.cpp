/*
宣言 double floor( double num )
概要 小数点以下切り捨て
引数	num:数字
戻り値　小数点以下を切り捨てた数字
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
