/*
宣言
	double random( int high);
	double random( int low, int high );
概要
	乱数を作ります。
	呼び出すたびに異なる数値を返します。
	パラメータで値の上限、または範囲を指定することができます。
	たとえばrandom(5)とすると、0以上、5未満の乱数が生成されます。
引数
	high : 値の上限 (intまたはfloat)
	low : 値の下限。設定しない場合は0 (intまたはfloat)
戻り値
	生成された乱数
*/

#include "Magic.h"
#include <stdio.h>
MAGIC_BEGIN

void setup( ) {

}

void draw( ) {
	background( 255 );
	int n = ( int )random( 1000, 10000 );
	char buf[ 256 ];
	sprintf_s( buf, 256, "%d", n );
	text( buf, 0, 0 );
}

MAGIC_END
