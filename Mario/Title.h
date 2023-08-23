#pragma once
#include "AbstractScene.h"
#include "PadInput.h"

class Title :public AbstractScene
{
private:
	enum class TITLE_MENU 
	{
		START,
		END
	};

	TITLE_MENU Menu_Number;
	int Interval;
	int Select;
	int JoyPadY;
	int CTime;
	int Coin_Count;

	int Back_Image;
	int MarioName_Image;
	int Coin_Image[4];
	int World_Image;
	int Time_Image;
	int Top_Image;
	int Number_Image[15];
	int Select_Image;
	int Carsol_Image;

	int CursorSE;
	int TitleBGM;

	int Click_Sound;

public:
	Title();
	~Title() {};
	virtual AbstractScene* Update()override;


	virtual void Draw()const override;

};

