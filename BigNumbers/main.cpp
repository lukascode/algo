#include <iostream>
#include <vector>
#include <deque>
#include <cstdint>
#include <stdexcept>
#include <cassert>

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
        // int last_this = this->digits->size()-1;
        // int last_arg = number.digits->size()-1;

    }

    void operator+=(int value) {

    }

    bool operator<(const Number& number) {
        if(digits->size() < number.digits->size())
            return true;
        if(digits->size() > number.digits->size())
            return false;
        for(int i=0; i<digits->size(); ++i) {
            int a = (*digits)[i], b = (*number.digits)[i];
            if(a != b) {
                if(a < b) return true;
                else if(a > b) return false;
            }
        } return false;
    }
    bool operator<=(const Number& number) {
        if( this->operator<(number) || this->operator==(number))
            return true;
        return false;
    }
    bool operator>(const Number& number) {
        if( !this->operator<(number) && !this->operator==(number))
            return true;
        return false;
    }
     bool operator>=(const Number& number) {
        if(!this->operator<(number))
            return true;
        return false;
    }
    bool operator==(const Number& number) {
        bool result = true;
        if(sign == number.sign) {
            if(digits->size() == number.digits->size()) {
                for(int i=0; i<digits->size(); ++i) {
                    if( (*digits)[i] != (*number.digits)[i])
                        { result = false; break; }
                }
            } else result = false;
        } else result = false;
        return result;
    }

    std::string toString() {
        std::string str = "";
        if(sign < 0) str += "-";
        for(size_t i=0; i<digits->size(); ++i) {
            char c = (char)((*digits)[i] + '0');
            str += c;
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
            assert(number[i] >= 48 && number[i] <= 57);
            digits->push_back(number[i] - '0');
        } return digits;
    }

    bool is_number(const std::string& s) {
        std::string::const_iterator it = s.begin();
        while(it != s.end() && std::isdigit(*it)) ++it;
        return !s.empty() && it == s.end();
    }

    static std::deque<uint8_t>* addNumbers(const std::deque<uint8_t>& a, const std::deque<uint8_t>& b) {
        if(a.size() < b.size()) return addNumbers(b, a);
        std::deque<uint8_t>* result = new std::deque<uint8_t>();
        int asize = a.size(), bsize = b.size();
        int carr = 0;
        for(int i=asize-1, j=bsize-1; i>=0; --i,--j) {
            int pos_sum = (j >= 0)?a[i]+b[j]+carr:a[i]+carr;
                result->push_front(pos_sum%10);
                carr = (pos_sum>10)?1:0;
        }
        if(carr != 0)
            result->push_front(1);
        return result;
    }

    static std::deque<uint8_t>* subtractNumbers(const std::deque<uint8_t>& a, const std::deque<uint8_t>& b) {
        if(a.size() < b.size()) return addNumbers(b, a);
        std::deque<uint8_t>* result = new std::deque<uint8_t>();
        int asize = a.size(), bsize = b.size();
        int carr = 0;
        for(int i=asize-1, j=bsize-1; i>=0; --i,--j) {
            int pos_sum, anewdigit = a[i] - carr;
            if(j >= 0) {
                carr = (anewdigit < b[j])?1:0;
                result->push_front( (carr*10+anewdigit) - b[j] );
            } else {
                carr = (anewdigit < 0)?1:0;
                result->push_front(carr*10+anewdigit);
            }
        }
        /* remove zeros at the beginning of the sequence */
        while(!result->empty() && result->front() == 0) result->pop_front();
        return result;
    }
};




int main(void) {



    return 0;
} 