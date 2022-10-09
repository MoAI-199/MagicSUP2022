/*
宣言
	void textAlign( align );
概要
	文字を表示する位置の揃え方を設定します。左揃え(LEFT)、中央揃え(CENTER)、右揃え(RIGHT)の3種類から選べます。
引数
	align : LEFT,CENTER,RIGHTのいずれか
戻り値
	なし
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	textAlign( LEFT );
	text( "LEFT", getWidth( ) / 2, 100 );
	textAlign( CENTER );
	text( "CENTER", getWidth( ) / 2, 200 );
	textAlign( RIGHT );
	text( "RIGHT", getWidth( ) / 2, 300 );
}

void draw( ) {
}

MAGIC_END
