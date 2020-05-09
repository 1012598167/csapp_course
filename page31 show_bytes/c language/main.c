#include <stdio.h>
typedef unsigned char* byte_pointer;
void show_bytes(byte_pointer start,size_t len)
{
    size_t i;
    for (i=0;i<len;i++)
    {
        printf("%.2x",start[i]);
        printf("\n");
    }

    printf("\n");
}
void show_int(int x)
{
    show_bytes((byte_pointer)&x, sizeof(int));
}
int main()
{

    printf("%.2x",0x3);
    return 0;
}