/*
クラス
	Sprite
宣言
	void onMousePressed( Instance* _inst, void( Instance::* func )( ) )
	void onMousePressed( Instance* _inst, void( Instance::* func )( SpritePtr myself ) )
概要
	スプライトを押したときに処理される関数を登録できる
引数
	Instance* _inst        : thisと記入してください
	void( Instance::*func ): 登録する関数
戻り値
	なし
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
