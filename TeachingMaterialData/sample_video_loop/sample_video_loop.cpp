/*
宣言
		void loop( );
概要
		動画をループさせます。
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
bool pause = false;

void draw( ) {
	video->image( 100, 100 );
	video->loop( );
}



MAGIC_END
