/*
éŒ¾ double sin( double angle )
ŠT—v angle‚ÌsinƒÆ‚ğ•Ô‚·
ˆø” angle:Šp“x
–ß‚è’l sinƒÆ
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
