#include <iostream>
#include <vector>
#include <deque>
#include <cstdint>
#include <stdexcept>

class Number {
public:
    Number() {
        sign = 1;
        digits = new std::deque<uint8_t>();
        digits->push_back(0);
    }

    ~Number() {
        if(digits != NULL) 
            delete digits;
    }

    Number(int number) {
        if(number < 0) { 
            sign = -sign;
            number = -number;
        } digits = getDigits(number);
    }

    Number(std::string number) {
        if(number[0] == '-') {
            sign = -sign;
            number.erase(0, 1);
        } else if(number[0] == '+') {
            number.erase(0, 1);
        }
        if(!is_number(number))
            throw std::invalid_argument
            ("error. received not a number value");
        if(number.length() == 0) 
            digits = new std::deque<uint8_t>();
        else digits = getDigits(number);
    }

    Number(const Number& number) : sign(number.sign) {
        digits = new std::deque<uint8_t>();
        for(size_t i=0; i<number.digits->size(); ++i) {
            digits->push_back((*number.digits)[i]);
        }
    }

    Number& operator+(const Number& number) {

    }

    Number& operator+(int value) {

    }

    void operator+=(const Number& number) {
        int last_this = this->digits->size()-1;
        int last_arg = number.digits->size()-1;

    }

    void operator+=(int value) {

    }

    std::string toString() {
        std::string str = "";
        if(sign < 0) str += "-";
        for(size_t i=0; i<digits->size(); ++i) {
            str += (char)((*digits)[i] + '0');
        }  return str;
    }

private:
    std::deque<uint8_t>* digits;
    int sign;

    std::deque<uint8_t>* getDigits(int number) {
        std::deque<uint8_t>* digits = new std::deque<uint8_t>();
        do {
            uint8_t digit = number % 10;
            number /= 10;
            digits->push_front(digit);
        } while(number != 0);
        return digits;
    }

    std::deque<uint8_t>* getDigits(std::string number) {
        std::deque<uint8_t>* digits = new std::deque<uint8_t>();
        for(int i=0; i<number.length(); ++i) {
            digits->push_back(number[i] - '0');
        } return digits;
    }

    bool is_number(const std::string& s) {
        std::string::const_iterator it = s.begin();
        while(it != s.end() && std::isdigit(*it)) ++it;
        return !s.empty() && it == s.end();
    }

    static std::deque<uint8_t>* addNumbers(const std::deque<uint8_t>& a, const std::deque<uint8_t>& b) {
        std::deque<uint8_t>* result = new std::deque<uint8_t>();
        //for(int i=a.size()-1,j=b.size()-1; ())
        return NULL;
    }
};




int main(void) {



    return 0;
} 