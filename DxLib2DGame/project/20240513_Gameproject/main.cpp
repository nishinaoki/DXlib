#include "DxLib.h"//Dx���C�u�����[���C���N���[�h(�ǂݍ���)

int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)//Windows�̃��C���œ�����
{

    //��{�݌v
    ChangeWindowMode(TRUE);//Windows�̉�ʂ��A�N�e�B�u�ɂ���
    DxLib_Init();//DxLib�̏�����
    SetDrawScreen(DX_SCREEN_BACK);//��ʂ̔w�i�͍�
    SetGraphMode(800, 600, 32);//��ʂ̑傫��

    //Dxlib�̏���������
    if (DxLib_Init() == -1)
    {
        //�G���[���N�����璼���ɏI��

        return -1;
    }
    //�~�̏����ʒu
    int circleX = 320;
    int circleY = 240;

    //�Q�[�����[�v
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        ClearDrawScreen();

        DrawCircle(circleX, circleY, 30, GetColor(0, 0, 255), TRUE);

        circleX += 2;
        circleY += 2;


        ScreenFlip();
    }

    DrawPixel(320, 240, GetColor(255, 0, 0));

    DxLib_End();

    return 0;
}
        
