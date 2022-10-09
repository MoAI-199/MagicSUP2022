/*
宣言
	void translate( int x, int y );
概要
	表示ウィンドウ内のオブジェクトを移動する量を指定します。
	x パラメータは左/右への移動を指定し、y パラメータは上/下への移動を指定します。
	変換は累積的であり、関数への後続の呼び出しが効果を累積した後に発生するすべてに適用されます。
	たとえば、translate(50, 0) を呼び出してから translate(20, 0) を呼び出すことは translate(70, 0) と同じです。 
	draw() 内でtranslate() が呼び出された場合、ループが再び始まると変換がリセットされます。
引数
	x : X座標移動量
	y : Y座標移動量
戻り値
	なし
*/
#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	ellipse( 0, 0, 100 );
	translate( 100, 0 );
	ellipse( 0, 0, 100 );
	translate( 0, 100 );
	ellipse( 0, 0, 100 );
}

void draw( ) {
	translate( getWidth( ) / 2, getHeight( ) / 2 );
	ellipse( 0, 0, 100 );
	translate( 100, 0 );
	ellipse( 0, 0, 100 );
	translate( 0, 100 );
	ellipse( 0, 0, 100 );
}

MAGIC_END
