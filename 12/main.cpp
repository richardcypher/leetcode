#include <iostream>
#include <string>
using namespace std;

string intToRoman(int num) {
    string result = "";
    string base_str1 = "", base_str2 = "", base_str3 = "";
    int base = 1;
    while( num != 0) {
        switch(base) {
                case 1:
                    base_str1 = "I";
                    base_str2 = "V";
                    base_str3 = "X";
                    break;
                case 10:
                    base_str1 = "X";
                    base_str2 = "L";
                    base_str3 = "C";
                    break;
                case 100:
                    base_str1 = "C";
                    base_str2 = "D";
                    base_str3 = "M";
                    break;
                case 1000:
                    base_str1 = "M";
                    break;
        }
        int unit_num = num % 10;
        string unit_str = "";
        if(unit_num < 4 && unit_num >= 0) {
            for(int i = 0; i < unit_num; i ++) 
            {
                unit_str += base_str1;
            }
        }
        else if(unit_num  >= 4 && unit_num <= 8) {
            unit_str = base_str2;
            if(unit_num == 4)
                unit_str = base_str1 + unit_str;
            else {
                for (int i = 0; i < (unit_num - 5); ++i)
                {
                    unit_str += base_str1;
                }
            }
        }
        else if(unit_num == 9) {
            unit_str = base_str1 + base_str3;
        }
        result = unit_str + result;
        num /= 10;
        base *= 10;
    }
    return result;
}

int main() {
    cout<<intToRoman(3333)<<endl;
    return 0;
}