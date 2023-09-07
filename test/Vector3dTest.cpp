#include "pch.h"
#include "Vector3d.h"

using namespace m3d;

TEST(Vector3d, Equals) {
    Vector3d a{ 5, 4, -7 };
    Vector3d b{ 5, 4, -7 };
    EXPECT_TRUE(a == b);
}

TEST(Vector3d, CopyConstructor) {
    Vector3d a{ 5, 4, -7 };
    Vector3d b(a);
    EXPECT_EQ(a, b);
}

TEST(Vector3d, AssignOperator) {
    Vector3d a{ 5, 4, -7 };
    Vector3d z;
    z = a;
    EXPECT_EQ(a, z);
}

TEST(Vector3d, StaticMemberVariables) {
    EXPECT_TRUE(Vector3d::zero == Vector3d(0, 0, 0));
    EXPECT_TRUE(Vector3d::unit_x == Vector3d(1, 0, 0));
    EXPECT_TRUE(Vector3d::unit_y == Vector3d(0, 1, 0));
    EXPECT_TRUE(Vector3d::unit_z == Vector3d(0, 0, 1));
}

TEST(Vector3d, AccessData) {
    Vector3d a;
    a.x() = 3;
    a.y() = 1;
    a.z() = 4;
    EXPECT_EQ(a, Vector3d(3, 1, 4));
}

TEST(Vector3d, NotEqual) {
    Vector3d a{ 3, 1, 4 };
    Vector3d b{ 3, 1, 4.000001 };
    EXPECT_NE(a, b);
}

TEST(Vector3d, Positive) {
    Vector3d a{ 5, 4, -1 };
    Vector3d b = +a;
    EXPECT_EQ(a, b);
}

TEST(Vector3d, Negative) {
    Vector3d a{ 5, 4, -7 };
    Vector3d b = -a;
    EXPECT_EQ(b, Vector3d(-5, -4, 7));
}

TEST(Vector3d, Add) {
    Vector3d a{ 3, 1, 4 };
    Vector3d b{ 1, 5, 9 };
    EXPECT_EQ(a + b, Vector3d(4, 6, 13));
}

TEST(Vector3d, Minus) {
    Vector3d a{ 3, 1, 4 };
    Vector3d b{ 1, 5, 9 };
    EXPECT_EQ(a - b, Vector3d(2, -4, -5));
}

TEST(Vector3d, Times) {
    Vector3d a{ 3, 1, 4 };
    Vector3d b{ 6, 2, 8 };
    EXPECT_EQ(2 * a, b);
    EXPECT_EQ(a * 2, b);
}

TEST(Vector3d, Divide) {
    Vector3d a{ 6, 2, 8 };
    Vector3d b{ 3, 1, 4 };
    EXPECT_EQ(a / 2, b);
}

TEST(Vector3d, SelfAdd) {
    Vector3d a{ 3, 1, 4 };
    Vector3d b{ 1, 5, 9 };
    a += b;
    EXPECT_EQ(a, Vector3d(4, 6, 13));
}

TEST(Vector3d, SelfMinus) {
    Vector3d a{ 3, 1, 4 };
    Vector3d b{ 1, 5, 9 };
    a -= b;
    EXPECT_EQ(a, Vector3d(2, -4, -5));
}

TEST(Vector3d, SelfTimes) {
    Vector3d a{ 3, 1, 4 };
    Vector3d b{ 6, 2, 8 };
    a *= 2;
    EXPECT_EQ(a, b);
}

TEST(Vector3d, SelfDivide) {
    Vector3d a{ 6, 2, 8 };
    Vector3d b{ 3, 1, 4 };
    a /= 2;
    EXPECT_EQ(a, b);
}

TEST(Vector3d, Length) {
    Vector3d a{ 3, 4, 5 };
    bool eq = m3d::utils::is_equal(a.length(), 7.07106781);
    EXPECT_TRUE(eq);
}

TEST(Vector3d, Normalize) {
    Vector3d a{ 3, 4, 5 };
    Vector3d b{
        3.0 / 7.07106781,
        4.0 / 7.07106781,
        5.0 / 7.07106781
    };
    EXPECT_EQ(a.normalize(), b);
}

TEST(Vector3d, Distance) {
    Vector3d a{ 3, 4, 0 };
    Vector3d b{ 6, 8, 0 };
    double dist = utils::distance(a, b);
    EXPECT_DOUBLE_EQ(dist, 5);
}

TEST(Vector3d, DotProduct) {
    Vector3d a{ 3, -2, 7 };
    Vector3d b{ 0, 4, -1 };
    EXPECT_DOUBLE_EQ(a.dot_product(b), -15);
}

TEST(Vector3d, CrossProduct) {
    Vector3d a{ 1, 3, 4 };
    Vector3d b{ 2, -5, 8 };
    Vector3d result{ 44, 0, -11 };
    EXPECT_EQ(a.cross_product(b), result);
}
