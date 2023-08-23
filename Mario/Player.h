#pragma once
class Player
{
private:

	int jump;
	bool Ground;
	int location;
	int JumpPower;         //ジャンプ
	bool Move;               //歩いているかを判定
	int Walk;               //歩行モーション管理
	int PlayerImage[9];        //プレイヤーの画像
	bool TurnFlg;
	float Speed;	            //スピード
	int Width, Height;      //プレイヤーの高さ
	int x, y;               //座標
	float fallinit;
	float fall;
	int JoypadX, JoypadY;	//パッド入力値
	float PadangL;			//パッド入力角度
	int TriggerL, TriggerR;	//トリガー入力値
	bool Search;


public:
	void InitPad();
		Player();

	void Update();
	void Draw()const;

	//座標取得
	int GetX()const { return x; }
	int GetY()const { return y; }

	void OnGround() { Ground = true; }
	void OffGround() { Ground = false; }

	//索敵
	bool WaitSearch() { return Search; }

	//座標セット
	void SetX(int X) { x = X; }
	void SetY(int Y) { y = Y; }
	
};