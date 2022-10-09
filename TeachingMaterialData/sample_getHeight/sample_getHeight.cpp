/*
éŒ¾ int getHeight( );
ŠT—v ‰æ–Ê‚Ìc•‚Ìæ“¾
ˆø”  ‚È‚µ
–ß‚è’l ‰æ–Ê‚Ìc•
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	createCanvas( 600, 400 );
	background( 255 );
}

void draw( ) {
	//‰~‚ğ‰æ–Ê‚Ìã‰º‹Ï“™‚ÌˆÊ’u‚É•`‰æ‚³‚¹‚é
	ellipse( 100, getHeight( ) / 2, 100 );
}

MAGIC_END