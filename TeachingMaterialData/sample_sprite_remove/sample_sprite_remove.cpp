/*
クラス
	Sprite
宣言
	void remove( );
概要
	spriteを削除する
引数
	なし
戻り値
	なし
*/

#include "Magic.h"
MAGIC_BEGIN

SpritePtr sprite;

void setup( ) {
	sprite = createSprite( 200, 0 );
}

void draw( ) {
	background( 255 );
	if ( isMousePressed( ) ) {
		sprite->remove( );

	}
	drawSprite( sprite );
	drawSprites( );
}

MAGIC_END
