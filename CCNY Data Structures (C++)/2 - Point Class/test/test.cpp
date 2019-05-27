#include "hw2.h"
#include "gtest/gtest.h"

TEST(constructor, defaultConstructor) {
    Point test;
    EXPECT_EQ(0, test.getX());
    EXPECT_EQ(0, test.getY());
    EXPECT_EQ(0, test.getZ());
}

TEST(constructor, twoParam) {
    Point test(1,2);
    EXPECT_EQ(1, test.getX());
    EXPECT_EQ(2, test.getY());
    EXPECT_EQ(0, test.getZ());
}

TEST(constructor, threeParam) {
    Point test(1,2,3);
    EXPECT_EQ(1, test.getX());
    EXPECT_EQ(2, test.getY());
    EXPECT_EQ(3, test.getZ());
}

TEST(constructor, copy) {
    Point expect(1,2,3);
    Point test(expect);
    EXPECT_EQ(expect.getX(), test.getX());
    EXPECT_EQ(expect.getY(), test.getY());
    EXPECT_EQ(expect.getZ(), test.getZ());
}

TEST(set, oneParamX) {
    Point test;
    test.setX(1);
    EXPECT_EQ(1, test.getX());
    EXPECT_EQ(0, test.getY());
    EXPECT_EQ(0, test.getZ());
}

TEST(set, oneParamY) {
    Point test;
    test.setY(1);
    EXPECT_EQ(0, test.getX());
    EXPECT_EQ(1, test.getY());
    EXPECT_EQ(0, test.getZ());
}

TEST(set, oneParamZ) {
    Point test;
    test.setZ(1);
    EXPECT_EQ(0, test.getX());
    EXPECT_EQ(0, test.getY());
    EXPECT_EQ(1, test.getZ());
}

TEST(set, twoParam) {
    Point test;
    test.setXY(1,2);
    EXPECT_EQ(1, test.getX());
    EXPECT_EQ(2, test.getY());
    EXPECT_EQ(0, test.getZ());
}

TEST(set, threeParam) {
    Point test;
    test.setXYZ(1,2,3);
    EXPECT_EQ(1, test.getX());
    EXPECT_EQ(2, test.getY());
    EXPECT_EQ(3, test.getZ());
}

TEST(print, function1) {
    ::testing::internal::CaptureStdout();
    Point test;
    test.print();
    std::string output = ::testing::internal::GetCapturedStdout();

    EXPECT_STREQ("(0, 0, 0)\n", output.c_str());
}

TEST(print, function2) {
    ::testing::internal::CaptureStdout();
    Point test(1, 2, 3);
    test.print();
    std::string output = ::testing::internal::GetCapturedStdout();

    EXPECT_STREQ("(1, 2, 3)\n", output.c_str());
}

TEST(distance, origin) {
    Point test(1, 2, 3);
    EXPECT_EQ(sqrt(14), test.distance());
}

TEST(distance, twoPts) {
    Point test1(1, 2, 3);
    Point test2(-1, -2, -3);
    EXPECT_EQ(sqrt(56), test1.distance(test2));
}

TEST(origin, origin) {
    Point test;
    EXPECT_EQ(true, test.origin());
}

TEST(origin, notOrigin) {
    Point test(1,1,1);
    EXPECT_EQ(false, test.origin());
}

TEST(line, onLine1) {
    Point test1(1,1,1);
    Point test2;
    EXPECT_EQ(true, test1.line(test2));
}

TEST(line, onLine2) {
    Point test1(1,1,1);
    Point test2(2,2,2);
    EXPECT_EQ(true, test1.line(test2));
}

TEST(line, onLine3) {
    Point test1(1,1,1);
    Point test2(-2, -2, -2);
    EXPECT_EQ(true, test1.line(test2));
}

TEST(line, onLine4) {
    Point test1(0,1,1);
    Point test2(0,2,2);
    EXPECT_EQ(true, test1.line(test2));
}

TEST(line, onLine5) {
    Point test1(1,0,1);
    Point test2(2,0,2);
    EXPECT_EQ(true, test1.line(test2));
}

TEST(line, onLine6) {
    Point test1(1,1,0);
    Point test2(2,2,0);
    EXPECT_EQ(true, test1.line(test2));
}

TEST(line, notOnLine1) {
    Point test1;
    Point test2;
    EXPECT_EQ(false, test1.line(test2));
}

TEST(line, notOnLine2) {
    Point test1(1,1,1);
    Point test2(1,2,3);
    EXPECT_EQ(false, test1.line(test2));
}

TEST(line, notOnLine3) {
    Point test1(1,1,1);
    Point test2(-1, -2, -3);
    EXPECT_EQ(false, test1.line(test2));
}

TEST(line, notOnLine4) {
    Point test1(0,1,1);
    Point test2(1,1,1);
    EXPECT_EQ(false, test1.line(test2));
}

