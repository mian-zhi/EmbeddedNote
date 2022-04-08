#include<iostream>
using namespace std;

class String {
    char* data; // C code
    int n;      // Length of the string
public:
    //constructor
    String(const char* s = 0) {
        if (s == 0) {
            data = 0; n = 0; return;
        }
        const char* p = s;
        //while(*p != '\0') p++;
        while (*p) p++;
        n = p - s;  //Length
        data = new char[n + 1];
        for (int i = 0; i < n; i++)
            data[i] = s[i];
        data[n] = '\0';
    }

    int size() { return n; }

    char operator[](int i)const {
        if (i < 0 || i >= n) throw "下标非法";
        return data[i];
    }
#if 1
    char& operator[](int i) {
        if (i < 0 || i >= n) throw "下标非法";
        return data[i];
    }
#endif
};

ostream& operator<<(ostream& o, String s) {
    for (int i = 0; i < s.size(); i++)
        cout << s[i];
    return o;
}

int main()
{
    String str, str2("Hello world");
    str2[0] = 'E';
    cout << str2 << endl;
    String str3 = str2;
    cout << str3 << endl;
    int a = 0;
}