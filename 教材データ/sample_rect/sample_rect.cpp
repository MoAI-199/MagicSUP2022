/*
宣言
	void rect( int x, int y, int w, int h );
概要
	四角形を描画します
引数
	x : 四角形のx座標
	y : 四角形のy座標
	w : 四角形の幅
	h : 四角形の高さ
戻り値
	なし
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	background( 0 );
	angleMode( DEGREES );
	
}

void draw( ) {

	rotate( 45 );
	rect( 100, 0, 60, 60 ); // Draw white rectangle using RADIUS mode

	fill( 100 );
	rotate( 90 );
	rect( 100, 0, 60, 60 ); // Draw gray rectangle using CENTER mode

}

MAGIC_END
