#include "pch.h"
#include"GameSys.h"
#define DEBUG


#ifdef DEBUG
int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

#endif

#ifdef RUN
int main(int argc, char** argv) {

	return 0;
}
#endif