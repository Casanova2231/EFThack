#pragma once
int Function;


D3DCOLOR A;
const char* C;
int B;
bool CreateConsole = true;
void menu()
{
	  int Ainespacing = 191;
      int Linespacing =179;

	  int a = GameVars.Meshpoint;
	  char c[8];
	  _itoa(a, c, 10);



	if (CFG.b_MenuShow)
	{
	

	    //DrawCircle(GetSystemMetrics(SM_CXSCREEN) / 2.0f, GetSystemMetrics(SM_CYSCREEN) / 2.0f, CFG.AimbotFOV, 1, D2D1::ColorF::White, 11.0f);
		draw_boxnew(155, 191, 140,24, D2D1::ColorF::SkyBlue);
		DrawRenderTextA(115, Linespacing, "[Max ʱ��]", D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);
		Ainespacing =Ainespacing + 25;
		Linespacing =Linespacing + 25;
		draw_boxnew(155, Ainespacing, 140, 24, D2D1::ColorF::SkyBlue);
		DrawRenderTextA(90, Linespacing , "���͸��", D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);
		DrawRenderTextA(180, Linespacing, CFG.b_EspBox == 0 ? C = "[�ر�]" : C = "[����]", Function == 0 ? A = D2D1::ColorF::Red : A = D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);

		Ainespacing = Ainespacing + 25;
		Linespacing = Linespacing + 25;
		draw_boxnew(155, Ainespacing, 140, 24, D2D1::ColorF::SkyBlue);
		DrawRenderTextA(90, Linespacing, "��������", D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);
		DrawRenderTextA(180, Linespacing, CFG.b_aiming == 0 ? C = "[�ر�]" : C = "[����]", Function == 1 ? A = D2D1::ColorF::Red : A = D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);

		Ainespacing = Ainespacing + 25;
		Linespacing = Linespacing + 25;
		draw_boxnew(155, Ainespacing, 140, 24, D2D1::ColorF::SkyBlue);
		DrawRenderTextA(90, Linespacing, "�����λ", D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);
		DrawRenderTextA(180, Linespacing, CFG.b_radial == 0 ? C = "[�ز�]" : C = "[ͷ��]", Function ==2 ? A = D2D1::ColorF::Red : A = D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);

		Ainespacing = Ainespacing + 25;
		Linespacing = Linespacing + 25;
		draw_boxnew(155, Ainespacing, 140, 24, D2D1::ColorF::SkyBlue);
		DrawRenderTextA(90, Linespacing, "������Ʒ", D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);
		DrawRenderTextA(180, Linespacing, CFG.b_Vehicle == 0 ? C = "[�ر�]" : C = "[����]", Function ==3 ? A = D2D1::ColorF::Red : A = D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);


		Ainespacing = Ainespacing + 25;
		Linespacing = Linespacing + 25;
		draw_boxnew(155, Ainespacing, 140, 24, D2D1::ColorF::SkyBlue);
		DrawRenderTextA(90, Linespacing, "ҽ����Ʒ", D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);
		DrawRenderTextA(180, Linespacing, CFG.b_medical == 0 ? C = "[�ر�]" : C = "[����]", Function == 4 ? A = D2D1::ColorF::Red : A = D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);


		Ainespacing = Ainespacing + 25;
		Linespacing = Linespacing + 25;
		draw_boxnew(155, Ainespacing, 140, 24, D2D1::ColorF::SkyBlue);
		DrawRenderTextA(90, Linespacing, "����͸��", D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);
		DrawRenderTextA(180, Linespacing, CFG.b_weapon == 0 ? C = "[�ر�]" : C = "[����]", Function == 5 ? A = D2D1::ColorF::Red : A = D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);

		Ainespacing = Ainespacing + 25;
		Linespacing = Linespacing + 25;
		draw_boxnew(155, Ainespacing, 140, 24, D2D1::ColorF::SkyBlue);
		DrawRenderTextA(90, Linespacing, "���͸��", D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);
		DrawRenderTextA(180, Linespacing, CFG.b_parts == 0 ? C = "[�ر�]" : C = "[����]", Function == 6 ? A = D2D1::ColorF::Red : A = D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);

		Ainespacing = Ainespacing + 25;
		Linespacing = Linespacing + 25;
		draw_boxnew(155, Ainespacing, 140, 24, D2D1::ColorF::SkyBlue);
		DrawRenderTextA(90, Linespacing, "�ӵ�͸��", D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);
		DrawRenderTextA(180, Linespacing, CFG.b_Airdrop == 0 ? C = "[�ر�]" : C = "[����]", Function == 7 ? A = D2D1::ColorF::Red : A = D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);

		Ainespacing = Ainespacing + 25;
		Linespacing = Linespacing + 25;
		draw_boxnew(155, Ainespacing, 140, 24, D2D1::ColorF::SkyBlue);
		DrawRenderTextA(90, Linespacing, "��������", D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);
		DrawRenderTextA(180, Linespacing, CFG.b_endurance == 0 ? C = "[�ر�]" : C = "[����]", Function == 8 ? A = D2D1::ColorF::Red : A = D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);

		Ainespacing = Ainespacing + 25;
		Linespacing = Linespacing + 25;
		draw_boxnew(155, Ainespacing, 140, 24, D2D1::ColorF::SkyBlue);
		DrawRenderTextA(90, Linespacing, "�������", D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);
		DrawRenderTextA(180, Linespacing, CFG.b_Recoil == 0 ? C = "[�ر�]" : C = "[����]", Function == 9 ? A = D2D1::ColorF::Red : A = D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);


		Linespacing = Linespacing + 25;
		DrawRenderTextA(90, Linespacing, "[Home����ʾ/���ز˵�]", D2D1::ColorF::Red, pTextFormatKaiTi, 11.0f);
		Linespacing = Linespacing + 25;
		DrawRenderTextA(90, Linespacing, "[С���̵��������ҿ����رչ���]", D2D1::ColorF::Red, pTextFormatKaiTi, 11.0f);
		Linespacing = Linespacing + 25;
		DrawRenderTextA(90, Linespacing, "[End����ȫ�˳� �ر���Ϸǰ�밴END]", D2D1::ColorF::Red, pTextFormatKaiTi, 11.0f);

	}
	
}
//Draw_FullRect(5, 5, 300, 90, D3DCOLOR_ARGB(100, 255, 0, 0));
void functionhotkey()
{
	static int meshpoint = 1;

	if (GetAsyncKeyState(VK_UP) & 1)
	{
		if (Function <= 0)
		{
			Function = 0;
		}
		else
		{
			Function = Function - 1;
		}
	}
	if (GetAsyncKeyState(VK_DOWN) & 1)
	{
		if (Function >=9)
		{
			Function = 0;
		}
		else
		{
			Function = Function + 1;
		}
	}
	if (GetAsyncKeyState(VK_HOME) & 1)
		CFG.b_MenuShow = !CFG.b_MenuShow;
	if (GetAsyncKeyState(VK_END) & 1)
	{
		driveruninstall();
		Sleep(1000);//1��
		exit(NULL);
	}
	
	if (GetAsyncKeyState(SPI_GETLOWPOWERTIMEOUT) & 1)
	{

		meshpoint = meshpoint + 1;

	}
	if (GetAsyncKeyState(SPI_GETPOWEROFFTIMEOUT) & 1)
	{

		meshpoint = meshpoint - 1;
	}
	GameVars.Meshpoint = meshpoint;

	//cout << Function << endl;
	if (GetAsyncKeyState(VK_LEFT) & 1 || GetAsyncKeyState(VK_RIGHT) & 1)
	{
		if (Function == 0)
		{
			CFG.b_EspBox = !CFG.b_EspBox;
		}
		if (Function == 1)
		{
			CFG.b_aiming = !CFG.b_aiming;
		}
		if (Function == 2)
		{
			CFG.b_radial = !CFG.b_radial;
		}
		if (Function == 3)
		{
			CFG.b_Vehicle = !CFG.b_Vehicle;
		}
		if (Function ==4)
		{
			CFG.b_medical = !CFG.b_medical;
		}
		if (Function == 5)
		{
			CFG.b_weapon = !CFG.b_weapon;
		}
		if (Function ==6)
		{
			CFG.b_parts = !CFG.b_parts;
		}
		if (Function == 7)
		{
			CFG.b_Airdrop = !CFG.b_Airdrop;
		}
		if (Function == 8)
		{
			CFG.b_endurance = !CFG.b_endurance;
		}
		if (Function ==9)
		{
			CFG.b_Recoil = !CFG.b_Recoil;
		}

		
	}




}
void cycle()
{


	menu();

	functionhotkey();



}


