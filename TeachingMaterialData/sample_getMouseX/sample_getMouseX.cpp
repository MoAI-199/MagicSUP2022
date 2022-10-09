/*
* 宣言 int getMouseX( );
* 概要 マウスの横の位置を取得する。
* 引数  なし
* 戻り値 マウスの横の位置
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
	ellipse( getMouseX( ), 100, 100 );
}

MAGIC_END