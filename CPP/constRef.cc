
int main() {
    int a = 1;
    const int b = 2;

    int &c = a;
    const int &d = a;
    // d = 2;
    // a = 2;


    // int &e = b;
    const int &f = b;
    // f = 2;
    // b = 2;
}