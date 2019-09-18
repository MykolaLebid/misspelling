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

	char abundant_code_letter(const char ch) const;

	std::string code_tail(const std::string str) const;

	std::string code(const std::string str) const {
		if (str!="") {
			return first_letter(str)  +  code_tail(str);
		} else {
			return "";
		};
	}
};

#endif
