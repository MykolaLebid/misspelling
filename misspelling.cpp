#include "misspelling.h"
#include <unordered_map>

char Word::abundant_code_letter(const char ch) const {
	// create an empty unordered_map
	std::unordered_map< char,  char> char_map;
	// insert elements in map
	
	char_map.insert({ 'a', '0' }); char_map.insert({ 'e', '0' }); 
	char_map.insert({ 'i', '0' }); char_map.insert({ 'o', '0' });
	char_map.insert({ 'u', '0' }); char_map.insert({ 'y', '0' });
	
	char_map.insert({ 'b', '1' }); char_map.insert({ 'f', '1' });
 	char_map.insert({ 'p', '1' }); char_map.insert({ 'v', '1' });
	
	char_map.insert({ 'c', '2' }); char_map.insert({ 'g', '2' });
 	char_map.insert({ 'j', '2' }); char_map.insert({ 'k', '2' });
	char_map.insert({ 'q', '2' }); char_map.insert({ 's', '2' });
 	char_map.insert({ 'x', '2' }); char_map.insert({ 'z', '2' });
	
	char_map.insert({ 'd', '3' }); char_map.insert({ 't', '3' });
        
	char_map.insert({ 'l', '4' });
	
	char_map.insert({ 'm', '5' }); char_map.insert({ 'n', '5' });
	
	char_map.insert({ 'r', '6' });
	return char_map[ch];
};

std::string Word::drop_h_w(const std::string str) const {
        std::string abundant_code_str = "";
	for (char const &ch: str) 
		if ((ch!='h') && (ch!='w')) abundant_code_str += ch;
	return abundant_code_str;
};

std::string Word::abundant_code_string(const std::string str) const {
	std::string abundant_code_str="";
	for (char const &ch: str) 
		abundant_code_str += abundant_code_letter(ch);
	return abundant_code_str;
}

std::string Word::filtered_code_string(const std::string abundant_code_str) const {
	std::string filtered_code_string = "";
		for (auto it = abundant_code_str.cbegin(); it != abundant_code_str.end(); ++it)
			if (*(std::next(it)) != *it && *it != '0') filtered_code_string += *it;  	
	return filtered_code_string;
}

std::string Word::zero_pad_formatting(std::string filtered_code_str) const {
	const int tail_code_length = code_length - 1;
	const int zero_pad = tail_code_length - filtered_code_str.length();
	if (zero_pad > 0) return (filtered_code_str + std::string(zero_pad,'0'));
	return filtered_code_str.substr(0, tail_code_length);	
} 
std::string Word::code_tail(const std::string str) const {
	// cut out first character 
	std::string current_str = str.substr(1);
	
	// cut out h and w letters
	current_str = drop_h_w(current_str);
	
	std::string abundant_code_str = abundant_code_string(current_str);

	std::string filtered_code_str = filtered_code_string(abundant_code_str);

	return zero_pad_formatting(filtered_code_str);	
};


