/*
クラス
	Video
宣言
		int getWidth( );
概要
		動画の横幅を取得する
引数
		なし
戻り値
		動画の横幅
*/
#include "Magic.h"
MAGIC_BEGIN

VideoPtr video;

// 全体の初期化（最初に一回だけ呼ばれる）
void setup( ) {
	createCanvas( 600, 600 );
	video = createVideo( "video.mp4" );
}


// 計算と表示
void draw( ) {
	fill( 100 );
	rect( 0, video->getHeight( ), video->getWidth( ), video->getHeight( ) );
	video->image( 0, 0 );
}


MAGIC_END
