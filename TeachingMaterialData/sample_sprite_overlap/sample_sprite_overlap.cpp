/*
�N���X
	Sprite
�錾
	void overlap( GroupPtr group, Instance* _inst, void( Instance::* func )( SpritePtr myself, SpritePtr group_menber ) )
�T�v
	�X�v���C�g�ƃO���[�v���̃X�v���C�g���Փ˂����Ƃ��A�o�^�����֐����Ăяo��
����
	GroupPtr group             : �X�v���C�g�̃O���[�v
	Instance* _inst              : this�ƋL�����Ă�������
	void( Instance::*func ) : �o�^����֐�
�߂�l
	�Ȃ�
*/

#include "Magic.h"
MAGIC_BEGIN
SpritePtr sprite;
GroupPtr group;

void setup( ) {
	sprite = createSprite( 0, 0 );
	group = createGroup( );
	SpritePtr sp = createSprite( 500, 300 );
	group->add( sp );
	
}

void deleted( SpritePtr myself, SpritePtr group_member ) {
	myself->remove( );
}

void draw( ) {
	background( 255 );
	sprite->setPos( getMouseX( ), getMouseY( ) );
	sprite->overlap( group, this, &Instance::deleted );
	drawSprites( );
}


MAGIC_END
