#include <boost/test/unit_test.hpp>
#include <string>
#include <cmath>
#include "Vec3.h"

BOOST_AUTO_TEST_SUITE(Vec3_tests);

BOOST_AUTO_TEST_CASE(equality) {
    BOOST_CHECK(Vec3 (-7, .125, 9) == Vec3 (-7, .125, 9));
    BOOST_CHECK(!(Vec3 (-7, .126, 9) == Vec3 (-7, .125, 9)));
    BOOST_CHECK(!(Vec3 (-5, 19.2, 8) == Vec3 (-5, 19.2, 8.1)));
    BOOST_CHECK(Vec3 (14, 182, 9.9) != Vec3 (-14, 182, 9.9));
}

BOOST_AUTO_TEST_CASE(addition) {
    BOOST_CHECK(Vec3 (5, -8, 17.221) + Vec3 (-7, 14.0f, 19.6) == Vec3 (-2, 6, 36.821));
}

BOOST_AUTO_TEST_CASE(subtraction) {
    BOOST_CHECK(Vec3 (4, 6.2, 11.89) - Vec3 (178, 9, 4.4) == Vec3 (-174, -2.8, 7.49));
}

BOOST_AUTO_TEST_CASE(multiplication) {
    BOOST_CHECK(Vec3 (9, 3.2, 8) * 7.889 == Vec3 (71.001, 25.2448, 63.112));
}

BOOST_AUTO_TEST_CASE(compound_assignment) {
    Vec3 v (13, 15, 17);
    BOOST_CHECK((v += Vec3 (1, 2, 3)) == Vec3 (14, 17, 20));
    BOOST_CHECK(v == Vec3 (14, 17, 20));
    BOOST_CHECK((v -= Vec3 (1, 2, 3)) == Vec3 (13, 15, 17));
    BOOST_CHECK(v == Vec3 (13, 15, 17));
    BOOST_CHECK((v *= 9) == Vec3 (117, 135, 153));
    BOOST_CHECK(v == Vec3 (117, 135, 153));
}

BOOST_AUTO_TEST_CASE(dot_product) {
    BOOST_CHECK((Vec3 (1, 2, 3)).dot(Vec3 (4, -5, 6)) == 12);
}

BOOST_AUTO_TEST_CASE(cross_product) {
    BOOST_CHECK((Vec3 (3, -3, 1)).cross(Vec3 (4, 9, 2)) == Vec3 (-15, -2, 39));
}

BOOST_AUTO_TEST_CASE(magnitude) {
    BOOST_CHECK(abs((Vec3 (1, -2, 4)).mag() - 4.582) < .001);
}

BOOST_AUTO_TEST_CASE(normalize) {
    BOOST_CHECK((Vec3 (3, 1, 2)).norm() == Vec3 (0.802, 0.267, 0.534));
}

BOOST_AUTO_TEST_SUITE_END();
