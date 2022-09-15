#include <iostream>
using namespace std;

void print(int num) {
    for (int i = 31; i >= 0; --i) {
        cout << ((num & (1 << i)) == 0 ? "0" : "1");
    }
    cout << endl;
}


int main() {
    int num = 2;                    //00000000000000000000000000000010, 32位
    print(num);

    int int_max = (1<<31)-1, int_min = (1<<31);
    cout << "INT最大值: ";          //01111111111111111111111111111111
    print(int_max);

    cout << "INT最小值: ";          //10000000000000000000000000000000
    print(int_min);

    //最高位为符号位，剩余位取反加一即为最终值
    print(-1);
    print(-2);
}