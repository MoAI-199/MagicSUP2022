/*
クラス
	Sprite
宣言
	double getScale( );
概要
	spriteの拡大率を取得する
引数
	なし
戻り値
	スプライトの拡大率
*/

#include "Magic.h"
MAGIC_BEGIN
SpritePtr sprite = nullptr;
SpritePtr sprite_big = nullptr;

void setup( ) {
	sprite = createSprite( 100, 100 );
	sprite_big = createSprite( 300, 300 );
	sprite_big->setScale( 1.5 );
}

void draw( ) {
	background( 255 );
	double scale = sprite_big->getScale( );
	drawSprites( );
}

MAGIC_END