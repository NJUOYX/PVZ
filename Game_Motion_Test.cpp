#include"pch.h"
#include"GameSys.h"


TEST(GameMotionTest,Attack_Motion){
	constexpr auto ATTACK_TIMES = 10;
	constexpr auto ZB_HP = 10;
	constexpr auto ZB_DAMAGE = 1;
	constexpr auto P_HP = 10;
	constexpr auto P_DAMAGE = 1;
	GameLoader loader;
	GameSys sys(loader);
	One_Shot_Plant plant({P_HP,P_DAMAGE});
	Normal_Zombie zb({ZB_HP,ZB_DAMAGE});
	EXPECT_NO_THROW(sys.fill_staff_in_blank({ ROW_INDEX_MIN,1 },&plant));
	EXPECT_NO_THROW(sys.fill_staff_in_blank({ ROW_INDEX_MIN,2 }, &zb));
	auto event_of_plant = sys.find_pos_event({ ROW_INDEX_MIN,1 });
	for (auto i = 0; i < 10; ++i)
	{
		event_of_plant->event_exc();
	}
	EXPECT_FALSE(zb.is_alive());

}