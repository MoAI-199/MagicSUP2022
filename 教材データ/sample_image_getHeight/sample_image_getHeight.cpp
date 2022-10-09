/*
ƒNƒ‰ƒX
	Image
éŒ¾
		int getHeight( );
ŠT—v
		‰æ‘œ‚Ìc•‚ðŽæ“¾‚·‚é
ˆø”
		‚È‚µ
–ß‚è’l
		‰æ‘œ‚Ìc•
*/
#include "Magic.h"
MAGIC_BEGIN

ImagePtr image;

void setup( ) {
	image = loadImage( "logo.png" );
}

void draw( ) {
	int height = image->getHeight( );
}

MAGIC_END
