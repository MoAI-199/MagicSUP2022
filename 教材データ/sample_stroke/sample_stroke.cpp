/*
* 宣言 void stroke( int r, int g, int b  )
* 概要 枠線の表示
*	   RGB値を指定して色を変更できる
* 引数  r : 赤の成分 (0 ～ 255)
* 　　　g : 緑の成分 (0 ～ 255)
* 　　　b : 青の成分 (0 ～ 255)
* 戻り値 なし
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	createCanvas( 600, 400 );
	background( 255 );
}

void draw( ) {
	//枠線のない赤色の円を描画
	noStroke( );
	fill( 255, 0, 0 );
	ellipse( 100, 100, 100 );
	
	//青色の枠線の円を描画
	stroke(0, 0, 255 );
	fill( 255, 0, 0 );
	ellipse( 200, 100, 100 ); 
}

MAGIC_END

