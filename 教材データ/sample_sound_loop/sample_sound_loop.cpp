/*
クラス
	Sound
宣言
	void loop( );
概要
	ループ再生する
引数
	なし
戻り値
	なし
*/
#include "Magic.h"
MAGIC_BEGIN

SoundPtr sound;
void setup( ) {
	sound = loadSound( "cancel_0.mp3" );
	sound->loop( );
}

void draw( ) {

}

MAGIC_END
