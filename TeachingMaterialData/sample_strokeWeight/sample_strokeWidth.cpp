/*
* éŒ¾ void strokeWeight( int weight )
* ŠT—v ˜gü‚Ì‘¾‚³‚ğ•Ï‚¦‚é
* ˆø”  weight : ˜gü‚Ì‘¾‚³
* –ß‚è’l ‚È‚µ
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	createCanvas( 600, 400 );
	background( 255 );
}

void draw( ) {
	//˜gü‚ª×‚¢”’F‚Ì‰~‚ğ•`‰æ
	strokeWeight( 1 );
	ellipse( 100, 100, 100 );

	//˜gü‚Ì‘¾‚­‚µ‚Ä‰~‚ğ•`‰æ
	strokeWeight( 10 );
	ellipse( 300, 100, 100 );
}

MAGIC_END