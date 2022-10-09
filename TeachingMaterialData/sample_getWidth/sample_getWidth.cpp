/*
宣言 int getWidth( );
概要 画面の横幅の取得
引数  なし
戻り値 画面の横幅
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	createCanvas( 600, 400 );
	background( 255 );
}

void draw( ) {
	//円を画面の左右均等の位置に描画させる
	ellipse( getWidth( ) / 2, 100, 100 );
}

MAGIC_END