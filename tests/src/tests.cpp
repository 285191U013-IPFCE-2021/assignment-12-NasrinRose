
#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

extern "C"
{
    #include "..\include\duration.h"
}
// See Catch2's documentation: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#scaling-up

// Add your test cases. Dont forget to include header file. 

Duration d0 = Duration();
    Duration d1(5);
    Duration d2(15);
TEST_CASE("Duration and GetDuration")
{

    REQUIRE(d0.getDuration() == 0);
    REQUIRE(d1.getDuration() == 5);
    REQUIRE(d2.getDuration() == 15);
}
TEST_CASE("Tick and Tick()")
{
    d0.tick();
    REQUIRE(d0.getDuration() == 1);
    d1.tick();
    REQUIRE(d1.getDuration() == 6);
    d2.tick();
    REQUIRE(d2.getDuration() == 16);

    d0.tick(4);
    REQUIRE(d0.getDuration() == 5);
    d1.tick(4);
    REQUIRE(d1.getDuration() == 10);
    d2.tick(4);
    REQUIRE(d2.getDuration() == 20);
}
TEST_CASE("Set Alarm and CheckAlarm")
 {
    d0.setAlarm(10);
    REQUIRE(d0.tick(6) == true);
    REQUIRE(d0.Checkalarm()== false);
    d1.setAlarm(20);
    REQUIRE(d1.tick(11) == true);
    REQUIRE(d1.Checkalarm()== false);
    d2.setAlarm(30);
    REQUIRE(d2.tick(11) == true);
    REQUIRE(d2.Checkalarm()== false);
    d0.setAlarm(15);
    REQUIRE(d0.tick() == false);
    
}


