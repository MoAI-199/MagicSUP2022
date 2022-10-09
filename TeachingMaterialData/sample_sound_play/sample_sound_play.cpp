/*
クラス
	Sound
宣言
	void play( );
概要
	再生する
引数
	なし
戻り値
	なし
*/
#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	SoundPtr sound = loadSound( "mySound.mp3" );
	sound->play( );
}

void draw( ) {

}

MAGIC_END
