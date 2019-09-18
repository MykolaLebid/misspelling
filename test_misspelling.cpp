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
	ASSERT_EQ(word.code("Abb"), "A100");
}

TEST_F(MisspellingCaseFixture, ThreeTailConsonants) {
	ASSERT_EQ(word.code("Abcd"), "A123");
}

TEST_F(MisspellingCaseFixture, ThreeTailConsonantsWithHandW){
	ASSERT_EQ(word.code("Abhd"), "A130");
}

TEST_F(MisspellingCaseFixture, ThreeTailConsonantsWithDoubleDigits){
	ASSERT_EQ(word.code("Abfd"), "A130");		
}

TEST_F(MisspellingCaseFixture, FourDigits){
	ASSERT_EQ(word.code("Abfdmr"), "A135");		
}

