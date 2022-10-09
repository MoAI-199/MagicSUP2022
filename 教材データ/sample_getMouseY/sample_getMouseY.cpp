/*
* 宣言 int getMouseY( );
* 概要 マウスの縦の位置を取得
* 引数  なし
* 戻り値 マウスの縦の位置
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	createCanvas( 600, 400 );
	background( 255 );
}

void draw( ) {
	//枠線の太くして円を描画
	fill( 255, 0, 0 );
	ellipse( 100, getMouseY( ), 100 );
}

MAGIC_END