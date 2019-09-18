//#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <unordered_map> // for func abundant_code_letter(..)
#include "misspelling.h"

//class MisspellingCase : 
TEST(MisspellingCase, KeepOneLetterWord) {
	Word word;		
	auto code = word.code("A");
	ASSERT_EQ(code, "A000");
}




TEST(MisspellingCase, ZeroWord) {
	Word word;		
	auto code = word.code("");
	ASSERT_EQ(code, "");
}

TEST(MisspellingCase, DifferentVowels) {
	Word word;		
	auto code = word.code("Aaaa");
	ASSERT_EQ(code, "A000");
}


TEST(MisspellingCase, OneTailConsonant) {
	Word word;		
	auto code = word.code("Ab");
	ASSERT_EQ(code, "A100");
}

TEST(MisspellingCase, TwoTailConsonants) {
	Word word;		
	auto code = word.code("Abb");
	ASSERT_EQ(code, "A110");
}

TEST(MisspellingCase, ThreeTailConsonants) {
	Word word;		
	auto code = word.code("Abcd");
	ASSERT_EQ(code, "A123");
}


