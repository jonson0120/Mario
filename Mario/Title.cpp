#include"Title.h"
#include"GameMainScene.h"
#include"AbstractScene.h"

Title::Title() 
{
	Menu_Number = TITLE_MENU::START;
	Interval = 0;
	Select = 0;
	JoyPadY = 0;
	CTime = 0;
	Coin_Count = 0;

	Back_Image = LoadGraph("1-1image/title.png");
	MarioName_Image = LoadGraph("1-1image/UI/name_mario.png");
	World_Image = LoadGraph("1-1image/UI/world.png");
	Time_Image = LoadGraph("1-1image/UI/time.png");
	Top_Image = LoadGraph("1-1image/UI/top.png");
	Select_Image = LoadGraph("1-1image/UI/Select.png");
	Carsol_Image = LoadGraph("1-1image/Item/mushroom.png");
	LoadDivGraph("1-1image/UI/uicoin.png",4,4,1,16,16,Coin_Image);
	LoadDivGraph("1-1image/UI/num.png", 15, 15, 1, 16, 16, Number_Image);
	
}


AbstractScene* Title::Update() 
{
	if (Interval < 30)Interval++;
	JoyPadY = PAD_INPUT::GetPadThumbLY();

	if (JoyPadY > MARGIN && Interval >= 30) {
		PlaySoundMem(CursorSE, DX_PLAYTYPE_BACK);
		Select--;
		Interval = 0;
	}
	else if (JoyPadY < -MARGIN && Interval >= 30) {
		PlaySoundMem(CursorSE, DX_PLAYTYPE_BACK);
		Select++;
		Interval = 0;
	}

	if (JoyPadY < MARGIN && -MARGIN < JoyPadY && !PAD_INPUT::OnPressed(XINPUT_BUTTON_B))Interval = 30;

	if (Select == 0) Menu_Number = TITLE_MENU::START;
	if (Select == 1) Menu_Number = TITLE_MENU::END;

	if (Select < 0)Select = 1;
	if (Select > 1)Select = 0;

	
	if (PAD_INPUT::OnPressed(XINPUT_BUTTON_B) && Interval >= 30) {
		if (TITLE_MENU::START == Menu_Number) return new GameMainScene();
		if (TITLE_MENU::END == Menu_Number)return nullptr;
		Interval = 0;
	}
	


	CTime++;
	if (CTime % 12 == 0)
	{
		Coin_Count++;
	}
    
	return this;
}

void Title::Draw() const 
{
	DrawGraph(0, 0, Back_Image, true);//背景画像
	DrawGraph(180, 290 + Select * 30, Carsol_Image, TRUE);
	//マリオの名前
	DrawGraph(90, 25, MarioName_Image, true);
	//ステージ表記画像
	DrawGraph(360, 25, World_Image, true);
	//残り時間表記画像
	DrawGraph(490, 25, Time_Image, true);
	//トップスコア表記画像
	DrawGraph(240, 370, Top_Image, true);
	//コイン画像
	DrawGraph(230, 45, Coin_Image[Coin_Count%4], true); 
	//1-1
	DrawGraph(375, 45, Number_Image[1], true); 
	DrawGraph(390, 45, Number_Image[10], true); 
	DrawGraph(410, 45, Number_Image[1], true); 
	//1 PLAY GAME
	DrawGraph(220, 295, Select_Image, true);


}