/*
クラス
	Sprite
宣言
	void createSprite( int x, int y );
概要
	spriteを生成する
引数
	int x：X座標
	int y：Y座標
戻り値
	Spriteのデータ
*/
#include "Magic.h"
MAGIC_BEGIN
SpritePtr sprite;
void setup( ) {
	sprite = createSprite( 0, 200 );
}

void draw( ) {
	drawSprite( sprite );
}

MAGIC_END
