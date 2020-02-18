#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Player.h"

//This will have our various tests in here
//	I'm thinking the first test is to make sure that each ship 
//		and player is made with the appropriate values

TEST_CASE("A default ctor") {
	Player first;
	CHECK(first.getShipX(0) != NULL);
	CHECK(first.getShipX(1) != NULL);
	CHECK(first.getShipX(2) != NULL);
	CHECK(first.getShipX(3) != NULL);
	CHECK(first.getShipX(4) != NULL);
	CHECK(first.getShipX(5) != NULL);
}