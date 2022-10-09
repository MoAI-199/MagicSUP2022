/*
宣言
		void pause( );
概要
		動画の一時停止
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
	video->image( 100, 100 );

	video->pause( );
}

MAGIC_END
