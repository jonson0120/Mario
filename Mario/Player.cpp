#include "Player.h"
#include"DxLib.h"
#include<math.h>
#include"PadInput.h"
#include"common.h"


Player::Player()
{
	location = 0;
	Ground = true;
	Walk = 0;
	Speed = 0;
	Move = true;
	LoadDivGraph("1-1image/Mario/mario.png", 9, 9, 1, 32, 32, PlayerImage);

	Width = 32;
	Height = 32;
	jump = 0;
	fall = 0;
	fallinit = 19;
}

void Player::Update()
{

	InitPad();
	
		
		//���ړ�
		//����
		if (JoypadX >= MARGIN && !PAD_INPUT::OnPressed(XINPUT_BUTTON_A))
		{
			Speed += 2;
			Walk++;
			TurnFlg = FALSE;
		}
		else if (JoypadX <= -MARGIN && !PAD_INPUT::OnPressed(XINPUT_BUTTON_A)) {
			Speed -= 2;	//�ړ��ʂ����Z
			TurnFlg = TRUE;
			Walk++;			//���s�A�j���[�V�����i�s
		}

		//����
		else if (JoypadX >= MARGIN && PAD_INPUT::OnPressed(XINPUT_BUTTON_A))
		{
			Speed += 4;
			Walk++;
			Walk++;
			TurnFlg = FALSE;
		}
		else if (JoypadX <= -MARGIN && PAD_INPUT::OnPressed(XINPUT_BUTTON_A)) {
			Speed -= 4;	//�ړ��ʂ����Z
			TurnFlg = TRUE;
			Walk++;			//���s�A�j���[�V�����i�s
			Walk++;
		}
		//��X�e�B�b�N���͎�
		else
		{
			Walk = 0;	//���s�A�j���[�V�������Z�b�g
		}

		if (Ground)
		{
			JumpPower = 0;
		}
		else
		{
			// ���������x��������
			JumpPower -= 1;
		}


		if (PAD_INPUT::OnClick(XINPUT_BUTTON_B) && Ground)//�W�����v
		{
			Ground = false;
			JumpPower = 15;
			location -= 15;
		}
		//�����ƃW�����v
		//A�{�^���E�W�����v
		location -= JumpPower;

		if ( location> 0)
		{
			location = 0;
		}
		
	
	if (16 <= Walk)Walk = 0;
}

void Player::Draw()const
{
	int fix = 0;

	DrawRotaGraph(SCREEN_WIDTH / 2+Speed, SCREEN_HEIGHT / 2 + location, 1.0f, 0,PlayerImage[Walk / 4], TRUE,TurnFlg);
	DrawFormatString(0, 0, 0xffffff, "%d", location);
	DrawFormatString(0, 10, 0xffffff, "%f", Speed);
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