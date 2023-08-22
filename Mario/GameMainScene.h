#pragma once
#include "AbstractScene.h"
#include"Player.h"

class GameMainScene : public AbstractScene
{
private:
	Player player;				//プレイヤー

	int CameraX;
	int CameraY;

public:
	GameMainScene();

	virtual ~GameMainScene()
	{
		//delete player;//newを作ったらdeleteを作る
	};
	//描画以外の更新を実装する
	virtual AbstractScene* Update()override;

	//描画に関するころを実装する
	virtual void Draw()const override;		//通常の描画
};

