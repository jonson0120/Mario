#pragma once
class Player
{
private:

	bool Move;               //歩いているかを判定
	int Walk;               //歩行モーション管理
	int PlayerImage[9];        //プレイヤーの画像

	float Speed;	            //スピード
	int Width, Height;      //プレイヤーの高さ
	int x, y;               //座標

	int JoypadX, JoypadY;	//パッド入力値
	float PadangL;			//パッド入力角度
	int TriggerL, TriggerR;	//トリガー入力値

public:
	void InitPad();
		Player();

		void Update();
		void Draw()const;

};


