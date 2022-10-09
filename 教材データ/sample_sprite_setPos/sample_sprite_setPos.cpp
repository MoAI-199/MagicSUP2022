/*
クラス
	Sprite
宣言
	void setPos( int x, int y );
概要
	spriteの座標を設定する
引数
	int x ： Xの座標
	int y ： Yの座標
戻り値
	なし
*/

#include "Magic.h"
MAGIC_BEGIN
SpritePtr sprite;
void setup( ) {
	sprite = createSprite( 0, 200 );
}

void draw( ) {
	background( 255 );
	sprite->setPos( 0, 0 );
	drawSprite( sprite );
}

MAGIC_END