#pragma once
class Player
{
private:

	bool Move;               //�����Ă��邩�𔻒�
	int Walk;               //���s���[�V�����Ǘ�
	int PlayerImage[9];        //�v���C���[�̉摜
	bool TurnFlg;
	float Speed;	            //�X�s�[�h
	int Width, Height;      //�v���C���[�̍���
	int x, y;               //���W
	float fall;
	int jump;
	float fallinit;
	int JoypadX, JoypadY;	//�p�b�h���͒l
	float PadangL;			//�p�b�h���͊p�x
	int TriggerL, TriggerR;	//�g���K�[���͒l

public:
	void InitPad();
		Player();

		void Update();
		void Draw()const;

};


