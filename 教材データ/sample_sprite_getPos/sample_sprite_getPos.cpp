/*
クラス
	Sprite
宣言
	int getPos( );
概要
	spriteの座標を取得する
引数
	なし
戻り値
	spriteの座標
*/

#include "Magic.h"
MAGIC_BEGIN
SpritePtr sprite;
SpritePtr sprite2;
void setup( ) {
	sprite = createSprite( 0, 200 );
	sprite2 = createSprite( 200, 400 );
}

void draw( ) {
	int pos_x = ( int )sprite->getPos( ).x;
	int pos_y = ( int )sprite->getPos( ).y;
	background( 255 );
	sprite2->setPos( pos_x, pos_y + 5 );
	drawSprite( sprite );
	drawSprite( sprite2 );
}

MAGIC_END
