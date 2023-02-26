#pragma once


enum bone_list
{
	pelvis = 1,
	l_hip = 2,
	l_knee = 3,
	l_foot = 4,
	l_toe = 5,
	l_ankle_scale = 6,
	penis = 7,
	GenitalCensor = 8,
	GenitalCensor_LOD0 = 9,
	Inner_LOD0 = 10,
	GenitalCensor_LOD1 = 11,
	GenitalCensor_LOD2 = 12,
	r_hip = 13,
	r_knee = 14,
	r_foot = 15,
	r_toe = 16,
	r_ankle_scale = 17,
	spine1 = 18,
	spine1_scale = 19,
	spine2 = 20,
	spine3 = 21,
	spine4 = 22,
	l_clavicle = 23,
	l_upperarm = 24,
	l_forearm = 25,
	l_hand = 26,
	l_index1 = 27,
	l_index2 = 28,
	l_index3 = 29,
	l_little1 = 30,
	l_little2 = 31,
	l_little3 = 32,
	l_middle1 = 33,
	l_middle2 = 34,
	l_middle3 = 35,
	l_prop = 36,
	l_ring1 = 37,
	l_ring2 = 38,
	l_ring3 = 39,
	l_thumb1 = 40,
	l_thumb2 = 41,
	l_thumb3 = 42,
	IKtarget_righthand_min = 43,
	IKtarget_righthand_max = 44,
	l_ulna = 45,
	neck = 46,
	head = 47,
	jaw = 48,
	eyeTranform = 49,
	l_eye = 50,
	l_Eyelid = 51,
	r_eye = 52,
	r_Eyelid = 53,
	r_clavicle = 54,
	r_upperarm = 55,
	r_forearm = 56,
	r_hand = 57,
	r_index1 = 58,
	r_index2 = 59,
	r_index3 = 60,
	r_little1 = 61,
	r_little2 = 62,
	r_little3 = 63,
	r_middle1 = 64,
	r_middle2 = 65,
	r_middle3 = 66,
	r_prop = 67,
	r_ring1 = 68,
	r_ring2 = 69,
	r_ring3 = 70,
	r_thumb1 = 71,
	r_thumb2 = 72,
	r_thumb3 = 73,
	IKtarget_lefthand_min = 74,
	IKtarget_lefthand_max = 75,
	r_ulna = 76,
	l_breast = 77,
	r_breast = 78,
	BoobCensor = 79,
	BreastCensor_LOD0 = 80,
	BreastCensor_LOD1 = 81,
	BreastCensor_LOD2 = 82,
	collision = 83,
	displacement = 84
};

class bone_t
{
private:
	struct transform_access_read_only_t
	{
		uint64_t transform_data{};
	};

	struct transform_data_t
	{
		uint64_t transform_array{};
		uint64_t transform_indices{};
	};

	struct matrix34_t
	{
		vec4 vec0{};
		vec4 vec1{};
		vec4 vec2{};
	};

	D3DXVECTOR3 get_bone_position(uintptr_t pTransform)
	{
		__m128 result{};

		const __m128 mulVec0 = { -2.000, 2.000, -2.000, 0.000 };
		const __m128 mulVec1 = { 2.000, -2.000, -2.000, 0.000 };
		const __m128 mulVec2 = { -2.000, -2.000, 2.000, 0.000 };

		transform_access_read_only_t transform_access_read_only = maxread<transform_access_read_only_t>(pTransform + 0x38);
		unsigned int index = maxread<unsigned int>(pTransform + 0x40);
		transform_data_t transform_data = maxread<transform_data_t>(transform_access_read_only.transform_data + 0x18);

		if (transform_data.transform_array && transform_data.transform_indices)
		{
			result = maxread<__m128>(transform_data.transform_array + 0x30 * index);
			int transform_index = maxread<int>(transform_data.transform_indices + 0x4 * index);
			int safe = 0;
			while (transform_index >= 0 && safe++ < 200)
			{
				matrix34_t matrix = maxread<matrix34_t>(transform_data.transform_array + 0x30 * transform_index);

				__m128 xxxx = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix.vec1), 0x00));	// xxxx
				__m128 yyyy = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix.vec1), 0x55));	// yyyy
				__m128 zwxy = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix.vec1), 0x8E));	// zwxy
				__m128 wzyw = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix.vec1), 0xDB));	// wzyw
				__m128 zzzz = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix.vec1), 0xAA));	// zzzz
				__m128 yxwy = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix.vec1), 0x71));	// yxwy
				__m128 tmp7 = _mm_mul_ps(*(__m128*)(&matrix.vec2), result);

				result = _mm_add_ps(_mm_add_ps(
					_mm_add_ps(
						_mm_mul_ps(
							_mm_sub_ps(
								_mm_mul_ps(_mm_mul_ps(xxxx, mulVec1), zwxy),
								_mm_mul_ps(_mm_mul_ps(yyyy, mulVec2), wzyw)),
							_mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(tmp7), 0xAA))),
						_mm_mul_ps(
							_mm_sub_ps(
								_mm_mul_ps(_mm_mul_ps(zzzz, mulVec2), wzyw),
								_mm_mul_ps(_mm_mul_ps(xxxx, mulVec0), yxwy)),
							_mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(tmp7), 0x55)))),
					_mm_add_ps(
						_mm_mul_ps(
							_mm_sub_ps(
								_mm_mul_ps(_mm_mul_ps(yyyy, mulVec0), yxwy),
								_mm_mul_ps(_mm_mul_ps(zzzz, mulVec1), zwxy)),
							_mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(tmp7), 0x00))),
						tmp7)), *(__m128*)(&matrix.vec0));

				transform_index = maxread<int>(transform_data.transform_indices + 0x4 * transform_index);
			}
		}

		return D3DXVECTOR3(result.m128_f32[0], result.m128_f32[1], result.m128_f32[2]);
	}
public:
	D3DXVECTOR3 get_entity_bone(uintptr_t player, int bone_index)
	{
		uintptr_t player_model = maxread<uintptr_t>(player + 0xA8); // BaseEntity->model
		uintptr_t bone_transforms = maxread<uintptr_t>(player_model + 0x28); // Model->boneTransforms
		bone_transforms = maxread<uintptr_t>(bone_transforms + 0x28); // Model->boneTransforms
		bone_transforms = maxread<uintptr_t>(bone_transforms + 0x10); // Model->boneTransforms
		uintptr_t entity_bone = maxread<uintptr_t>(bone_transforms + (0x20 + (bone_index * 0x8)));
		uintptr_t bone = maxread<uintptr_t>(entity_bone + 0x10);
		return get_bone_position(bone);
	}
} bone;


//HumanBase = 0,
//HumanPelvis = 14,
//HumanLThigh1 = 15,
//HumanLThigh2 = 16,
//HumanLCalf = 17,
//HumanLFoot = 18,
//HumanLToe = 19,
//HumanRThigh1 = 20,
//HumanRThigh2 = 21,
//HumanRCalf = 22,
//HumanRFoot = 23,
//HumanRToe = 24,
//HumanSpine1 = 29,
//HumanSpine2 = 36,
//HumanSpine3 = 37,
//HumanLCollarbone = 89,
//HumanLUpperarm = 90,
//HumanLForearm1 = 91,
//HumanLForearm2 = 92,
//HumanLForearm3 = 93,
//HumanLPalm = 94,
//HumanRCollarbone = 110,
//HumanRUpperarm = 111,
//HumanRForearm1 = 112,
//HumanRForearm2 = 113,
//HumanRForearm3 = 114,
//HumanRPalm = 115,
//HumanNeck = 132,
//HumanHead = 133