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

*�����L���O��ʁF�X�V����

*�����F�Ȃ�

*�߂�l�F�Ȃ�

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

*�����L���O��ʁF�`�揈��

*�����F�Ȃ�

*�߂�l�F�Ȃ�

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

*�����L���O��ʁF��ʕύX����

*�����F�Ȃ�

*�߂�l�F�Ȃ�

**************************************/

void Set_RankingMode(int mode)
{
	DispMode = mode;
}

/********************************

*�����L���O��ʁF�X�R�A�擾����

*�����F�Ȃ�

*�߂�l�F�Ȃ�

*******************************************/

void Set_RankingScene(int score)
{
	New_Score.score = score;
}


/************************************************

*�����L���O��ʁF�t�@�C���ǂݍ��ݏ���

*�����F�Ȃ�

*�߂�l�F�Ȃ�

**************************************************/

void file_read(void)
{
	FILE* fp = NULL;
	int i;

	OutputDebugString("�t�@�C�����ǂݍ��߂܂���");
	OutputDebugString("�t�@�C���𐶐����܂�");
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

*�����L���O��ʁF�t�@�C���������ݏ���

*�����F�Ȃ�

*�߂�l�F�Ȃ�

******************************************/


void file_write(void)
{
	FILE* fp = NULL;
	int i;

	OutputDebugString("�t�@�C�����������݂܂�");
	fopen_s(&fp, RANKING_FILE, "W");

	if (fp == NULL)
	{
		OutputDebugString("�t�@�C�����������߂܂���");
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

*�����L���O��ʁF�����L���O�\�[�g����

*�����F�Ȃ�

*�߂�l�F�Ȃ�

*******************************************/

void rnking_sort(void)
{
	int i, j;      //���[�v�J�E���^
	T_RANKING tmp;        //�ޔ�̈�

	//��ԉ��̃X�R�A���X�V����
	Ranking_Data[RANKING_MAX - 1] = New_Score;

	//�f�[�^�̃\�[�g���s��
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


	//���ʂ��ォ��ӂ��Ă���
	for (i = 0; i < RANKING_MAX; i++)
	{
		Ranking_Data[i].rank = i + 1;
	}

	//�t�@�C���ɏ������݂��s��
	file_write();
}

/****************************************

*�����L���O��ʁF���O���͏���

*�����F�Ȃ�

*�߂�l�F�Ȃ�

********************************************/


