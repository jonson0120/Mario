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

		//���ړ�
		if (JoypadX >= MARGIN && Move)
		{
			Speed += 2;
			Walk++;
			TurnFlg = FALSE;
		}
		else if (JoypadX <= -MARGIN && Move) {
			Speed -= 2;	//�ړ��ʂ����Z
			TurnFlg = TRUE;
			Walk++;			//���s�A�j���[�V�����i�s
		}
		//��X�e�B�b�N���͎�
		else
		{
			Walk = 0;	//���s�A�j���[�V�������Z�b�g
		}
		
		
		//A�{�^���E�W�����v
		if (PAD_INPUT::OnClick(XINPUT_BUTTON_A) && jump < 1 && Move)
		{
			//�����ƃW�����v
			float fallinit = 19;
			fall = -fallinit;	//�������x���}�C�i�X�ɂ���
			jump++;				//�W�����v�񐔂𑝂₷
		}

		//�������x�Ǘ�
		if (fall < fallinit)
		{
			//�������x�𑝂₷
			fall += (fallinit * 2) / 66;
			if (fall > fallinit)
			{
				fall = fallinit;	//�������x�̍ő�l
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
	//�X�e�B�b�N
	JoypadX = PAD_INPUT::GetPadThumbLX();
	JoypadY = PAD_INPUT::GetPadThumbLY();

	//�g���K�[
	TriggerL = PAD_INPUT::GetPadLeftTrigger();
	TriggerR = PAD_INPUT::GetPadRightTrigger();

	//���͊p�x
	float angle = atan2((float)JoypadX, (float)JoypadY);
	if (angle < 0)angle += 3.14;

	angle = angle / 2 / 3.14 * 360;
	if (JoypadX < 0)angle -= 180;

	PadangL = angle;
}