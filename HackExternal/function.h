#include <windows.h>
#include <psapi.h>
#include <tlhelp32.h>
#include <dwmapi.h>
#include <string>
#include <vector>
#include "offset.h"
#include "cfg.h"
#include "Driver/driver.h"
#include "fon_font.hpp"
#include <algorithm>
#include "win_utils.h"
#include <corecrt_io.h>
#include <iostream>
#include <codecvt>
#include "Defines.h"
#include<any>
#include"SimpleCache.h"
template <class B>
B maxread(uintptr_t address)
{
	B buffer{};

	ReadByte(address, &buffer, sizeof(B));


	return buffer;
}

template<typename T>
std::string read_string(uint64_t address)
{
	char buffer[70];

	ReadByte(address, &buffer, sizeof(buffer));

	std::string nameString;
	for (int i = 0; i < 70; i += 2) {
		if (buffer[i] == 0)
			break;
		else
			nameString += buffer[i];
	};

	return nameString;
}


template <class T>
bool write(unsigned long long address, T buffer)
{
	return  Writeto(address, reinterpret_cast<void*>(&buffer), sizeof(T));

}


D3DMATRIX MatrixMultiplication(D3DMATRIX pM1, D3DMATRIX pM2)
{
	D3DMATRIX pOut;
	pOut._11 = pM1._11 * pM2._11 + pM1._12 * pM2._21 + pM1._13 * pM2._31 + pM1._14 * pM2._41;
	pOut._12 = pM1._11 * pM2._12 + pM1._12 * pM2._22 + pM1._13 * pM2._32 + pM1._14 * pM2._42;
	pOut._13 = pM1._11 * pM2._13 + pM1._12 * pM2._23 + pM1._13 * pM2._33 + pM1._14 * pM2._43;
	pOut._14 = pM1._11 * pM2._14 + pM1._12 * pM2._24 + pM1._13 * pM2._34 + pM1._14 * pM2._44;
	pOut._21 = pM1._21 * pM2._11 + pM1._22 * pM2._21 + pM1._23 * pM2._31 + pM1._24 * pM2._41;
	pOut._22 = pM1._21 * pM2._12 + pM1._22 * pM2._22 + pM1._23 * pM2._32 + pM1._24 * pM2._42;
	pOut._23 = pM1._21 * pM2._13 + pM1._22 * pM2._23 + pM1._23 * pM2._33 + pM1._24 * pM2._43;
	pOut._24 = pM1._21 * pM2._14 + pM1._22 * pM2._24 + pM1._23 * pM2._34 + pM1._24 * pM2._44;
	pOut._31 = pM1._31 * pM2._11 + pM1._32 * pM2._21 + pM1._33 * pM2._31 + pM1._34 * pM2._41;
	pOut._32 = pM1._31 * pM2._12 + pM1._32 * pM2._22 + pM1._33 * pM2._32 + pM1._34 * pM2._42;
	pOut._33 = pM1._31 * pM2._13 + pM1._32 * pM2._23 + pM1._33 * pM2._33 + pM1._34 * pM2._43;
	pOut._34 = pM1._31 * pM2._14 + pM1._32 * pM2._24 + pM1._33 * pM2._34 + pM1._34 * pM2._44;
	pOut._41 = pM1._41 * pM2._11 + pM1._42 * pM2._21 + pM1._43 * pM2._31 + pM1._44 * pM2._41;
	pOut._42 = pM1._41 * pM2._12 + pM1._42 * pM2._22 + pM1._43 * pM2._32 + pM1._44 * pM2._42;
	pOut._43 = pM1._41 * pM2._13 + pM1._42 * pM2._23 + pM1._43 * pM2._33 + pM1._44 * pM2._43;
	pOut._44 = pM1._41 * pM2._14 + pM1._42 * pM2._24 + pM1._43 * pM2._34 + pM1._44 * pM2._44;

	return pOut;
}








D3DXMATRIX Matrix(Vector3 rot, Vector3 origin = Vector3(0, 0, 0))
{
	float radPitch = (rot.x * float(M_PI) / 180.f);
	float radYaw = (rot.y * float(M_PI) / 180.f);
	float radRoll = (rot.z * float(M_PI) / 180.f);

	float SP = sinf(radPitch);
	float CP = cosf(radPitch);
	float SY = sinf(radYaw);
	float CY = cosf(radYaw);
	float SR = sinf(radRoll);
	float CR = cosf(radRoll);

	D3DMATRIX matrix;
	matrix.m[0][0] = CP * CY;
	matrix.m[0][1] = CP * SY;
	matrix.m[0][2] = SP;
	matrix.m[0][3] = 0.f;

	matrix.m[1][0] = SR * SP * CY - CR * SY;
	matrix.m[1][1] = SR * SP * SY + CR * CY;
	matrix.m[1][2] = -SR * CP;
	matrix.m[1][3] = 0.f;

	matrix.m[2][0] = -(CR * SP * CY + SR * SY);
	matrix.m[2][1] = CY * SR - CR * SP * SY;
	matrix.m[2][2] = CR * CP;
	matrix.m[2][3] = 0.f;

	matrix.m[3][0] = origin.x;
	matrix.m[3][1] = origin.y;
	matrix.m[3][2] = origin.z;
	matrix.m[3][3] = 1.f;

	return matrix;
}



