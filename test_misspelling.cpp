#include "gtest/gtest.h"

#include "misspelling.h"

class MisspellingCaseFixture : public ::testing::Test {
	public:
		Word word;
};


TEST_F(MisspellingCaseFixture, KeepOneLetterWord) {
	ASSERT_EQ(word.code("A"), "A000");
}

TEST_F(MisspellingCaseFixture, ZeroWord) {
	ASSERT_EQ(word.code(""), "");
}

TEST_F(MisspellingCaseFixture, DifferentVowels) {
	ASSERT_EQ(word.code("Aaaa"), "A000");
}


TEST_F(MisspellingCaseFixture, OneTailConsonant) {
	ASSERT_EQ(word.code("Ab"), "A100");
}

TEST_F(MisspellingCaseFixture, TwoTailConsonants) {
	ASSERT_EQ(word.code("Abb"), "A110");
}

TEST_F(MisspellingCaseFixture, ThreeTailConsonants) {
	ASSERT_EQ(word.code("Abcd"), "A123");
}


