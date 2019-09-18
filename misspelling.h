#ifndef MISSELLING
#define MISSELLING
#include <string>
class Word 
{
private:
	const unsigned int code_length = 4;

	std::string code_head(const std::string str) const {return str.substr(0, 1);};
	
	std::string code_tail(const std::string str) const;
	std::string drop_h_w(const std::string str) const;
	
	char abundant_code_letter(const char ch) const;
	std::string abundant_code_string(const std::string str) const;	
	std::string filtered_code_string(const std::string abundant_code_str) const;
	std::string zero_pad_formatting(std::string filtered_code_str) const; 
public:	
	std::string code(const std::string str) const {
		if (str!="") {
			return code_head(str)  +  code_tail(str);
		} else {
			return "";
		};
	}
};

#endif