uint64_t ReadChain(uint64_t base, const std::vector<uint64_t>& offsets) {
	uint64_t result = maxread<uint64_t>(base + offsets.at(0));
	for (int i = 1; i < offsets.size(); i++) {
		result = maxread<uint64_t>(result + offsets.at(i));
	}
	return result;
}

std::string GetWeaponryName(uint64_t  key)
{

	//uint64_t name = maxread<uint64_t>(maxread<uint64_t>(maxread<uint64_t>(maxread<uint64_t>(maxread<uint64_t>(key + 0x10) + 0x28) + 0x10) + 0x30) + 0x60);
	uint64_t name = ReadChain(key, { 0x10, 0x28, 0x10, 0x30, +0x60 });

	char Name[256];
	if (name > 10)
	{
		RedByte(name + 0x0, Name, 256);
		return std::string(Name);
	}

	else return "";


}

bool BoneTo1Screen(D3DXMATRIX& m_Matrix, const D3DXVECTOR3& from, D3DXVECTOR2& to)
{
	float ViewW = m_Matrix._14 * from.x + m_Matrix._24 * from.y + m_Matrix._34 * from.z + m_Matrix._44;
	auto width = GetSystemMetrics(SM_CXSCREEN);
	auto height = GetSystemMetrics(SM_CYSCREEN);
	if (ViewW > 0.01f) {
		ViewW = 1.0f / ViewW;
		to.x = (width / 2) + (m_Matrix._11 * from.x + m_Matrix._21 * from.y + m_Matrix._31 * from.z + m_Matrix._41) * ViewW * (width / 2);
		to.y = (height / 2) - (m_Matrix._12 * from.x + m_Matrix._22 * from.y + m_Matrix._32 * from.z + m_Matrix._42) * ViewW * (height / 2);
		return true;
	}
	return false;
}
D3DXVECTOR3 bget_object_pos_component(uintptr_t entity)//坐标
{
	auto bos = ReadChain(entity, { 0x10, 0x28, 0x10, 0x30, 0x30, 0x8 ,0x38 });

	D3DXVECTOR3 StartBone = maxread<D3DXVECTOR3>(bos + 0x90);

	return StartBone;


}

D3DXMATRIX GetMatrix()
{
	uint64_t Camre = maxread<uint64_t>(maxread<uint64_t>(maxread<uint64_t>(maxread<uint64_t>(GameVars.gameManager + 0x10) + 0x10) + 0x30) + 0x18);
	return maxread<D3DXMATRIX>(Camre + 0x2E4);
}

std::string RandomString(int len)
{
	srand(time(NULL));
	std::string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	std::string newstr;
	int pos;
	while (newstr.size() != len) {
		pos = ((rand() % (str.size() - 1)));
		newstr += str.substr(pos, 1);
	}
	return newstr;
}

bool WorldTo1Screen(D3DXMATRIX& m_Matrix, const D3DXVECTOR3& from, D3DXVECTOR2& to, float& Dis)
{
	//float ViewW = m_Matrix._14 * from.x + m_Matrix._24 * from.y + m_Matrix._34 * from.z + m_Matrix._44;
	//Dis = ViewW;
	//auto width = GetSystemMetrics(SM_CXSCREEN);
	//auto height = GetSystemMetrics(SM_CYSCREEN);
	//if (ViewW > 0.01f) {
	//	ViewW = 1.0f / ViewW;
	//	to.x = (width / 2) + (m_Matrix._11 * from.x + m_Matrix._21 * from.y + m_Matrix._31 * from.z + m_Matrix._41) * ViewW * (width / 2);
	//	to.y = (height / 2) - (m_Matrix._12 * from.x + m_Matrix._22 * from.y + m_Matrix._32 * from.z + m_Matrix._42) * ViewW * (height / 2);
	//	return true;
	//}
	//return false;

	float ViewW = m_Matrix._14 * from.x + m_Matrix._24 * from.y + m_Matrix._34 * from.z + m_Matrix._44;
	Dis = ViewW;
	if (ViewW > 0.01f)
	{
		ViewW = 1.0f / ViewW;
		to.x = (GetSystemMetrics(SM_CXSCREEN) / 2) + (m_Matrix._11 * from.x + m_Matrix._21 * from.y + m_Matrix._31 * from.z + m_Matrix._41) * ViewW * (GetSystemMetrics(SM_CXSCREEN) / 2);
		to.y = (GetSystemMetrics(SM_CYSCREEN) / 2) - (m_Matrix._12 * from.x + m_Matrix._22 * from.y + m_Matrix._32 * from.z + m_Matrix._42) * ViewW * (GetSystemMetrics(SM_CYSCREEN) / 2);
		//cout << "x=  " << to.x << "  " << "Y=  " << to.y << endl;
		return true;
	}
	return false;


}

