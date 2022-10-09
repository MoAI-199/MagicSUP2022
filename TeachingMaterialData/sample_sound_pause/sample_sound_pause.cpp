/*
ƒNƒ‰ƒX
	Sound
éŒ¾
	void pause( );
ŠT—v
	’âŽ~‚·‚é
ˆø”
	‚È‚µ
–ß‚è’l
	‚È‚µ
*/
#include "Magic.h"
MAGIC_BEGIN

SoundPtr sound;
void setup( ) {
	sound = loadSound( "mySound.mp3" );
	sound->play( );
}

void draw( ) {
	if ( isMousePressed( ) ) {
		sound->pause( );
	}
}
MAGIC_END
