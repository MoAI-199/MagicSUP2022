/*
* 宣言 bool isMousePressed( );
* 概要 マウスが押されているか
* 引数  なし
* 戻り値 true : 押されている
　　　　 false: 押されていない
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	createCanvas( 600, 400 );
	background( 255 );
}

void draw( ) {
	background( 255 );
	if ( isMousePressed( ) ) {
		fill( 0, 0, 255, 20 );
		ellipse( 300, 100, 100 );
	}
}

MAGIC_END