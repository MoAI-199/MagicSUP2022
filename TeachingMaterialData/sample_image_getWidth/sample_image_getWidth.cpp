/*
クラス
	Image
宣言
		int getWidth( );
概要
		画像の横幅を取得する
引数
		なし
戻り値
		画像の横幅
*/
#include "Magic.h"
MAGIC_BEGIN

ImagePtr image;

void setup( ) {
	image = loadImage( "logo.png" );
}

void draw( ) {
	int width = image->getWidth(  );
}

MAGIC_END
