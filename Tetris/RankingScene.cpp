#include "RankingScene.h"
#include "DxLib.h"
#include "InputControl.h"
#include "SceneManager.h"


/****************************

*型定義

****************************/

#define RANKING_FILE       ("dat/rankingdata.csv")
#define RANKING_MAX           (10)
#define RANKING_NAME_LEN      (11)


/**************************

*型定義

*****************************/

typedef struct
{
	int rank;                       //ランク
	char name[RANKING_NAME_LEN];    //名前
	int scene;                      //スコア
}T_RANKING;


typedef struct
{
	int x;
	int y;
}T_CURSOR;


/******************************

*グローバル変数定義

**********************************/

T_RANKING Ranking_Data[RANKING_MAX];
T_RANKING New_Score;
int DispMode;

T_CURSOR Cursor;
int name_num;


/*****************************************

*プロトタイプ宣言

******************************************/

void file_read(void);               //ファイルl読み込み
void file_write(void);              //ファイル書き込み
void ranking_sort(void);           //ランキングソート処理
void ranking_input_name(void);      //名前入力処理
void ranking_input_name_draw(void);   //名前入力描画処理


/*********************************

*ランキング画面：初期化処理

*引数：なし

*戻り値：エラー情報（-１：以上有、-１以外：正常終了）

****************************************/

int RankinguScene_Initialize(void)
{
	int ret = 0;
	file_read();
	switch (DispMode)
	{
	case RANKING_INPUT_MODE:
		Cursor.x = 0;
		Cursor.y = 0;
		name_num = 0;
		break;

	case RANKING_DISP_MODE:
	default:
		break;
	}
	return ret;
}


/*******************************

*ランキング画面：更新処理

*引数：なし

*戻り値：なし

*************************************/

void RankingScene_Update(void)
{
	switch (DispMode)
	{
	case RANKING_INPUT_MODE:
		ranking_input_name();
		break;

	case RANKING_DISP_MODE:
	default:
		if (GetButtonDown(XINPUT_BUTTON_B))
		{
			Change_Scene(E_TITLE);
		}
		break;
	}
}


/**********************************

*ランキング画面：描画処理

*引数：なし

*戻り値：なし

***************************************/

void RankingScene_Draw(void)
{
	int i;

	switch (DispMode)
	{
	case RANKING_INPUT_MODE:
		ranking_input_name_draw();
		break;

	case RAKING_DISP_MODE:
	default:
		for (i = 0; i < RANKING_MAX; i++)
		{
			DrawFormatString(20, 10 + (i * 25), GetColor(255, 255, 255), "%2d,%10s,%10d", Ranking_Date[i].rank,
				Ranking_Date[i].name, Ranking_Date[i].scone);
		}
		break;

	}
}

/*******************************

*ランキング画面：画面変更処理

*引数：なし

*戻り値：なし

**************************************/

void Set_RankingMode(int mode)
{
	DispMode = mode;
}



