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
	LoadDivGraph("1-1image/Mario/mario", 9, 9, 1, 32, 32, PlayerImage);

}

void Player::Update()
{
	if (JoypadX >= MARGIN && Move)
	{
		Speed += 0.5;
		Walk++;
	}
	else if (JoypadX <= -MARGIN && Move) {
		Speed -= 0.5;	//移動量を減算
					
		Walk++;			//歩行アニメーション進行
	}
	if (40 <= Walk)Walk = 0;
}

void Player::Draw()const
{
	int fix = 0;
	DrawRotaGraph(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + Height / 4 + fix, 1.0f, 0,PlayerImage[Walk / 10], TRUE);
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