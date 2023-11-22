#include "Block.h"
#include "DxLib.h"
#include "InputControl.h"


/*********************************

*マクロ定義

*********************************/

#define FIELD_HEIGHT           (21)                //フィールドのマスの高さ
#define FIELD_WIDTH            (12)               //フィールドのマスの幅
#define BLOCK_TROUT_SIZE      (4)                 //ブロックのマスサイズ
#define BLOCK_SIZE             (36)               //1ブロック当たりのサイズ
#define BLOCK_TYPE_MAX         (7)                 //落ちてくるブルックの種類
#define BLOCK_NEXT_POS_X     (700)               //次のブロックの座標（X座標）
#define BLOCK_NEXT_POS_Y     (500)               //次のブロックの座標（Y座標）
#define BLOCK_STOCK_POS_X    (500)       //ストックされたブロックの座標（X座標）
#define BLOCK_STOCK_POS_Y    (350)       //ストックされたブロックの座標（Y座標）