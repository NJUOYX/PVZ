#include"pch.h"
#include"GameSys.h"


TEST(GameMotionTest,One_Shot_Attack_Motion){
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
	for (auto i = 0; i < ATTACK_TIMES; ++i)
	{
		event_of_plant->event_exc();
	}
	EXPECT_FALSE(zb.is_alive());

}

TEST(GameMotionTest, Zombie_Move_Motion) {
	constexpr auto ZB_HP = 10;
	constexpr auto ZB_DAMAGE = 1;
	constexpr auto ZB_SPEED = 1;
	constexpr auto INIT_COL = 5;
	constexpr auto FIN_COL = 0;
	constexpr auto TIMES = (INIT_COL - FIN_COL) / ZB_SPEED;
	GameLoader loader;
	GameSys sys(loader);
	Normal_Zombie zb({ ZB_HP,ZB_DAMAGE });
	EXPECT_NO_THROW(sys.fill_staff_in_blank({ ROW_INDEX_MIN,INIT_COL }, &zb));
	for (auto i = 0; i < TIMES; ++i) {
		EXPECT_EQ(&sys.view_staff({ ROW_INDEX_MIN,INIT_COL - i }), &zb);
		auto event_of_zb = sys.find_pos_event({ ROW_INDEX_MIN,INIT_COL - i });
		event_of_zb->event_exc();
	}
}