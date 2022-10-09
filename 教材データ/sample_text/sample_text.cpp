/*
宣言
	void text( const char * str, int x, int y );
概要
	文字または文字列を指定した位置に表示します
引数
	x : 表示位置のx座標
	y : 表示位置のy座標
戻り値
	なし
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	text( "sample", 100, 50 );
}

void draw( ) {
}

MAGIC_END
