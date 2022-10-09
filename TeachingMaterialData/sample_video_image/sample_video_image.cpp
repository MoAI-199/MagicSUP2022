/*
宣言
		void image( int x, int y );
概要
		動画ファイルの再生
引数
		    x :  動画を表示するx座標 
		    y :  動画を表示するy座標 
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
}

MAGIC_END
