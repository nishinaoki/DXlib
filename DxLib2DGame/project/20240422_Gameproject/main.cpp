#include "DxLib.h"//Dx���C�u�����[���C���N���[�h�i�ǂݍ��݁j

int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)//Windows�̃��C���œ�����
{

	//��{�݌v
	ChangeWindowMode(TRUE);//Windows�̉�ʂ��A�N�e�B�u�ɂ���
	DxLib_Init();//DxLib�̏�����
	SetDrawScreen(DX_SCREEN_BACK);//��ʂ̔w�i�͍�
	SetGraphMode(800, 600, 32);//��ʂ̑傫��

	//DxLib�̏���������
	if (DxLib_Init() == -1)
	{
		//�G���[���N�����璼���ɏI��
		return -1;
	}
	//�~�̏����ʒu
	int circleX = 150;
	int circleY = 200;
	//�����̈ʒu
	int stringX = 10;
	int stringY = 15;
	int stringX1 = 10;
	int stringY1 = 45;
	//�����̐F
	int StringColor = GetColor(255, 255, 255);
	int StringColor2 = GetColor(255, 0, 0);
	//�}�E�X�̍��W
	int MouseX=0;
	int MouseY=0;

	//�Q�[�����[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		//��ʂ̏�����
		ClearDrawScreen();
		//�����̑傫���̎w��
		SetFontSize(32);
		// ��ʂɕ�����\��
		// DrawString(10,15,"HelloWourd",StringColor);
		DrawFormatString(stringX, stringY, StringColor,"MouseX:%d MouseY:%d",MouseX,MouseY);
		//��ʂɉ~��`�悳����
		DrawCircle(circleX, circleY, 30, GetColor(0, 0, 255), TRUE);
		//�}�E�X�̍��W�̎擾
		GetMousePoint(&MouseX, &MouseY);
		//�}�E�X���N���b�N���ꂽ��
		if ((GetMouseInput() & MOUSE_INPUT_LEFT))
		{
			SetFontSize(30);
			DrawString(stringX1, stringY1, "Hit!", StringColor2);
		}
		//��
		if (CheckHitKey(KEY_INPUT_UP))
		{
			if (circleY <= 40)
			{
				circleY += 3;
			}
			else
			{
				circleY -= 3;
			}
		}
		//��
		if (CheckHitKey(KEY_INPUT_DOWN))
		{
			if (circleY >= 560)
			{
				circleY -= 3;
			}
			else
			{
				circleY += 3;
			}
		}
		//�E
		if (CheckHitKey(KEY_INPUT_RIGHT))
		{
			if (circleX >= 760)
			{
				circleX -= 3;
			}
			else
			{
				circleX += 3;
			}
		}
	//��
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		if (circleX <= 40)
		{
			circleX += 3;
		}
		else
		{
			circleX -= 3;
		}
	}

	//�~��X���W�ɓ���������
	//circleX += 4;
	//circleY += 3;
	if (circleX >= 800)
	{
		circleX = 0;
		circleY = 0;
	}
	//����ʂ̓��e��\��ʂɔ��f������
	ScreenFlip();

}

//��ʂɓ_��`�悳���ĂˁiX���W�A�x���W�A�_�̐F�w��j
DrawPixel(320, 240, GetColor(255, 0, 0));
//Dxlib�g�p�̏I������
DxLib_End();
//�\�[�X�̏I��
return 0;
}