#pragma once
class KeyManager
{
private:
    static char oldKey[256];    //前回の入力キー
    static char nowKey[256];    //今回の入力キー
private:
    KeyManager() = default;


public:
    static void Update()
    {
        for (int i = 0; i < 256; i++)
        {
            oldKey[i] = nowKey[i];
        }
        
    }
    //ボタンを押した瞬間
    static bool OnClick(int inputKey)
    {
        bool ret = (nowKey[inputKey] == 1 && oldKey[inputKey] == 0);
        return ret;
    }
    //ボタンを押してる間
    static bool OnPressed(int inputKey)
    {
        bool ret = (nowKey[inputKey] == 1);
        return ret;
    }
    //ボタンを離した瞬間
    static bool OnRelease(int inputKey)
    {
        bool ret = (oldKey[inputKey] == 1 && nowKey[inputKey] == 0);
        return ret;
    }
};

