/*
クラス
	Sprite
宣言
	void drawSprite( SpritePtr sprite );
概要
	spriteを描画する
引数
	SpritePtr sprite：描画するSpriteデータ
戻り値
	無し
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
