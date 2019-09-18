//#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <unordered_map> // for func abundant_code_letter(..)
class Word 
{
public:
	const unsigned int code_length = 4;

	std::string first_letter(const std::string str) const {
		return str.substr(0, 1);
	};

	char abundant_code_letter(const char ch) const {
		// create an empty unordered_map
		std::unordered_map< char,  char> char_map;
		// insert elements in map
		
		char_map.insert({ 'a', '0' });
		char_map.insert({ 'e', '0' });
	 	char_map.insert({ 'i', '0' });
		char_map.insert({ 'o', '0' });
		char_map.insert({ 'u', '0' });
		char_map.insert({ 'y', '0' });
		char_map.insert({ 'b', '1' });
		char_map.insert({ 'f', '1' });
	 	char_map.insert({ 'p', '1' });
		char_map.insert({ 'v', '1' });
		char_map.insert({ 'c', '2' });
		char_map.insert({ 'g', '2' });
	 	char_map.insert({ 'j', '2' });
		char_map.insert({ 'k', '2' });
		char_map.insert({ 'q', '2' });
		char_map.insert({ 's', '2' });
	 	char_map.insert({ 'x', '2' });
		char_map.insert({ 'z', '2' });
		char_map.insert({ 'd', '3' });
		char_map.insert({ 't', '3' });
	        char_map.insert({ 'l', '4' });
		char_map.insert({ 'm', '5' });
	 	char_map.insert({ 'n', '5' });
		char_map.insert({ 'r', '6' });
	 	char_map.insert({ 'h', '7' });
		char_map.insert({ 'w', '7' });
		return char_map[ch];
				
//// Iterate Over the unordered_map and display elements
		//for (std::pair<std::string, int> element : wordMap)
		//	std::cout << element.first << " :: " << element.second << std::endl;
	 	//
	}; 
	std::string code_tail(const std::string str) const {
	//	const unsigned int word_length = str.length();
                std::string unfiltered_code_string = "";
		for (char const &ch: str.substr(1)) 
			unfiltered_code_string += abundant_code_letter(ch);
	        	
                std::string filtered_code_string = "";
		 for (char const &ch: unfiltered_code_string) 
			filtered_code_string += abundant_code_letter(ch);
		
		const int zero_pad = code_length - unfiltered_code_string.length() - 1;
		if (zero_pad > 0) return (unfiltered_code_string + std::string(zero_pad,'0'));
		return unfiltered_code_string;	
		//	if (code_length > word_length))
	//	const unsigned int zero_pad = 4 - ;		
	};

	std::string code(const std::string str) const {
		if (str!="") {
			return first_letter(str)  +  code_tail(str);
		} else {
			return "";
		};
	}
};

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


