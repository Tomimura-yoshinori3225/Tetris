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
	int scene;                      //スコア4
}T_RANKING;

