/*
宣言
		void mouseClicked( );
概要
		クリックされた時に処理される関数
引数
		なし
戻り値
		なし
*/
#include "Magic.h"
MAGIC_BEGIN

VideoPtr video;
bool pause = false;

void setup( ) {
	video = createVideo( "video.mp4" );

}

void draw( ) {
	video->image( 100, 100 );
	if ( pause ) {
		video->pause( );
	} else {
		video->loop( );
	}

}

void mouseClicked( ) {
	pause = !pause;
}

MAGIC_END
