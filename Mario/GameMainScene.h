#pragma once
#include "AbstractScene.h"
#include"Player.h"

class GameMainScene : public AbstractScene
{
private:
	Player player;				//�v���C���[

	int CameraX;
	int CameraY;

public:
	GameMainScene();

	virtual ~GameMainScene()
	{
		//delete player;//new���������delete�����
	};
	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update()override;

	//�`��Ɋւ��邱�����������
	virtual void Draw()const override;		//�ʏ�̕`��
};

