#include "function.h"
#include "driverloading.h"
#include "overlay.h"
#include "menucycle.h"
#include "bone.h"
//#include "allnames.h"

typedef struct
{
	const char* name;
	DWORD  color;
	std::string EAname;
}WORLDDATA;

namespace OverlayWindow
{
	WNDCLASSEX WindowClass;
	HWND Hwnd;
	LPCSTR Name;
}
typedef struct _EntityList
{
	uintptr_t actor_camp;
	uintptr_t actor_pawn;
	uintptr_t actor_mesh;
	WORLDDATA actor_ADAD;
	string PLNAME;
	Vector3  distance;
	string actor_name;
	float Health;
	uintptr_t actor_state;
	int actor_id;

}EntityList;
std::vector<EntityList> entityList;

typedef struct _EntityItem
{
	uintptr_t actor_pawn;
	WORLDDATA actor_ADAD;
	Vector3  distance;

}EntityItem;
std::vector<EntityItem> entityItem;





class textx
{
public:
	wchar_t word[64];
};


std::string BoxLocalPlayer(std::string& Gname, WORLDDATA& data)
{
	if (CFG.b_EspBox)
	{
		if (Gname == findTargetString(Gname, "Player"))
		{
			data.color = D2D1::ColorF::Red;
			data.name = "玩家";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == findTargetString(Gname, "Bot"))
		{
			data.color = D2D1::ColorF::DarkOrange;
			data.name = "人机";
			data.EAname = Gname;
			return "A";
		}
	}
	//return "";

	return "";
}

