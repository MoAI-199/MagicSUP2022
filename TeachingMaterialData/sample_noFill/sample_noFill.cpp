/*
* 宣言 void noFill( )
* 概要 fillの無効化
* 引数 なし
* 戻り値 なし
*/


#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	createCanvas( 600, 400 );
	background( 120 );
}

void draw( ) {
	//赤い円を描く
	fill( 255, 0, 0 );
	ellipse( 100, 100, 100 );
	//fillの無効化
	noFill( );
	ellipse( 200, 100, 100 );

}

MAGIC_END