TEST(line, notOnLine5) {
    Point test1(1,0,1);
    Point test2(1,1,1);
    EXPECT_EQ(false, test1.line(test2));
}

TEST(line, notOnLine6) {
    Point test1(1,1,0);
    Point test2(1,1,1);
    EXPECT_EQ(false, test1.line(test2));
}

TEST(line, notOnLine7) {
    Point test1(1,1,1);
    Point test2(0,1,1);
    EXPECT_EQ(false, test1.line(test2));
}

TEST(line, notOnLine8) {
    Point test1(1,1,1);
    Point test2(1,0,1);
    EXPECT_EQ(false, test1.line(test2));
}

TEST(line, notOnLine9) {
    Point test1(1,1,1);
    Point test2(1,1,0);
    EXPECT_EQ(false, test1.line(test2));
}

TEST(cross, origin) {
    Point test1(0,0,0);
    Point test2(0,0,0);
    Point prod = test1.cross(test2);
    EXPECT_EQ(0, prod.getX());
    EXPECT_EQ(0, prod.getY());
    EXPECT_EQ(0, prod.getZ());
}

TEST(cross, ij) {
    Point test1(1,0,0);
    Point test2(0,1,0);
    Point prod = test1.cross(test2);
    EXPECT_EQ(0, prod.getX());
    EXPECT_EQ(0, prod.getY());
    EXPECT_EQ(1, prod.getZ());
}

TEST(cross, ik) {
    Point test1(1,0,0);
    Point test2(0,0,1);
    Point prod = test1.cross(test2);
    EXPECT_EQ(0, prod.getX());
    EXPECT_EQ(-1, prod.getY());
    EXPECT_EQ(0, prod.getZ());
}

TEST(cross, jk) {
    Point test1(0,1,0);
    Point test2(0,0,1);
    Point prod = test1.cross(test2);
    EXPECT_EQ(1, prod.getX());
    EXPECT_EQ(0, prod.getY());
    EXPECT_EQ(0, prod.getZ());
}

TEST(cross, one2six) {
    Point test1(1,2,3);
    Point test2(4,5,6);
    Point prod = test1.cross(test2);
    EXPECT_EQ(-3, prod.getX());
    EXPECT_EQ(6, prod.getY());
    EXPECT_EQ(-3, prod.getZ());
}

TEST(output, function1) {
    ::testing::internal::CaptureStdout();
    Point test;
    cout << test;
    std::string output = ::testing::internal::GetCapturedStdout();

    EXPECT_STREQ("(0, 0, 0)\n", output.c_str());
}

TEST(output, function2) {
    ::testing::internal::CaptureStdout();
    Point test(1, 2, 3);
    cout << test;
    std::string output = ::testing::internal::GetCapturedStdout();

    EXPECT_STREQ("(1, 2, 3)\n", output.c_str());
}

TEST(add, origin) {
    Point test1(0,0,0);
    Point test2(0,0,0);
    Point addend = test1 + test2;
    EXPECT_EQ(0, addend.getX());
    EXPECT_EQ(0, addend.getY());
    EXPECT_EQ(0, addend.getZ());
}

TEST(add, ij) {
    Point test1(1,0,0);
    Point test2(0,1,0);
    Point addend = test1 + test2;
    EXPECT_EQ(1, addend.getX());
    EXPECT_EQ(1, addend.getY());
    EXPECT_EQ(0, addend.getZ());
}

TEST(add, ik) {
    Point test1(1,0,0);
    Point test2(0,0,1);
    Point addend = test1 + test2;
    EXPECT_EQ(1, addend.getX());
    EXPECT_EQ(0, addend.getY());
    EXPECT_EQ(1, addend.getZ());
}

TEST(add, jk) {
    Point test1(0,1,0);
    Point test2(0,0,1);
    Point addend = test1 + test2;
    EXPECT_EQ(0, addend.getX());
    EXPECT_EQ(1, addend.getY());
    EXPECT_EQ(1, addend.getZ());
}

TEST(add, one2six) {
    Point test1(1,2,3);
    Point test2(4,5,6);
    Point addend = test1 + test2;
    EXPECT_EQ(5, addend.getX());
    EXPECT_EQ(7, addend.getY());
    EXPECT_EQ(9, addend.getZ());
}

TEST(subtract, origin) {
    Point test1(0,0,0);
    Point test2(0,0,0);
    Point diff = test1 - test2;
    EXPECT_EQ(0, diff.getX());
    EXPECT_EQ(0, diff.getY());
    EXPECT_EQ(0, diff.getZ());
}

TEST(subtract, ij) {
    Point test1(1,0,0);
    Point test2(0,1,0);
    Point diff = test1 - test2;
    EXPECT_EQ(1, diff.getX());
    EXPECT_EQ(-1, diff.getY());
    EXPECT_EQ(0, diff.getZ());
}

