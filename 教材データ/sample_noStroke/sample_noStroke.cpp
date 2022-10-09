/*
* 宣言 void noStroke( )
* 概要 枠線を消す
* 引数 なし
* 戻り値 なし
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	createCanvas( 600, 400 );
	background( 255 );
}

void draw( ) {
	//枠線のある円を描画
	fill( 255, 0, 0 );
	ellipse( 100, 100, 100 );
	//枠線のない円を描画
	noStroke( );
	ellipse( 200, 100, 100 );
}

MAGIC_END

