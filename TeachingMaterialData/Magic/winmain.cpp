#include "DxLib.h"
#include "../lib/Magic.h"
#include "mathematics.h"

Global* _instance = NULL;
extern Matrix _mat_transform;

int WINAPI WinMain( _In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd ) {
	// log.txtを非表示
	SetOutApplicationLogValidFlag( FALSE );
	// ウインドウモードに変更
	ChangeWindowMode( TRUE );
	// 描画先を裏画面に変更
	SetDrawScreen( DX_SCREEN_BACK );
	// マウスカーソルを表示
	SetMouseDispFlag( TRUE );

	//ウィンドウ設定
	_instance->systemInit( );

	if ( DxLib_Init( ) == -1 ) {
		return -1;
	}

	_instance->initTextStyle( );

	//ウィンドウの最大サイズを設定
	int max_width = 5000;
	int max_height = 5000;
	SetGraphMode( max_width, max_height, 32 );
	//ウィンドウサイズを自由な比率で変更出来ようにする
	SetWindowSizeChangeEnableFlag( FALSE, FALSE );

	_instance->background( 255 );
	_instance->preload( );
	_instance->setup( );
	while ( true ) {
		if ( ProcessMessage( ) != 0 ) {
			break;
		}
		if ( CheckHitKey( KEY_INPUT_ESCAPE ) != 0 ) {
			break;
		}

		_instance->systemUpdate( );

		_mat_transform = Matrix( );
		_instance->resetSetting( );
		_instance->draw( );
		_instance->deleteSprite( );

		ScreenFlip( );
		DrawGraph( 0, 0, DX_SCREEN_FRONT, FALSE );
	}

	_instance->deleteTextStyle( );

	DxLib_End( );
	return 0; 
}