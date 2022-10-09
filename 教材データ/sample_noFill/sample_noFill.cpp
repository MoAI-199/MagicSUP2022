/*
* éŒ¾ void noFill( )
* ŠT—v fill‚Ì–³Œø‰»
* ˆø” ‚È‚µ
* –ß‚è’l ‚È‚µ
*/


#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	createCanvas( 600, 400 );
	background( 120 );
}

void draw( ) {
	//Ô‚¢‰~‚ğ•`‚­
	fill( 255, 0, 0 );
	ellipse( 100, 100, 100 );
	//fill‚Ì–³Œø‰»
	noFill( );
	ellipse( 200, 100, 100 );

}

MAGIC_END
