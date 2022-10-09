/*
* 宣言 void draw( )
* 概要 プログラムが停止するまで連続的に呼び出される
* 引数  なし
* 戻り値 なし
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	createCanvas( 600, 400 );
	background( 255 );
}

void draw( ) {
	fill( 255, 0, 0 );
	ellipse( getMouseX( ), getMouseY( ), 100 );
}

MAGIC_END

