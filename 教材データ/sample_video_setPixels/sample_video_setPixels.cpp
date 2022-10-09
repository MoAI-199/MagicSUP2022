/*
クラス
	Video
宣言
	void setPixel( int index, int color );
概要
	indexで指定したピクセルの色をcolorに変更します。
引数
	index：ピクセルの要素番号
	color：色
戻り値
	なし
*/

#include "Magic.h"
MAGIC_BEGIN

VideoPtr video;
void setup( ) {
	video = createVideo( "video.mp4" );
}

void draw( ) {
	video->loop( );
	video->loadPixels( );

	for ( int i = 0; i < video->getHeight( ); i++ ) {
		for ( int j = 0; j < video->getWidth( ); j++ ) {
			int index = ( j + i * video->getWidth( ) ) * 4;
			if ( video->getPixel( index + 2 ) > 10 ) {
				video->setPixel( index + 1, 255 );
			}
		}
	}

	video->updatePixels( );
}

MAGIC_END