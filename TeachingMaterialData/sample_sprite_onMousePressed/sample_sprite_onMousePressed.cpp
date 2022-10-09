/*
ƒNƒ‰ƒX
	Sprite
éŒ¾
	void onMousePressed( Instance* _inst, void( Instance::* func )( ) )
	void onMousePressed( Instance* _inst, void( Instance::* func )( SpritePtr myself ) )
ŠT—v
	ƒXƒvƒ‰ƒCƒg‚ð‰Ÿ‚µ‚½‚Æ‚«‚Éˆ—‚³‚ê‚éŠÖ”‚ð“o˜^‚Å‚«‚é
ˆø”
	Instance* _inst        : this‚Æ‹L“ü‚µ‚Ä‚­‚¾‚³‚¢
	void( Instance::*func ): “o˜^‚·‚éŠÖ”
–ß‚è’l
	‚È‚µ
*/

#include "Magic.h"
MAGIC_BEGIN
SpritePtr sprite;
SpritePtr sprite2;

void setup( ) {
	sprite = createSprite( 200, 0 );
	sprite2 = createSprite( 400, 0 );
	sprite->setVelocity( sprite->getVelocity( ).x, 0.5 );
	sprite2->setVelocity( sprite2->getVelocity( ).x, 0.5 );
	sprite->onMousePressed( this, &Instance::deleted2 );
	sprite2->onMousePressed( this, &Instance::deleted2 );
}

void draw( ) {
	background( 255 );
	drawSprites( );
}

void deleted1( ) {
	sprite->setPos( 0, ( int )sprite->getPos( ).y );
}

void deleted2( SpritePtr myself ) {
	myself->setPos( ( int )myself->getPos( ).x, 0 );
}

MAGIC_END
