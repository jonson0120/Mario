#include"AbstractScene.h"
#include"DxLib.h"
#include "GameMainScene.h"
#include"Title.h"
#include"KeyManager.h"
#include"Player.h"

GameMainScene::GameMainScene()
{
	CameraX = 0;
	CameraY = 0;
}

AbstractScene* GameMainScene::Update()
{
	player.WaitSearch();
	player.Update();

	CameraX = player.GetX();
	CameraY = player.GetY();
	return this;
}

void GameMainScene::Draw() const
{
	player.Draw();
}
