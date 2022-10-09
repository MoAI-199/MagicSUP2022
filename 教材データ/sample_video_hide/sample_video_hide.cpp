/*
宣言
		void hide( );
概要
		動画を非表示にします。
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
	background( 255 );
	video->loop( );
	if ( isMousePressed( ) ) {
		video->hide( );
	} else {
		video->image( 100, 100 );
	}
}


MAGIC_END

/*　注意
[hide]の上に必ず[background]を書いてください。
*/