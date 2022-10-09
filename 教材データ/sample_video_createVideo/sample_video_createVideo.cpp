/*
宣言  
		VideoPtr createVideo( const char* filename );
概要 
		動画ファイルのロード
引数
		filename :　メモリに読みこむ動画ファイルのファイル名
戻り値
		Videoインスタンス
*/
#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	VideoPtr video = createVideo( "video.mp4" );
}

void draw( ) {
}

MAGIC_END
