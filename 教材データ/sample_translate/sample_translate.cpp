/*
�錾
	void translate( int x, int y );
�T�v
	�\���E�B���h�E���̃I�u�W�F�N�g���ړ�����ʂ��w�肵�܂��B
	x �p�����[�^�͍�/�E�ւ̈ړ����w�肵�Ay �p�����[�^�͏�/���ւ̈ړ����w�肵�܂��B
	�ϊ��͗ݐϓI�ł���A�֐��ւ̌㑱�̌Ăяo�������ʂ�ݐς�����ɔ������邷�ׂĂɓK�p����܂��B
	���Ƃ��΁Atranslate(50, 0) ���Ăяo���Ă��� translate(20, 0) ���Ăяo�����Ƃ� translate(70, 0) �Ɠ����ł��B 
	draw() ����translate() ���Ăяo���ꂽ�ꍇ�A���[�v���Ăюn�܂�ƕϊ������Z�b�g����܂��B
����
	x : X���W�ړ���
	y : Y���W�ړ���
�߂�l
	�Ȃ�
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