namespace Game




	D3DMATRIX MatrixMultiplication(D3DMATRIX pM1, D3DMATRIX pM2)
	{
		D3DMATRIX pOut;
		pOut._11 = pM1._11 * pM2._11 + pM1._12 * pM2._21 + pM1._13 * pM2._31 + pM1._14 * pM2._41;
		pOut._12 = pM1._11 * pM2._12 + pM1._12 * pM2._22 + pM1._13 * pM2._32 + pM1._14 * pM2._42;
		pOut._13 = pM1._11 * pM2._13 + pM1._12 * pM2._23 + pM1._13 * pM2._33 + pM1._14 * pM2._43;
		pOut._14 = pM1._11 * pM2._14 + pM1._12 * pM2._24 + pM1._13 * pM2._34 + pM1._14 * pM2._44;
		pOut._21 = pM1._21 * pM2._11 + pM1._22 * pM2._21 + pM1._23 * pM2._31 + pM1._24 * pM2._41;
		pOut._22 = pM1._21 * pM2._12 + pM1._22 * pM2._22 + pM1._23 * pM2._32 + pM1._24 * pM2._42;
		pOut._23 = pM1._21 * pM2._13 + pM1._22 * pM2._23 + pM1._23 * pM2._33 + pM1._24 * pM2._43;
		pOut._24 = pM1._21 * pM2._14 + pM1._22 * pM2._24 + pM1._23 * pM2._34 + pM1._24 * pM2._44;
		pOut._31 = pM1._31 * pM2._11 + pM1._32 * pM2._21 + pM1._33 * pM2._31 + pM1._34 * pM2._41;
		pOut._32 = pM1._31 * pM2._12 + pM1._32 * pM2._22 + pM1._33 * pM2._32 + pM1._34 * pM2._42;
		pOut._33 = pM1._31 * pM2._13 + pM1._32 * pM2._23 + pM1._33 * pM2._33 + pM1._34 * pM2._43;
		pOut._34 = pM1._31 * pM2._14 + pM1._32 * pM2._24 + pM1._33 * pM2._34 + pM1._34 * pM2._44;
		pOut._41 = pM1._41 * pM2._11 + pM1._42 * pM2._21 + pM1._43 * pM2._31 + pM1._44 * pM2._41;
		pOut._42 = pM1._41 * pM2._12 + pM1._42 * pM2._22 + pM1._43 * pM2._32 + pM1._44 * pM2._42;
		pOut._43 = pM1._41 * pM2._13 + pM1._42 * pM2._23 + pM1._43 * pM2._33 + pM1._44 * pM2._43;
		pOut._44 = pM1._41 * pM2._14 + pM1._42 * pM2._24 + pM1._43 * pM2._34 + pM1._44 * pM2._44;

		return pOut;
	}




	const char* OperatorNames[29][6] =
	{
		// Credits Dude on UC for opnames. 
		{"AI","SMOKE","MUTE","SLEDGE","THATCHER"}, //0
		{"RECRUIT","CASTLE","ASH","PULSE","THERMITE"}, //1
		{"","DOC","ROOK","TWITCH","MONTAGNE"}, //2
		{"","GLAZ","FUZE","KAPKAN","TACHANKA"}, //3
		{"","BLITZ","IQ","JAGER","BANDIT"}, //4
		{"","BUCK","FROST"}, //5
		{"","BLACKBEARD","VALKYRIE"}, //6
		{"","CAPITAO","CAVEIRA"}, //7
		{"","HIBANA","ECHO"}, //8
		{"","JACKAL","MIRA"}, //9
		{"","YING","LESION"}, //10
		{"","ELA","ZOFIA"}, //11
		{"","DOKKAEBI","VIGIL"}, //12
		{"","","LION","FINKA"}, //13
		{"","MAESTRO","ALIBI"}, //14
		{"","MAVERICK","CLASH"}, //15
		{"","NOMAD","KAID", ""}, //16
		{"","MOZZIE","GRIDLOCK"}, //17
		{"","NOKK"}, //18
		{"","WARDEN"}, //19
		{"","GOYO"}, //20
		{"","AMARU"}, //21
		{"","KALI","WAMAI", "ACE", "ARUNI", "OSA"}, //22
		{"","ORYX", "FLORES"}, //23
		{"","IANA"}, //24
		{"","MELUSI"}, //25
		{"ZERO"}, //26
		{"THUNDERBIRD"}, //26
		{"THORN"}, // 27
	};




};







DWORD GetProcessIDByName(const char* pName)//取自己ID
{
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (INVALID_HANDLE_VALUE == hSnapshot) {
		return NULL;
	}
	PROCESSENTRY32 pe = { sizeof(pe) };
	for (BOOL ret = Process32First(hSnapshot, &pe); ret; ret = Process32Next(hSnapshot, &pe)) {

		char tmpStr[800];
		sprintf_s(tmpStr, "%S", pe.szExeFile);
		if (strcmp(tmpStr, pName) == 0) {
			CloseHandle(hSnapshot);
			return pe.th32ProcessID;
		}
		//printf("%-6d %s\n", pe.th32ProcessID, pe.szExeFile);
	}
	CloseHandle(hSnapshot);
	return 0;
}

