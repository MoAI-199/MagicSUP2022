/*
宣言
	SoundPtr loadSound( const char* filename )
概要
	音ファイルをメモリに読みこむ
引数
	filename :　メモリに読みこむ音ファイルのファイル名
戻り値 
	Soundインスタンス
*/
#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	SoundPtr sound = loadSound( "cancel_0.mp3" );
}

void draw( ) {
	
}

MAGIC_END
