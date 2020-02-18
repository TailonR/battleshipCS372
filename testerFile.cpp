#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Player.h"

//This will have our various tests in here
//	I'm thinking the first test is to make sure that each ship 
//		and player is made with the appropriate values

TEST_CASE("The AI ctor") 
{
	Player first;
	SUBCASE("The getShipX function")
	{
		CHECK(first.getShipX(0) >= 0);
		CHECK(first.getShipX(1) >= 0);
		CHECK(first.getShipX(2) >= 0);
		CHECK(first.getShipX(3) >= 0);
		CHECK(first.getShipX(4) >= 0);
	}
	SUBCASE("The getShipY function")
	{
		CHECK(first.getShipY(0) >= 0);
		CHECK(first.getShipY(1) >= 0);
		CHECK(first.getShipY(2) >= 0);
		CHECK(first.getShipY(3) >= 0);
		CHECK(first.getShipY(4) >= 0);
	}
	SUBCASE("The name of AI player")
	{
		CHECK(first.getName() == "NPC");
	}
}

TEST_CASE("The player ctor") {
	Player second("Tommy");

	SUBCASE("The player name")
	{
		CHECK(second.getName() == "Tommy");
	}
	SUBCASE("The getShipX function for player")
	{
		CHECK(second.getShipX(0) >= 0);
		CHECK(second.getShipX(1) >= 0);
		CHECK(second.getShipX(2) >= 0);
		CHECK(second.getShipX(3) >= 0);
		CHECK(second.getShipX(4) >= 0);
	}
}