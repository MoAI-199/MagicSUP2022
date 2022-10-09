/*
宣言
	void textSize( int size );
概要
	文字の大きさを設定します
引数
	size : 文字サイズ
戻り値
	なし
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	createCanvas(500, 500);
	textSize( 100 );
	text( "sample", 100, 50 );
}

void draw( ) {
}

MAGIC_END
