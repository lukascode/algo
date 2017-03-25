#include <iostream>
#include <vector>
#include <deque>
#include <cstdint>
#include <stdexcept>

using namespace std;

class Number {
public:
    Number() {
        sign = 1;
        digits->push_back(0);
    }

    ~Number() {
        if(digits != NULL) 
            delete digits;
    }

    Number(int number) {
        digits = getDigits(number);
    }

    Number(std::string number) {
        if(!is_number(number))
            throw std::invalid_argument("error. received not a number value");
        digits = getDigits(number);
    }

    std::string toString() {
        std::string str = "";
        if(sign < 0) str += "-";
        for(size_t i=0; i<digits->size(); ++i) {
            str += (char)((*digits)[i] + '0');
        }  return str;
    }

private:
    deque<uint8_t>* digits;
    int sign;

    deque<uint8_t>* getDigits(int number) {
        deque<uint8_t>* digits = new deque<uint8_t>();
        do {
            uint8_t digit = number % 10;
            number /= 10;
            digits->push_front(digit);
        } while(number != 0);
        return digits;
    }

    deque<uint8_t>* getDigits(std::string number) {
        deque<uint8_t>* digits = new deque<uint8_t>();
        for(int i=0; i<number.length(); ++i) {
            digits->push_back(number[i] - '0');
        } return digits;
    }

    bool is_number(const std::string& s) {
        std::string::const_iterator it = s.begin();
        while(it != s.end() && std::isdigit(*it)) ++it;
        return !s.empty() && it == s.end();
    }
};

int main(void) {



    return 0;
} 