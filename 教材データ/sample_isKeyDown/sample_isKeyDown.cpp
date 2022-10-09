/*
宣言
	bool isKeyDown( int key_code )
概要
		特定のキーが押されているかを返します。
引数
	key_code : LEFT_ARROW、RIGHT_ARROW、UP_ARROW、DOWN_ARROWのいずれか
戻り値
	指定したキーが押されているか
*/

#include "Magic.h"
MAGIC_BEGIN

int x = 0;
int y = 250;

void setup( ) {

}

void draw( ) {
	background( 120 );
	fill( 255, 0, 0 );
	ellipse( x, y, 100 );
	if ( isKeyDown( LEFT_ARROW ) ) {
		x -= 10;
	}
	if ( isKeyDown( RIGHT_ARROW ) ) {
		x += 10;
	}
}

MAGIC_END