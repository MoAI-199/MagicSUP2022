/*
宣言
	void textStyle( const char * style_name );
概要
	文字または文字列の表示スタイルを変更します。
引数
	style_name : NORMAL
	　　　　　　　　　　　　　BOLD(太字)
	                     ITALIC(斜体)
						 BOLD_ITALIC(太字斜体)
						 ※上記のみ使用可能。
戻り値
	なし
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	textStyle( "BOLD" );
	text( "sample", 100, 50 );
	textStyle( "NORMAL" );
	text( "sample", 100, 70 );
	textStyle( "ITALIC" );
	text( "sample", 100, 90 );
	textStyle( "BOLD_ITALIC" );
	text( "sample", 100, 110 );
}

void draw( ) {
	
}

MAGIC_END
