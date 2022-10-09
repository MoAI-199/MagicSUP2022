/*
�錾
	AnimationPtr loadAnimation( int num, ... );
	AnimationPtr loadAnimation( const char* filename_begin, const char* filename_end );
�T�v
	�A�j���[�V�����̃��[�h
����
	num : ��݂��ރt�@�C����
	... : (�ϒ�����) char * : �t�@�C����
	filename_begin : �A�j���[�V�������������摜�̏��߂̉摜
	filename_end : �A�j���[�V�������������摜�̍Ō�̂̉摜
�߂�l
	Animation�C���X�^���X
*/

#include "Magic.h"
MAGIC_BEGIN

AnimationPtr animation;
AnimationPtr animation2;
SpritePtr sprite;
SpritePtr sprite2;
void setup( ) {
	animation = loadAnimation(
		9,
		"01.png",
		"02.png",
		"03.png",
		"04.png",
		"05.png",
		"06.png",
		"07.png",
		"08.png",
		"09.png"
	);
	animation2 = loadAnimation( "unity01.png", "unity10.png" );
	sprite = createSprite( 100, 100 );
	sprite->addAnimation( "anime", animation );
	sprite2 = createSprite( 200, 100 );
	sprite2->addAnimation( "walk",animation2 );
}

void draw( ) {
	background( 255 );
	drawSprites( );
}

MAGIC_END