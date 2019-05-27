#include "hw0.h"
#include "gtest/gtest.h"

TEST(HelloWorld, HelloWorld) {
    ::testing::internal::CaptureStdout();
	helloWorld();
	std::string output = ::testing::internal::GetCapturedStdout();

	EXPECT_STREQ("Hello World\n", output.c_str());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}