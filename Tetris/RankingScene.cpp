#include "RankingScene.h"
#include "DxLib.h"
#include "InputControl.h"
#include "SceneManager.h"


/****************************

*�^��`

****************************/

#define RANKING_FILE       ("dat/rankingdata.csv")
#define RANKING_MAX           (10)
#define RANKING_NAME_LEN      (11)


/**************************

*�^��`

*****************************/

typedef struct
{
	int rank;                       //�����N
	char name[RANKING_NAME_LEN];    //���O
	int scene;                      //�X�R�A4
}T_RANKING;

