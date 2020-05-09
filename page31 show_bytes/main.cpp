#include <iostream>
using namespace std;
typedef unsigned char* byte_pointer;
void show_bytes(byte_pointer start,size_t len)
{
/*    size_t i;
    for (i=0;i<len;i++)
        cout<<*/
}
int main()
{
    int c=16384;
    cout<<(byte_pointer)&c<<endl;
    return 0;
}