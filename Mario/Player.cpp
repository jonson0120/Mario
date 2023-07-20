#include "Player.h"
#include"DxLib.h"
#include<math.h>
#include"PadInput.h"
#include"common.h"


Player::Player()
{

	Walk = 0;
	Speed = 0;
	Move = true;
	LoadDivGraph("1-1image/Mario/mario.png", 9, 9, 1, 32, 32, PlayerImage);

	Width = 32;
	Height = 32;
	jump = 0;
	fall = 0;

}

void Player::Update()
{

	InitPad();
	if (Move)
	{

		//横移動
		if (JoypadX >= MARGIN && Move)
		{
			Speed += 2;
			Walk++;
			TurnFlg = FALSE;
		}
		else if (JoypadX <= -MARGIN && Move) {
			Speed -= 2;	//移動量を減算
			TurnFlg = TRUE;
			Walk++;			//歩行アニメーション進行
		}
		//非スティック入力時
		else
		{
			Walk = 0;	//歩行アニメーションリセット
		}
		
		
		//Aボタン・ジャンプ
		if (PAD_INPUT::OnClick(XINPUT_BUTTON_A) && jump < 1 && Move)
		{
			//落下とジャンプ
			float fallinit = 19;
			fall = -fallinit;	//落下速度をマイナスにする
			jump++;				//ジャンプ回数を増やす
		}

		//落下速度管理
		if (fall < fallinit)
		{
			//落下速度を増やす
			fall += (fallinit * 2) / 66;
			if (fall > fallinit)
			{
				fall = fallinit;	//落下速度の最大値
			}
		}
		else
		{
			jump = 0;
		}

	}
	if (16 <= Walk)Walk = 0;
}

void Player::Draw()const
{
	int fix = 0;

	DrawRotaGraph(SCREEN_WIDTH / 2+Speed, SCREEN_HEIGHT / 2 + fall, 1.0f, 0,PlayerImage[Walk / 4], TRUE,TurnFlg);
}

void Player::InitPad()
{
	//スティック
	JoypadX = PAD_INPUT::GetPadThumbLX();
	JoypadY = PAD_INPUT::GetPadThumbLY();

	//トリガー
	TriggerL = PAD_INPUT::GetPadLeftTrigger();
	TriggerR = PAD_INPUT::GetPadRightTrigger();

	//入力角度
	float angle = atan2((float)JoypadX, (float)JoypadY);
	if (angle < 0)angle += 3.14;

	angle = angle / 2 / 3.14 * 360;
	if (JoypadX < 0)angle -= 180;

	PadangL = angle;
}