TEST(subtract, ik) {
    Point test1(1,0,0);
    Point test2(0,0,1);
    Point diff = test1 - test2;
    EXPECT_EQ(1, diff.getX());
    EXPECT_EQ(0, diff.getY());
    EXPECT_EQ(-1, diff.getZ());
}

TEST(subtract, jk) {
    Point test1(0,1,0);
    Point test2(0,0,1);
    Point diff = test1 - test2;
    EXPECT_EQ(0, diff.getX());
    EXPECT_EQ(1, diff.getY());
    EXPECT_EQ(-1, diff.getZ());
}

TEST(subtract, one2six) {
    Point test1(1,2,3);
    Point test2(4,5,6);
    Point diff = test1 - test2;
    EXPECT_EQ(-3, diff.getX());
    EXPECT_EQ(-3, diff.getY());
    EXPECT_EQ(-3, diff.getZ());
}

TEST(plane, onPlane1) {
    Point test1(0,0,0);
    Point test2(1,0,0);
    Point test3(0,1,0);
    Point planeAr[] = {test1, test2, test3};
    Point test4(1,1,0);
    EXPECT_EQ(true, plane(planeAr, test4));
}

TEST(plane, notOnPlane1) {
    Point test1(0,0,0);
    Point test2(1,0,0);
    Point test3(0,1,0);
    Point planeAr[] = {test1, test2, test3};
    Point test4(1,1,1);
    EXPECT_EQ(false, plane(planeAr, test4));
}

TEST(square, square1) {
    Point test1(0,0,0);
    Point test2(1,0,0);
    Point test3(0,1,0);
    Point test4(1,1,0);
    Point squareAr[] = {test1, test2, test3, test4};
    EXPECT_EQ(true, square(squareAr, 4));
}

TEST(square, square2) {
    Point test1(0,0,0);
    Point test2(1,0,0);
    Point test3(0,1,0);
    Point test4(0,0,1);
    Point test5(2,0,0);
    Point test6(0,2,0);
    Point test7(0,0,2);
    Point test8(1,1,0);
    Point squareAr[] = {test1, test2, test3, test4, test5, test6, test7, test8};
    EXPECT_EQ(true, square(squareAr, 8));
}

TEST(square, notSquare1) {
    Point test1(0,0,0);
    Point test2(1,0,0);
    Point test3(0,1,0);
    Point squareAr[] = {test1, test2, test3};
    EXPECT_EQ(false, square(squareAr, 3));
}

TEST(square, notSquare2) {
    Point test1(0,0,0);
    Point test2(1,0,0);
    Point test3(0,1,0);
    Point test4(0,0,1);
    Point test5(2,0,0);
    Point test6(0,2,0);
    Point test7(0,0,2);
    Point squareAr[] = {test1, test2, test3, test4, test5, test6, test7};
    EXPECT_EQ(false, square(squareAr, 7));
}

TEST(centroid, centroid1) {
    Point ptsAr[] = {};
    Point expect(0,0,0);
    Point test = centroid(ptsAr, 0);
    EXPECT_EQ(expect.getX(), test.getX());
    EXPECT_EQ(expect.getY(), test.getY());
    EXPECT_EQ(expect.getZ(), test.getZ());
}

TEST(centroid, centroid2) {
    Point ptsAr[] = {};
    Point expect(0,0,0);
    Point test = centroid(ptsAr, 0);
    EXPECT_EQ(expect.getX(), test.getX());
    EXPECT_EQ(expect.getY(), test.getY());
    EXPECT_EQ(expect.getZ(), test.getZ());
}

TEST(centroid, centroid3) {
    Point test1(0,0,0);
    Point test2(1,0,0);
    Point test3(0,1,0);
    Point test4(0,0,1);
    Point test5(-1,0,0);
    Point test6(0,-1,0);
    Point test7(0,0,-1);
    Point ptsAr[] = {test1, test2, test3, test4, test5, test6, test7};
    Point expect(0,0,0);
    Point test = centroid(ptsAr, 7);
    EXPECT_EQ(expect.getX(), test.getX());
    EXPECT_EQ(expect.getY(), test.getY());
    EXPECT_EQ(expect.getZ(), test.getZ());
}

TEST(centroid, centroid4) {
    Point test1(0,0,0);
    Point test2(1,0,0);
    Point test3(0,1,0);
    Point test4(0,0,1);
    Point test5(2,0,0);
    Point test6(0,2,0);
    Point test7(0,0,2);
    Point test8(3,0,0);
    Point test9(0,3,0);
    Point test0(0,0,3);
    Point ptsAr[] = {test1, test2, test3, test4, test5, test6, test7, test8, test9, test0};
    Point expect(0.6,0.6,0.6);
    Point test = centroid(ptsAr, 10);
    EXPECT_EQ(expect.getX(), test.getX());
    EXPECT_EQ(expect.getY(), test.getY());
    EXPECT_EQ(expect.getZ(), test.getZ());
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}