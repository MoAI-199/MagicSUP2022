/*
宣言
	void angleMode( int mode )
概要
	角度をDEGREESかRADIANSに設定する。　RADIANSはデフォルト。
引数
	mode : DEGREES
				RADIANS
戻り値
	なし
*/

#include "Magic.h"
MAGIC_BEGIN

int angle = 0;

void setup( ) {
	createCanvas( 500, 500 );
	angleMode( DEGREES );
}

void draw( ) {
	background( 255 );
	int width = getWidth( );
	int height = getHeight( );
	int mouse_x = getMouseX( );
	translate( width / 2, height / 2 );
	rotate( mouse_x );
	line( 0, 0, 100, 100 );
}

MAGIC_END