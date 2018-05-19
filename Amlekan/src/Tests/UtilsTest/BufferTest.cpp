#include "../BaseTest/BaseTest.h"

#include "Buffer.h"

class BufferTest : public BaseTest { };

TEST_F(BufferTest, CtorNotThrow) {
	Buffer buff;
	EXPECT_EQ(0, buff.size());
}

TEST_F(BufferTest, StringLength) {
	std::string str("hello");
	Buffer buff(str);
	EXPECT_EQ(5, buff.size());
}


