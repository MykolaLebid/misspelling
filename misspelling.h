#ifndef MISSELLING
#define MISSELLING
#include <string>
class Word 
{
public:
	const unsigned int code_length = 4;

	std::string first_letter(const std::string str) const {
		return str.substr(0, 1);
	};
	std::string drop_h_w(const std::string str) const;
	char abundant_code_letter(const char ch) const;
	
	std::string abundant_code_string(const std::string str) const;
	std::string filtered_code_string(const std::string abundant_code_str) const;
	std::string code_tail(const std::string str) const;
	
	std::string zero_pad_formatting(std::string filtered_code_str) const; 
	std::string code(const std::string str) const {
		if (str!="") {
			return first_letter(str)  +  code_tail(str);
		} else {
			return "";
		};
	}
};

#endif
