/*
宣言
	bool keyDown( const char * key_str )
概要
	指定した文字列に対応したキーが押されているか？
引数
	key_str :
		"LEFT" 矢印キーの左
		"RIGHT" 矢印キーの右
		"UP" 矢印キーの上
		"DOWN" 矢印キーの下
戻り値
	押されている : true
	押されていない : false
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
}

void draw( ) {
	background( 255 );

	if ( keyDown( "LEFT" ) ) {
		text( "LEFT", 0, 0 );
	}
	if ( keyDown( "RIGHT" ) ) {
		text( "RIGHT", 0, 0 );
	}
	if ( keyDown( "UP" ) ) {
		text( "UP", 0, 0 );
	}
	if ( keyDown( "DOWN" ) ) {
		text( "DOWN", 0, 0 );
	}
}

MAGIC_END