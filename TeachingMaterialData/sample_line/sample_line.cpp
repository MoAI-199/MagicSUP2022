/*
宣言
	void line( int x1, int y1, int x2, int y2 );
概要
	線を描画します
引数
	x1, y1 : 描画する線の起点座標
	x2, y2 : 描画する線の終点座標
戻り値
	なし
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
}

void draw( ) {
	rotate( 45 );
	translate( getWidth( ) / 2, getHeight( ) / 2 );
	line( 0, 0, -100, -100 );
}

MAGIC_END