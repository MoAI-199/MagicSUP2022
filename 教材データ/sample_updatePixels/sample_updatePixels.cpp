/*
宣言
	void updatePixels( )
概要
	ピクセルのデータをもとに画面を更新します。
引数
	なし
戻り値
	なし
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	createCanvas( 40, 30 );
}

void draw( ) {
	fill( 255, 0, 0 );
	ellipse( 15, 15, 10 );
	loadPixels( );

	for ( int i = 0; i < getHeight( ); i++ ) {
		for ( int j = 0; j < getWidth( ); j++ ) {
			int index = ( j + i * 40 ) * 4;
			if ( getPixel( index ) == 255 ) {
				setPixel( index, 0 );
			}
		}
	}
	updatePixels( );
}

MAGIC_END