#include"AbstractScene.h"
#include"DxLib.h"
#include "GameMainScene.h"
#include"Title.h"
#include"KeyManager.h"
#include"Player.h"

GameMainScene::GameMainScene()
{

}

AbstractScene* GameMainScene::Update()
{
	player.Update();
	return this;
}

void GameMainScene::Draw() const
{
	player.Draw();
}
