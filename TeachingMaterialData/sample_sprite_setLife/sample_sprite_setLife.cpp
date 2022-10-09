/*
クラス
	Sprite
宣言
	void setLife( int life );
概要
	消えるまでの時間を設定する
引数
	life：消えるまでの秒数
戻り値
	なし
*/

#include "Magic.h"
MAGIC_BEGIN

SpritePtr sprite;

void setup( ) {
	sprite = createSprite( 200, 0 );
	sprite->setLife( 3 );
}

void draw( ) {
	background( 255 );
	drawSprite( sprite );
	drawSprites( );
	
}

MAGIC_END
