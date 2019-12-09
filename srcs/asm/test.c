#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int     ft_strtol(char *str, int base, int size)
{
    int res;
    int i;
    int c;

    i = 0;
    c = 0;
    res = 0;
    while (str[i] && i < size)
    {
        if (str[i] == 'f')
          c = str[i] - ('a' - 10);
        else if (str[i] == '1')
            c = str[i] - '0';
        res = res * base;
        res = res + c;
        i++;
    }
    printf("res == %d\n", res);
    return (res);
}

int main()
{
    int fd;

    fd = open("toto.s", O_WRONLY);
    /*//char c[2] = "65";
    char c[3];
    //int i = 0x + 0b;
   // char hexa = 0x;
    char hexa = 0x00;
    char *test= "b";
    c[0] = hexa + (int)test;
    c[1] = 1;
     //c[1] = 0x0b;
    //7801000a000106;
    write(fd, &c, 2);*/
    char c = 'f';
    int hexa = 0x00;
    int i = c - ('a' - 10);
    printf("strtol == %lx\n",strtol("f1", NULL, 16));
    c = (char)strtol("ff", NULL, 16);
    char mine;
    mine = (char)ft_strtol("f1", 16);
    write(fd, &mine, 1);
    printf("i == %d\n", i);
    return (1);
}