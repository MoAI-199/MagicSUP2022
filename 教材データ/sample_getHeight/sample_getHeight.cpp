/*
宣言 int getHeight( );
概要 画面の縦幅の取得
引数  なし
戻り値 画面の縦幅
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	createCanvas( 600, 400 );
	background( 255 );
}

void draw( ) {
	//円を画面の上下均等の位置に描画させる
	ellipse( 100, getHeight( ) / 2, 100 );
}

MAGIC_END