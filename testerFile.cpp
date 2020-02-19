#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Player.h"
#include <iostream>
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

	Player second;
	SUBCASE("The getShipX function for second AI player")
	{
		CHECK(second.getShipX(0) >= 0);
		CHECK(second.getShipX(1) >= 0);
		CHECK(second.getShipX(2) >= 0);
		CHECK(second.getShipX(3) >= 0);
		CHECK(second.getShipX(4) >= 0);
	}
	SUBCASE("The getShipY function for second AI player")
	{
		CHECK(second.getShipY(0) >= 0);
		CHECK(second.getShipY(1) >= 0);
		CHECK(second.getShipY(2) >= 0);
		CHECK(second.getShipY(3) >= 0);
		CHECK(second.getShipY(4) >= 0);
	}
	SUBCASE("The name of second AI player")
	{
		CHECK(second.getName() == "NPC");
	}
	/*SUBCASE("Two AI players should not have all their ships in the same place")
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				CHECK(first.getShipX(i) != second.getShipX(j));
				CHECK(first.getShipY(i) != second.getShipY(j));
			}
		}
	}*/
}

TEST_CASE("The player ctor") 
{
	SUBCASE("The player name #1")
	{
		Player second("Tommy");
		CHECK(second.getName() == "Tommy");
	}
	SUBCASE("The player name #2")
	{
		Player second("Marigold");
		CHECK(second.getName() == "Marigold");
	}

}

TEST_CASE("Fill second's vector with ships")
{
	Player second("Tommy"); 
	SUBCASE("Size of second's vector of ships")
	{
		second.createShips();
		REQUIRE(second.getNumOfShips() == 5);

		SUBCASE("The getShipX function for player")
		{
			CHECK(second.getShipX(0) >= 0);
			CHECK(second.getShipX(1) >= 0);
			CHECK(second.getShipX(2) >= 0);
			CHECK(second.getShipX(3) >= 0);
			CHECK(second.getShipX(4) >= 0);

			SUBCASE("The getShipY function for player")
			{
				CHECK(second.getShipY(0) >= 0);
				CHECK(second.getShipY(1) >= 0);
				CHECK(second.getShipY(2) >= 0);
				CHECK(second.getShipY(3) >= 0);
				CHECK(second.getShipY(4) >= 0);
			}
		}
	}
}

TEST_CASE("Testing firing")
{
	Player first;
	Player second;
	auto p = std::make_pair(second.getShipX(1), second.getShipY(1));
	auto p2 = std::make_pair(second.getShipX(1)+3, second.getShipY(1));
	CHECK(first.playerfire(second, p));
	CHECK(first.playerfire(first, p) != false);
	SUBCASE("Reduce hits after each hit")
	{
		CHECK(first.playerfire(second, p));
		CHECK
		CHECK(first.playerfire(second, p));

	}
	CHECK(first.playerfire(first, p2) == false);


}