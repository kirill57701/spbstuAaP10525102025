#include <iostream>
#include <cstddef>
#include <limits>

int ismorepower(size_t a){
    int s = std::numeric_limits<size_t>::max();
    if (s/a >= a){return 1;}
    return 0;
}

int ismoresum(size_t a, size_t b){
    int s = std::numeric_limits<size_t>::max();
    if (s - a >= b){return 1;}
    return 0;
}

int ispyth(size_t a, size_t b, size_t c){
    if (a > 0 && b > 0 && c > 0){
    if (ismorepower(a) == 1 && ismorepower(b) == 1 && ismorepower(c) == 1){
        if (ismoresum(a*a, b*b) == 1 && ismoresum(b*b, c*c) == 1 && ismoresum(a*a, c*c) == 1){
            if ((a*a + b*b == c*c) || (a*a + c*c == b*b) || (b*b + c*c == a*a)){
                return 1;
            }
            return 0;
        }
        else{
            throw std::overflow_error("overflow, error");
        }
    }
    else{
        throw std::overflow_error("overflow, error");
    }}
    else{
        return 0;
    }
}

int main(){
    size_t a = 0, b = 0, c = 0;
    bool isokay = true;
    size_t count = 0;
    while (std::cin >> a){
        try{
            count += ispyth(a, b, c);}
        catch (...){
            std::cerr << "overflow, error";
            return 2;
        }
        c = b;
        b = a;
    }
    if (std::cin.eof()){
        std::cout << count << "\n";
    }
    else if(std::cin.fail()){
        std::cerr << "error\n";
        return 1;
    }
}
