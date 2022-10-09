/*
クラス
	Sprite
宣言
	void setIndex( int index );
概要
	インデックス番号を設定する
引数
	index：インデックス番号の数値
戻り値
	なし
*/

#include "Magic.h"
MAGIC_BEGIN

SpritePtr sprite[ 4 ] = {};

void setup( ) {
	for ( int i = 0; i < 4; i++ ) {
		sprite[ i ] = createSprite( 150 * i + 100, 200 );
		sprite[ i ]->setIndex( i );
	}
}

void draw( ) {
	for ( int i = 0; i < 4; i++ ) {
		if ( sprite[ i ]->getIndex( ) == 1 ) {
			sprite[ i ]->remove( );
		}
	}
	drawSprites( );
}

MAGIC_END
