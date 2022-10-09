/*
宣言
	void setFrameRate( int rate );
概要
	フレームレートの設定
引数
	rate : FPS値
戻り値
	なし
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	setFrameRate( 60 );
}

int x = 0;

void draw( ) {
	background( 255 );
	x++;
	if ( x == 300 ) {
		setFrameRate( 10 );
	}
	ellipse( x, getHeight( ) / 2, 100 );
}

MAGIC_END
