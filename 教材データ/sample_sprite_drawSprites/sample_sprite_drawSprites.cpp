/*
クラス
	Sprite
宣言
	void drawSprites( );
概要
	spriteをすべて描画する
引数
	なし
戻り値
	無し
*/
#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	SpritePtr sprite1 = createSprite( 0, 200 );
	SpritePtr sprite2 = createSprite( 300, 500 );
}

void draw( ) {
	drawSprites( );
}

MAGIC_END
