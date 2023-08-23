#pragma once
class Player
{
private:

	int jump;
	bool Ground;
	int location;
	int JumpPower;         //�W�����v
	bool Move;               //�����Ă��邩�𔻒�
	int Walk;               //���s���[�V�����Ǘ�
	int PlayerImage[9];        //�v���C���[�̉摜
	bool TurnFlg;
	float Speed;	            //�X�s�[�h
	int Width, Height;      //�v���C���[�̍���
	int x, y;               //���W
	float fallinit;
	float fall;
	int JoypadX, JoypadY;	//�p�b�h���͒l
	float PadangL;			//�p�b�h���͊p�x
	int TriggerL, TriggerR;	//�g���K�[���͒l
	bool Search;


public:
	void InitPad();
		Player();

	void Update();
	void Draw()const;

	//���W�擾
	int GetX()const { return x; }
	int GetY()const { return y; }

	void OnGround() { Ground = true; }
	void OffGround() { Ground = false; }

	//���G
	bool WaitSearch() { return Search; }

	//���W�Z�b�g
	void SetX(int X) { x = X; }
	void SetY(int Y) { y = Y; }
	
};