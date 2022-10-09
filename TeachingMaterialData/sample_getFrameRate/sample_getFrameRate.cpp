/*
宣言
	int getFrameRate( );
概要
	フレームレートの取得
引数
	なし
戻り値
	FPS値
*/
#include "Magic.h"
#include <string>
MAGIC_BEGIN

void setup( ) {

}

void draw( ) {
	background( 255 );
	int rate = getFrameRate( );
	std::string str = std::to_string( rate );
	text( str.c_str( ), 0, 0 );
}

MAGIC_END
