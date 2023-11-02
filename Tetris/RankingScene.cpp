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

/********************************

*ランキング画面：スコア取得処理

*引数：なし

*戻り値：なし

*******************************************/

void Set_RankingScene(int score)
{
	New_Score.score = score;
}


/************************************************

*ランキング画面：ファイル読み込み処理

*引数：なし

*戻り値：なし

**************************************************/

void file_read(void)
{
	FILE* fp = NULL;
	int i;

	OutputDebugString("ファイルが読み込めません");
	OutputDebugString("ファイルを生成します");
	file_write();
}
else
{
	for (i = 0; i < RANKING_MAX; i++)
	{
		fscanf_s(fp, "%2d, % [^,], %10d / n", &Ranking_Data[i].rank, Ranking_Data[i].name,
			RANKING_NAME_LEN, &Ranking_Data[i].score);
	}

	fclose(fp);
	}
}

/**************************************

*ランキング画面：ファイル書き込み処理

*引数：なし

*戻り値：なし

******************************************/


void file_write(void)
{
	FILE* fp = NULL;
	int i;

	OutputDebugString("ファイルを書き込みます");
	fopen_s(&fp, RANKING_FILE, "W");

	if (fp == NULL)
	{
		OutputDebugString("ファイルが書き込めません");
	}
	else
	{
		for (i = 0; i < RANKING_MAX; i++)
		{
			fprintf(fp, "%2d,%[^,],%10d/n", &Ranking_Data[i].rank, Ranking_Data[i].name,
				RANKING_NAME_LEN, &Ranking_Data[i].score);
		}
		fclose(fp);
	}
}


/***********************************************

*ランキング画面：ランキングソート処理

*引数：なし

*戻り値：なし

*******************************************/

void rnking_sort(void)
{
	int i, j;      //ループカウンタ
	T_RANKING tmp;        //退避領域

	//一番下のスコアを更新する
	Ranking_Data[RANKING_MAX - 1] = New_Score;

	//データのソートを行う
	for (i = 0; i < RANKING_MAX; i++)
	{
		for (j = i + 1; j < RANKING_MAX; j++)
		{

			if (Ranking_Data[i].score < Ranking_Data[j].score)
			{

				tmp = Ranking_Data[i];
				Ranking_Data[i] = Ranking_Data[j];
				Ranking_Data[j] = tmp;
			}
		}
	}


	//順位を上からふっていく
	for (i = 0; i < RANKING_MAX; i++)
	{
		Ranking_Data[i].rank = i + 1;
	}

	//ファイルに書き込みを行う
	file_write();
}

/****************************************

*ランキング画面：名前入力処理

*引数：なし

*戻り値：なし

********************************************/


