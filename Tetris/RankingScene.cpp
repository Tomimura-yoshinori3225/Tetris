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
	int scene;                      //�X�R�A
}T_RANKING;


typedef struct
{
	int x;
	int y;
}T_CURSOR;


/******************************

*�O���[�o���ϐ���`

**********************************/

T_RANKING Ranking_Data[RANKING_MAX];
T_RANKING New_Score;
int DispMode;

T_CURSOR Cursor;
int name_num;


/*****************************************

*�v���g�^�C�v�錾

******************************************/

void file_read(void);               //�t�@�C��l�ǂݍ���
void file_write(void);              //�t�@�C����������
void ranking_sort(void);           //�����L���O�\�[�g����
void ranking_input_name(void);      //���O���͏���
void ranking_input_name_draw(void);   //���O���͕`�揈��


/*********************************

*�����L���O��ʁF����������

*�����F�Ȃ�

*�߂�l�F�G���[���i-�P�F�ȏ�L�A-�P�ȊO�F����I���j

****************************************/



