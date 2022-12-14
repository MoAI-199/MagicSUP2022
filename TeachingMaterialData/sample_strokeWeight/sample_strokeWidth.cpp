/*
* 宣言 void strokeWeight( int weight )
* 概要 枠線の太さを変える
* 引数  weight : 枠線の太さ
* 戻り値 なし
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	createCanvas( 600, 400 );
	background( 255 );
}

void draw( ) {
	//枠線が細い白色の円を描画
	strokeWeight( 1 );
	ellipse( 100, 100, 100 );

	//枠線の太くして円を描画
	strokeWeight( 10 );
	ellipse( 300, 100, 100 );
}

MAGIC_END