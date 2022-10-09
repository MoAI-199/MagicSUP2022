/*
クラス
	Sprite
宣言
	void setScale( double scale );
概要
	spriteの拡大率を設定する
引数
	double scale ： スプライトの拡大率
戻り値
	なし
*/

#include "Magic.h"
MAGIC_BEGIN
SpritePtr sprite;
SpritePtr sprite_big;

void setup( ) {
	sprite = createSprite( 100, 100 );
	sprite_big = createSprite( 300, 300 );
	sprite_big->setScale( 1.5 );
}

void draw( ) {
	background( 255 );
	drawSprites( );
}

MAGIC_END