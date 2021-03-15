#include "doctest.h"
#include "snowman.hpp"

using namespace ariel;

#include <string>
#include <algorithm>

using namespace std;

TEST_CASE ("Good snowman code") {
    CHECK(snowman(11111111) == string("       \n _===_ \n (.,.) \n<( : )>\n ( : ) "));
    CHECK(snowman(22222222) == string("  ___  \n ..... \n\\(o.o)/\n (] [) \n (\" \") "));
    CHECK(snowman(33333333) == string("   _   \n  /_\\ \n (O_O) \n/(> <)\\\n (___) "));
    CHECK(snowman(44444444) == string("  ___  \n (_*_) \n (- -) \n (   ) \n (   ) "));
    CHECK(snowman(33232124) == string("   _   \n  /_\\ \n\\(o_O) \n (] [)>\n (   ) "));
    CHECK(snowman(12222212) == string("       \n _===_ \n\\(o.o)/\n ( : ) \n (\" \") "));
    CHECK(snowman(32443333) == string("   _   \n  /_\\ \n (-.-) \n/(> <)\\\n (___) "));
    CHECK(snowman(44444432) == string("  ___  \n (_*_) \n (- -) \n (> <) \n (\" \") "));
    CHECK(snowman(44242123) == string("  ___  \n (_*_) \n\\(o -) \n (] [)>\n (___) "));
    CHECK(snowman(41341144) == string("  ___  \n (_*_) \n (O,-) \n<(   )>\n (   ) "));
    CHECK(snowman(12341214) == string("       \n _===_ \n (O.-)/\n<( : )\n (   ) "));
    CHECK(snowman(12333321) == string("       \n _===_ \n (O.O) \n/(] [)\\\n ( : ) "));
    CHECK(snowman(23232223) == string("  ___  \n ..... \n\\(o_O)/\n (] [) \n (___) "));
    CHECK(snowman(11112311) == string("       \n _===_ \n\\(.,.) \n ( : )\\\n ( : ) "));
    CHECK(snowman(44114432) == string("  ___  \n (_*_) \n (. .) \n (> <) \n (\" \") "));
    CHECK(snowman(23232223) == string("  ___  \n ..... \n (o o) \n ( : ) \n ( : ) "));
    CHECK(snowman(31333342) == string("   _   \n  /_\\ \n (O,O) \n/(   )\\\n (\" \") "));
    CHECK(snowman(43232122) == string("  ___  \n (_*_) \n\\(o_O) \n (] [)>\n (\" \") "));
}

TEST_CASE ("Bad snowman code") {

    //input number too small
    CHECK_THROWS(snowman(555)); 
    CHECK_THROWS(snowman(2));
    CHECK_THROWS(snowman(1232312));
    CHECK_THROWS(snowman(111111));

    //input number too big
    CHECK_THROWS(snowman(123412234));
    CHECK_THROWS(snowman(432112342));  
    CHECK_THROWS(snowman(121212121));
    CHECK_THROWS(snowman(333333333));

    //negative value
    CHECK_THROWS(snowman(-12341234));
    CHECK_THROWS(snowman(-12341235)); 
    CHECK_THROWS(snowman(-11111111));
    CHECK_THROWS(snowman(-23412337));

    //illegal digits
    CHECK_THROWS(snowman(12361238));
    CHECK_THROWS(snowman(12345678));
    CHECK_THROWS(snowman(12361234));
    CHECK_THROWS(snowman(88888888));
}