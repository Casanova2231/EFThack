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
		DrawRenderTextA(115, Linespacing, "[Max 时钟]", D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);
		Ainespacing =Ainespacing + 25;
		Linespacing =Linespacing + 25;
		draw_boxnew(155, Ainespacing, 140, 24, D2D1::ColorF::SkyBlue);
		DrawRenderTextA(90, Linespacing , "玩家透视", D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);
		DrawRenderTextA(180, Linespacing, CFG.b_EspBox == 0 ? C = "[关闭]" : C = "[开启]", Function == 0 ? A = D2D1::ColorF::Red : A = D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);

		Ainespacing = Ainespacing + 25;
		Linespacing = Linespacing + 25;
		draw_boxnew(155, Ainespacing, 140, 24, D2D1::ColorF::SkyBlue);
		DrawRenderTextA(90, Linespacing, "骨骼自瞄", D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);
		DrawRenderTextA(180, Linespacing, CFG.b_aiming == 0 ? C = "[关闭]" : C = "[开启]", Function == 1 ? A = D2D1::ColorF::Red : A = D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);

		Ainespacing = Ainespacing + 25;
		Linespacing = Linespacing + 25;
		draw_boxnew(155, Ainespacing, 140, 24, D2D1::ColorF::SkyBlue);
		DrawRenderTextA(90, Linespacing, "自瞄点位", D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);
		DrawRenderTextA(180, Linespacing, CFG.b_radial == 0 ? C = "[胸部]" : C = "[头部]", Function ==2 ? A = D2D1::ColorF::Red : A = D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);

		Ainespacing = Ainespacing + 25;
		Linespacing = Linespacing + 25;
		draw_boxnew(155, Ainespacing, 140, 24, D2D1::ColorF::SkyBlue);
		DrawRenderTextA(90, Linespacing, "贵重物品", D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);
		DrawRenderTextA(180, Linespacing, CFG.b_Vehicle == 0 ? C = "[关闭]" : C = "[开启]", Function ==3 ? A = D2D1::ColorF::Red : A = D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);


		Ainespacing = Ainespacing + 25;
		Linespacing = Linespacing + 25;
		draw_boxnew(155, Ainespacing, 140, 24, D2D1::ColorF::SkyBlue);
		DrawRenderTextA(90, Linespacing, "医疗物品", D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);
		DrawRenderTextA(180, Linespacing, CFG.b_medical == 0 ? C = "[关闭]" : C = "[开启]", Function == 4 ? A = D2D1::ColorF::Red : A = D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);


		Ainespacing = Ainespacing + 25;
		Linespacing = Linespacing + 25;
		draw_boxnew(155, Ainespacing, 140, 24, D2D1::ColorF::SkyBlue);
		DrawRenderTextA(90, Linespacing, "武器透视", D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);
		DrawRenderTextA(180, Linespacing, CFG.b_weapon == 0 ? C = "[关闭]" : C = "[开启]", Function == 5 ? A = D2D1::ColorF::Red : A = D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);

		Ainespacing = Ainespacing + 25;
		Linespacing = Linespacing + 25;
		draw_boxnew(155, Ainespacing, 140, 24, D2D1::ColorF::SkyBlue);
		DrawRenderTextA(90, Linespacing, "配件透视", D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);
		DrawRenderTextA(180, Linespacing, CFG.b_parts == 0 ? C = "[关闭]" : C = "[开启]", Function == 6 ? A = D2D1::ColorF::Red : A = D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);

		Ainespacing = Ainespacing + 25;
		Linespacing = Linespacing + 25;
		draw_boxnew(155, Ainespacing, 140, 24, D2D1::ColorF::SkyBlue);
		DrawRenderTextA(90, Linespacing, "子弹透视", D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);
		DrawRenderTextA(180, Linespacing, CFG.b_Airdrop == 0 ? C = "[关闭]" : C = "[开启]", Function == 7 ? A = D2D1::ColorF::Red : A = D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);

		Ainespacing = Ainespacing + 25;
		Linespacing = Linespacing + 25;
		draw_boxnew(155, Ainespacing, 140, 24, D2D1::ColorF::SkyBlue);
		DrawRenderTextA(90, Linespacing, "无线耐力", D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);
		DrawRenderTextA(180, Linespacing, CFG.b_endurance == 0 ? C = "[关闭]" : C = "[开启]", Function == 8 ? A = D2D1::ColorF::Red : A = D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);

		Ainespacing = Ainespacing + 25;
		Linespacing = Linespacing + 25;
		draw_boxnew(155, Ainespacing, 140, 24, D2D1::ColorF::SkyBlue);
		DrawRenderTextA(90, Linespacing, "完美午后", D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);
		DrawRenderTextA(180, Linespacing, CFG.b_Recoil == 0 ? C = "[关闭]" : C = "[开启]", Function == 9 ? A = D2D1::ColorF::Red : A = D2D1::ColorF::White, pTextFormatKaiTi, 11.0f);


		Linespacing = Linespacing + 25;
		DrawRenderTextA(90, Linespacing, "[Home键显示/隐藏菜单]", D2D1::ColorF::Red, pTextFormatKaiTi, 11.0f);
		Linespacing = Linespacing + 25;
		DrawRenderTextA(90, Linespacing, "[小键盘的上下左右开启关闭功能]", D2D1::ColorF::Red, pTextFormatKaiTi, 11.0f);
		Linespacing = Linespacing + 25;
		DrawRenderTextA(90, Linespacing, "[End键安全退出 关闭游戏前请按END]", D2D1::ColorF::Red, pTextFormatKaiTi, 11.0f);

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
		Sleep(1000);//1秒
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


