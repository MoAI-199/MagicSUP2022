/*
* éŒ¾ void noStroke( )
* ŠT—v ˜gü‚ğÁ‚·
* ˆø” ‚È‚µ
* –ß‚è’l ‚È‚µ
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	createCanvas( 600, 400 );
	background( 255 );
}

void draw( ) {
	//˜gü‚Ì‚ ‚é‰~‚ğ•`‰æ
	fill( 255, 0, 0 );
	ellipse( 100, 100, 100 );
	//˜gü‚Ì‚È‚¢‰~‚ğ•`‰æ
	noStroke( );
	ellipse( 200, 100, 100 );
}

MAGIC_END

