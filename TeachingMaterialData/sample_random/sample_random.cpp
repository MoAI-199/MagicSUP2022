/*
�錾
	double random( int high);
	double random( int low, int high );
�T�v
	���������܂��B
	�Ăяo�����тɈقȂ鐔�l��Ԃ��܂��B
	�p�����[�^�Œl�̏���A�܂��͔͈͂��w�肷�邱�Ƃ��ł��܂��B
	���Ƃ���random(5)�Ƃ���ƁA0�ȏ�A5�����̗�������������܂��B
����
	high : �l�̏�� (int�܂���float)
	low : �l�̉����B�ݒ肵�Ȃ��ꍇ��0 (int�܂���float)
�߂�l
	�������ꂽ����
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