std::string Valuableobjects(std::string& Gname, WORLDDATA& data)
{
	if (CFG.b_Vehicle)
	{
		if (Gname == findTargetString(Gname, "item_keycard_interchange_"))
		{
			data.color = D2D1::ColorF::Red;
			data.name = "#SR门卡";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "mag_stanag_maopul_pmag_airsoft_6_30(Clone)")
		{
			data.color = D2D1::ColorF::Red;
			data.name = "ASADF";
			data.EAname = Gname;
			return "A";
		}	
		else if (Gname == "mount_m_lok_magpul_offset_light_optic_mount(Clone)")
		{
			data.color = D2D1::ColorF::Red;
			data.name = "ASADF";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_flash_card_ironkey(Clone)")
		{
			data.color = D2D1::ColorF::Red;
			data.name = "U盘";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_info_intelligence(Clone)")
		{
			data.color = D2D1::ColorF::Red;
			data.name = "情报";
			data.EAname = Gname;
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_barter_valuable_elibadge(Clone)")
		{
			data.color = D2D1::ColorF::Red;
			data.name = "徽章";
			data.EAname = Gname;
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_barter_valuable_gp(Clone)")
		{
			data.color = D2D1::ColorF::Red;
			data.name = "GP";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_barter_medical_defibrillator(Clone)")
		{
			data.color = D2D1::ColorF::Red;
			data.name = "除颤器";
			data.EAname = Gname;
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_spec_armorrepair(Clone)")
		{
			data.color = D2D1::ColorF::Red;
			data.name = "维修包";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_thick_diary(Clone)")
		{
			data.color = D2D1::ColorF::Red;
			data.name = "日记";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_barter_other_airfilter(Clone)")
		{
			data.color = D2D1::ColorF::Red;
			data.name = "过滤吸收器";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_barter_electr_sas(Clone)")
		{
			data.color = D2D1::ColorF::Pink;
			data.name = "SVD";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_barter_medical_transilluminator(Clone)")
		{
			data.color = D2D1::ColorF::Pink;
			data.name = "LED";
			return "A";
		}
		else if (Gname == findTargetString(Gname, "item_key_"))
		{
			data.color = D2D1::ColorF::Pink;
			data.name = "钥匙";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_keycard_lab_yellow(Clone)")
		{
			data.color = D2D1::ColorF::Yellow;
			data.name = "黄卡";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_keycard_lab_red(Clone)")
		{
			data.color = D2D1::ColorF::Red;
			data.name = "红卡";
			return "A";
		}
		else if (Gname == "item_keycard_lab_purple(Clone)")
		{
			data.color = D2D1::ColorF::Purple;
			data.name = "紫卡";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_keycard_lab_blue(Clone)")
		{
			data.color = D2D1::ColorF::Blue;
			data.name = "蓝卡";
			return "A";
		}
		else if (Gname == "item_keycard_lab_black(Clone)")
		{
			data.color = D2D1::ColorF::Black;
			data.name = "黑卡";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_keycard_lab_white(Clone)")
		{
			data.color = D2D1::ColorF::PaleVioletRed;
			data.name = "白卡";
			return "A";
		}
		else if (Gname == "item_barter_electr_ssd(Clone)")
		{
			data.color = D2D1::ColorF::Pink;
			data.name = "SSD";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == findTargetString(Gname, "item_money_"))
		{
			data.color = D2D1::ColorF::Pink;
			data.name = "钱";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_manual_lada(Clone)")
		{
			data.color = D2D1::ColorF::Pink;
			data.name = "手册";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_barter_valuable_bitcoin(Clone)")
		{
			data.color = D2D1::ColorF::Pink;
			data.name = "BTC";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_barter_valuable_raven(Clone)")
		{
			data.color = D2D1::ColorF::Pink;
			data.name = "乌鸦";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_barter_valuable_chicken(Clone)")
		{
			data.color = D2D1::ColorF::Pink;
			data.name = "金鸡";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_video_card(Clone)")
		{
			data.color = D2D1::ColorF::Pink;
			data.name = "显卡";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_quest_barter_valuable_teapot(Clone)")
		{
			data.color = D2D1::ColorF::Pink;
			data.name = "茶壶";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_barter_valuable_rolex(Clone)")
		{
			data.color = D2D1::ColorF::Pink;
			data.name = "劳力士";
			return "A";
		}
		else if (Gname == "item_barter_valuable_skullring(Clone)")
		{
			data.color = D2D1::ColorF::Pink;
			data.name = "骷髅";
			data.EAname = Gname;
			return "A";
		}
	
		else if (Gname == "item_barter_valuable_nyball_violet(Clone)")
		{
			data.color = D2D1::ColorF::Orange;
			data.name = "紫球";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_horse_figurine(Clone)")
		{
			data.color = D2D1::ColorF::Orange;
			data.name = "马";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_barter_valuable_cat(Clone)")
		{
			data.color = D2D1::ColorF::Orange;
			data.name = "猫";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_barter_valuable_kresalo(Clone)")
		{
			data.color = D2D1::ColorF::Orange;
			data.name = "火链";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_barter_other_dobby(Clone)")
		{
			data.color = D2D1::ColorF::Orange;
			data.name = "书";
			return "A";
		}
		else if (Gname == "item_barter_valuable_woodclock(Clone)")
		{
			data.color = D2D1::ColorF::Orange;
			data.name = "钟调";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_barter_valuable_prokill(Clone)")
		{
			data.color = D2D1::ColorF::Orange;
			data.name = "项链";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_chain_gold(Clone)")
		{
			data.color = D2D1::ColorF::Orange;
			data.name = "金链";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_quest_barter_valuable_vase(Clone)")
		{
			data.color = D2D1::ColorF::Orange;
			data.name = "花瓶";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_barter_valuable_lion(Clone)")
		{
			data.color = D2D1::ColorF::Orange;
			data.name = "沙雕";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_chain(Clone)")
		{
			data.color = D2D1::ColorF::Orange;
			data.name = "项链";
			data.EAname = Gname;
			return "A";
		}

		else if (Gname == "item_barter_electr_tetriz(Clone)")
		{
			data.color = D2D1::ColorF::Orange;
			data.name = "游戏机";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_barter_electr_cablemilitary(Clone)")
		{
			data.color = D2D1::ColorF::Orange;
			data.name = "军用电缆";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_barter_medical_bloodset(Clone)")
		{
			data.color = D2D1::ColorF::Coral;
			data.name = "输血工具";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_barter_electr_gyrotachometer(Clone)")
		{
			data.color = D2D1::ColorF::Coral;
			data.name = "军用计数器";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_barter_valuable_1gphone(Clone)")
		{
			data.color = D2D1::ColorF::Coral;
			data.name = "苹果13pro";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_spec_ipcamera(Clone)")
		{
			data.color = D2D1::ColorF::Coral;
			data.name = "摄像头";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_barter_electr_militaryboard(Clone)")
		{
			data.color = D2D1::ColorF::Coral;
			data.name = "军用电路板";
			data.EAname = Gname;
			return "A";
		}

	}
	if (CFG.b_medical)
	{

		if (Gname == "item_ibuprofen_loot(Clone)")
		{
			data.color = D2D1::ColorF::Chartreuse;
			data.name = "布洛芬";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_ifak_loot(Clone)")
		{
			data.color = D2D1::ColorF::Chartreuse;
			data.name = "单兵急救包";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_augmentin_loot(Clone)")
		{
			data.color = D2D1::ColorF::Chartreuse;
			data.name = "百力丁";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_meds_survival_first_aid_rollup_kit_loot(Clone)")
		{
			data.color = D2D1::ColorF::Chartreuse;
			data.name = "战术手术包";
			data.EAname = Gname;
			return "A";
		}
		//else if (Gname == "item_grizzly_loot(Clone)")
		//{
		//	data.color = ImColor(0, 255, 0);
		//	data.name = "grizziy急救包";
		//	return true;
		//}
		else if (findTargetString(Gname, "item_stimulator_") != "")
		{
			data.color = D2D1::ColorF::Chartreuse;
			data.name = "针剂";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_vaselin_loot(Clone)")
		{
			data.color = D2D1::ColorF::Chartreuse;
			data.name = "凡士林";
			data.EAname = Gname;
			return "A";
		}


	}

	if (CFG.b_parts)
	{
		if (Gname == "scope_all_holosun_hs401g5(Clone)")
		{
			data.color = D2D1::ColorF::Orchid;
			data.name = "hs401g5瞄准镜";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "scope_all_valday_ps320(Clone)")
		{
			data.color = D2D1::ColorF::Orchid;
			data.name = "PS320瞄准镜";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "scope_g36_hensoldt_hkv_carry_handle_3x(Clone)")
		{
			data.color = D2D1::ColorF::Orchid;
			data.name = "三倍镜";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "muzzle_ak_srvv_mbrfhmb_762_762x39(Clone)")
		{
			data.color = D2D1::ColorF::Orchid;
			data.name = "补偿器";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "mount_mp443_zenit_b8(Clone)")
		{
			data.color = D2D1::ColorF::Orchid;
			data.name = "B-8基座";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "pistolgrip_ar15_stark_ar_rifle_grip_blk(Clone)")
		{
			data.color = D2D1::ColorF::Orchid;
			data.name = "AR15握柄";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "mag_tt_toz_std_762x25tt_8(Clone)")
		{
			data.color = D2D1::ColorF::Orchid;
			data.name = "TT 弹夹";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "mag_pm_izhmeh_9x18pm_8(Clone)")
		{
			data.color = D2D1::ColorF::Orchid;
			data.name = "9x18弹夹";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "mag_ak_izhmash_ak_std_55_762x39_30(Clone)")
		{
			data.color = D2D1::ColorF::Orchid;
			data.name = "762x39弹夹";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "mag_stanag_surefire_mag5_556x45_100(Clone)")
		{
			data.color = D2D1::ColorF::Orchid;
			data.name = "MAG5弹夹";
			data.EAname = Gname;
			return "A";
		}

	}
	if (CFG.b_Airdrop)
	{
		if (Gname == "item_ammo_box_762x39_20(Clone)")
		{
			data.color = D2D1::ColorF::Purple;
			data.name = "762x39子弹";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_ammo_box_545x39_120_BT(Clone)")
		{
			data.color = D2D1::ColorF::Purple;
			data.name = "545x39子弹";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_ammo_box_545x39_120_PRS(Clone)")
		{
			data.color = D2D1::ColorF::Purple;
			data.name = "545x39子弹";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_ammo_box_9x18pm_16(Clone)")
		{
			data.color = D2D1::ColorF::Purple;
			data.name = "9x18 子弹";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "item_ammo_box_545x39_30(Clone)")
		{
			data.color = D2D1::ColorF::Purple;
			data.name = "545x39子弹";
			data.EAname = Gname;
			return "A";
		}
	}
	if (CFG.b_weapon)
	{
		if (Gname == "weapon_colt_m4a1_556x45_container(Clone)")
		{
			data.color = D2D1::ColorF::Khaki;
			data.name = "M4A1";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "weapon_izhmash_ak74m_545x39_container(Clone)")
		{
			data.color = D2D1::ColorF::Khaki;
			data.name = "AK74m";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "weapon_izhmash_ak74n_545x39_container(Clone)")
		{
			data.color = D2D1::ColorF::Khaki;
			data.name = "AK74N";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "weapon_izhmash_aks74u_545x39_container(Clone)")
		{
			data.color = D2D1::ColorF::Khaki;
			data.name = "AK74U";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "weapon_izhmash_aks74ub_545x39_container(Clone)")
		{
			data.color = D2D1::ColorF::Khaki;
			data.name = "AK74ub";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "weapon_dt_mdr_762x51_container(Clone)")
		{
			data.color = D2D1::ColorF::Khaki;
			data.name = "MBR步枪";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "weapon_molot_op_sks_762x39_container(Clone)")
		{
			data.color = D2D1::ColorF::Khaki;
			data.name = "SKS";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "weapon_hk_mp5_navy3_9x19_container(Clone)")
		{
			data.color = D2D1::ColorF::Khaki;
			data.name = "MP5";
			data.EAname = Gname;
			return "A";
		}
		else if (Gname == "weapon_beretta_m9a3_9x19_container(Clone)")
		{
			data.color = D2D1::ColorF::Khaki;
			data.name = "m9a3手枪";
			data.EAname = Gname;
			return "A";
		}
	}


		


	//


	return "";

}




auto CallAimbot()->VOID
{

	while (true)
	{
		auto EntityList_Copy = entityList;	
		bool isAimbotActive = CFG.b_aiming;
		if (isAimbotActive)
		{
			float target_dist = FLT_MAX;
			EntityList target_entity = {};
			auto m_Matrix = GetMatrix();
			Vector3 head_pos;
			float weaponsdistance;
			if (GetAsyncKeyState(VK_RBUTTON) != 0)
			{
				for (int index = 0; index < EntityList_Copy.size(); ++index)
				{
					auto Entity = EntityList_Copy[index];
					D3DXVECTOR2 HeadScreen;
					if (CFG.b_radial)
					{
						if (!BoneTo1Screen(m_Matrix, bone.get_entity_bone(Entity.actor_pawn, 37), HeadScreen)) continue;
					}
					else
					{
						if (!BoneTo1Screen(m_Matrix, bone.get_entity_bone(Entity.actor_pawn, 133), HeadScreen)) continue;
					}
	
					float x = HeadScreen.x - GetSystemMetrics(SM_CXSCREEN) / 2.0f;
					float y = HeadScreen.y - GetSystemMetrics(SM_CYSCREEN) / 2.0f;
					float crosshair_dist = sqrtf((x * x) + (y * y));
					if (crosshair_dist <= FLT_MAX && crosshair_dist <= target_dist)
					{
						if (crosshair_dist > CFG.AimbotFOV) // FOV
							continue;
						target_dist = crosshair_dist;
						target_entity = Entity;

					}

				}

				if (target_entity.actor_mesh != 0 || target_entity.actor_pawn != 0 || target_entity.actor_id != 0)
				{
					D3DXVECTOR2 HeadScreen;
					   if (CFG.b_radial)
					{
						if (!BoneTo1Screen(m_Matrix, bone.get_entity_bone(target_entity.actor_pawn, 37), HeadScreen)) continue;
					}
					else
					{
					   if (!BoneTo1Screen(m_Matrix, bone.get_entity_bone(target_entity.actor_pawn, 133), HeadScreen)) continue;
					}
					

					AimBot_API(HeadScreen.x, HeadScreen.y);
		









					//move_to(targethead.x, targethead.y);

					

				}

			}

		}


		Sleep(10);
	}
}


struct BaseObject
{
	uint64_t previousObjectLink; //0x0000
	uint64_t nextObjectLink; //0x0008
	uint64_t object; //0x0010
};
uint64_t GetObjectFromList(uint64_t listPtr, uint64_t lastObjectPtr, const char* objectName)
{
	char name[256];
	uint64_t classNamePtr = 0x0;

	BaseObject activeObject = maxread<BaseObject>(listPtr);
	BaseObject lastObject = maxread<BaseObject>(lastObjectPtr);
	//  std::cout << "-------------------" << std::endl;
	if (activeObject.object != 0x0)
	{
		while (activeObject.object != 0 && activeObject.object != lastObject.object)
		{
			classNamePtr = maxread<uint64_t>(activeObject.object + 0x60);
			RedByte(classNamePtr + 0x0, name, 256);
			//   std::cout << name << std::endl;
			if (strcmp(name, objectName) == 0)
			{
				return activeObject.object;
			}

			activeObject = maxread<BaseObject>(activeObject.nextObjectLink);
		}
	}
	if (lastObject.object != 0x0)
	{
		classNamePtr = maxread<uint64_t>(lastObject.object + 0x60);
		RedByte(classNamePtr + 0x0, name, 256);
		// std::cout << name << std::endl;
		if (strcmp(name, objectName) == 0)
		{
			return lastObject.object;
		}
	}
	//  std::cout << "-------------------" << std::endl;
	return uint64_t();
}



uint64_t g_gameWorld(uint64_t len)
{
	auto SA = maxread<std::array<uint64_t, 2>>(len + 0x20);

	uint64_t World= GetObjectFromList(SA[1], SA[0], "GameWorld");
 
	//GameVars.localGameWorld = ReadChain(World, { 0x30, 0x18, 0x28 });
	return ReadChain(World, { 0x30, 0x18, 0x28 });
}




auto GameCache()->VOID
{

	while (true)
	{
		std::vector<EntityList> tmpList;
		std::vector<EntityItem> tmpItem;

		//BYTE * patternCOM = ( BYTE *) "\xE8\x00\x00\x00\x00\x4C\x8B\x05\x00\x00\x00\x00\x33\xD2" ; 
		//BYTE* patternGOM = (BYTE*)"\x48\x89\x09\x48\x89\x05\x00\x00\x00\x00\x48\x83\xC4\x38";
		//E8 ? ? ? ? 4C 8B 05 ? ? ? ? 33 D2
		GameVars.gameManager = maxread<uint64_t>(GameVars.dwProcess_Base + 0x17ffd28);

		auto onlineusers = maxread<uint64_t>(g_gameWorld(GameVars.gameManager) + 0x80);
		uint64_t Aactors = maxread<uint64_t>(onlineusers + 0x10);
		int entityCount = maxread<int>(onlineusers + 0x18);
		auto PYonlineusers = maxread<uint64_t>(g_gameWorld(GameVars.gameManager) + 0xA0);
		uint64_t PYAactors = maxread<uint64_t>(PYonlineusers + 0x10);
		int PYentityCount = maxread<int>(PYonlineusers + 0x18);
		

		if (CFG.b_endurance)
		{

			uint64_t endurance = ReadChain(PYAactors, { 0x20, 0x530, 0x38 });

			write<float>(endurance+0x48, 100.0f);

		}
		if (CFG.b_Recoil)
		{
			uint64_t Aendurance = ReadChain(PYAactors, { 0x20, 0x1A0, 0x48 });
			write<float>(Aendurance + 0x70, 0.0f);
			write<float>(Aendurance + 0x78, 0.0f);
		}

			//' Player -> [530] Physical : -.GClass0627-> [38] Stamina : -.GClass0625-> [48] Current : Single
			//' Player->ProceduralWeaponAnimation(0x1A0)->ShotEffector(0x48)->Intensity(0x78) 设置为 0.f



		for (int i = 0; i < PYentityCount; i++)
		{

			uint64_t pawn = maxread<uint64_t>(PYAactors + 32 + (i * 0x8));
			if (pawn == 0x00)
				continue;
			auto intName = GetWeaponryName(pawn);
			if (intName == "")continue;
			WORLDDATA Adata = { NULL };
			BoxLocalPlayer(intName, Adata);
			if (intName == Adata.EAname)
			{

				EntityList Entity{ };
				Entity.actor_pawn = pawn;
				Entity.actor_ADAD = Adata;
				tmpList.push_back(Entity);
			}
		}
		
		for (int i = 0; i < entityCount; i++)
		{
			uint64_t pawn = maxread<uint64_t>(Aactors + 32 + (i * 0x8));
			if (pawn == 0x00)
				continue;
			auto intName = GetWeaponryName(pawn);
			if (intName == "")continue;

			WORLDDATA Bdata = { NULL };

			Valuableobjects(intName, Bdata);
			if (intName == Bdata.EAname)
			{
				EntityItem Entity{ };
				Entity.actor_pawn = pawn;
				Entity.actor_ADAD = Bdata;
				tmpItem.push_back(Entity);



			}




		}
		entityList = tmpList;
		entityItem = tmpItem;
		Sleep(10);
	}

}




auto RenderItem()->VOID
{

	float dis = 0.f;
	auto m_Matrix = GetMatrix();
	auto EntityItem_Copy = entityItem;
	for (int i = 0; i < EntityItem_Copy.size(); i++)
	{
		auto Entity = EntityItem_Copy[i];
		D3DXVECTOR3 StartBone = bget_object_pos_component(Entity.actor_pawn);
		D3DXVECTOR2  EndBone;
		D3DXVECTOR3 Start = StartBone;
		D3DXVECTOR2 StartEnd;
		Start.y = Start.y + 1.7;
		if (!WorldTo1Screen(m_Matrix, StartBone, EndBone, dis)) continue;
		if (!WorldTo1Screen(m_Matrix, Start, StartEnd, dis)) continue;
		if(dis>=2000)continue;
		char xdis[64];
		sprintf_s(xdis, "Dist:%.fm", dis);
		DrawRenderTextA(EndBone.x, EndBone.y, Entity.actor_ADAD.name, Entity.actor_ADAD.color, pTextFormatKaiTi, 11.0f);
		DrawRenderTextA(EndBone.x, EndBone.y+11, xdis, Entity.actor_ADAD.color, pTextFormatKaiTi, 11.0f);
	}
}

auto RenderVisual()->VOID
{
	float dis = 0.f;
	auto m_Matrix = GetMatrix();
	auto EntityList_Copy = entityList;
	for (int i = 0; i < EntityList_Copy.size(); i++)
	{
		auto Entity = EntityList_Copy[i];
		D3DXVECTOR3 StartBone = bget_object_pos_component(Entity.actor_pawn);
		D3DXVECTOR2  EndBone;
		D3DXVECTOR3 Start = StartBone;
		D3DXVECTOR2 StartEnd;
		Start.y = Start.y + 1.7;
		if (!WorldTo1Screen(m_Matrix, StartBone, EndBone, dis)) continue;
		if (!WorldTo1Screen(m_Matrix, Start, StartEnd, dis)) continue;
		char xdis[64];
		sprintf_s(xdis, "Dist:%.fm", dis);





		if (Entity.actor_ADAD.name == "玩家")
		{
			auto pyname = ReadChain(Entity.actor_pawn, { 0x520, 0x28, 0x10 });
			auto NAME = read_wstring(pyname + 0x14);
			DrawBox(StartEnd.x - (EndBone.y - StartEnd.y) / 4, StartEnd.y, (EndBone.y - StartEnd.y) / 2, EndBone.y - StartEnd.y, Entity.actor_ADAD.color);
			DrawRenderTextA(EndBone.x, EndBone.y, NAME.c_str(), Entity.actor_ADAD.color, pTextFormatKaiTi, 11.0f);
			DrawRenderTextA(EndBone.x, EndBone.y + 11, xdis, Entity.actor_ADAD.color, pTextFormatKaiTi, 11.0f);
		}
		else
		{

			DrawBox(StartEnd.x - (EndBone.y - StartEnd.y) / 4, StartEnd.y, (EndBone.y - StartEnd.y) / 2, EndBone.y - StartEnd.y, Entity.actor_ADAD.color);
			DrawRenderTextA(EndBone.x, EndBone.y,"人机", Entity.actor_ADAD.color, pTextFormatKaiTi, 11.0f);
			DrawRenderTextA(EndBone.x, EndBone.y + 11, xdis, Entity.actor_ADAD.color, pTextFormatKaiTi, 11.0f);

		}



		
		
		
		
	}

}



int APIENTRY  main(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ char* lpCmdLine, _In_ int nCmdShow)
{



	Sleep(10);
	GameVars.dwProcessName = "EscapeFromTarkov.exe";

	HWND gameHwnd = FindWindowA("UnityWndClass", "EscapeFromTarkov");
	GameVars.gameHWND = gameHwnd;
	GetWindowThreadProcessId(gameHwnd, &GameVars.PID);
	GameVars.dwProcess_Base = GetModuleAddress(L"UnityPlayer.dll");
	GameVars.ScreenWidth = GetSystemMetrics(SM_CXSCREEN);
	GameVars.ScreenHeight = GetSystemMetrics(SM_CYSCREEN);



	//cout << GameVars.dwProcess_Base << endl;
	//printf("[+] ProcessName: %s ID: (%d) base: %llx\n", GameVars.dwProcessName, GameVars.dwProcessId, GameVars.dwProcess_Base);

	//#pragma comment(linker,"/subsystem:\"Windows\" /entry:\"mainCRTStartup\"")
	CreateThread(nullptr, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(GameCache), nullptr, NULL, nullptr);
	//CreateThread(nullptr, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(CallHacks), nullptr, NULL, nullptr);
	//CreateThread(nullptr, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(Weapon), nullptr, NULL, nullptr);

	CreateThread(nullptr, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(CallAimbot), nullptr, NULL, nullptr);

}
