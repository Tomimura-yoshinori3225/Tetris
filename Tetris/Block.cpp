#include "Block.h"
#include "DxLib.h"
#include "InputControl.h"


/*********************************

*�}�N����`

*********************************/

#define FIELD_HEIGHT           (21)                //�t�B�[���h�̃}�X�̍���
#define FIELD_WIDTH            (12)               //�t�B�[���h�̃}�X�̕�
#define BLOCK_TROUT_SIZE      (4)                 //�u���b�N�̃}�X�T�C�Y
#define BLOCK_SIZE             (36)               //1�u���b�N������̃T�C�Y
#define BLOCK_TYPE_MAX         (7)                 //�����Ă���u���b�N�̎��
#define BLOCK_NEXT_POS_X     (700)               //���̃u���b�N�̍��W�iX���W�j
#define BLOCK_NEXT_POS_Y     (500)               //���̃u���b�N�̍��W�iY���W�j
#define BLOCK_STOCK_POS_X    (500)       //�X�g�b�N���ꂽ�u���b�N�̍��W�iX���W�j
#define BLOCK_STOCK_POS_Y    (350)       //�X�g�b�N���ꂽ�u���b�N�̍��W�iY���W�j