/*
クラス
	Image
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