/*
éŒ¾
		void pause( );
ŠT—v
		“®‰æ‚ÌˆêŽž’âŽ~
ˆø”
		‚È‚µ
–ß‚è’l
		‚È‚µ
*/
#include "Magic.h"
MAGIC_BEGIN

VideoPtr video;

void setup( ) {
	video = createVideo( "video.mp4" );
}

void draw( ) {
	video->image( 100, 100 );

	video->pause( );
}

MAGIC_END
