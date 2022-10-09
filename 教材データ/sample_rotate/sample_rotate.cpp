/*
宣言
	void rotate( int angle )
概要
	angleパラメータで指定された値で図形を回転させます。
引数
	angle = 回転角
戻り値
	なし
*/

#include "Magic.h"
MAGIC_BEGIN

double angle = 5;

const double PI = 3.1415926535897932384626433832795;

void setup( ) {
	createCanvas( 500, 500 );
	angleMode( RADIANS );
}

void draw( ) {
	background( 220 );

	rotate( 0 );
	fill( 0, 255, 0 );
	line( 100, 0, 52, 52 );
	rotate( PI / 6.0 );  // 30°時計回りに回転
	fill( 0, 255, 0 );
	line( 100, 0, 52, 52 );

	rotate( PI / 6.0 );  // 更に30°時計回りに回転
	fill( 255, 0, 0 );
	line( 100, 0, 52, 52 );
}

MAGIC_END