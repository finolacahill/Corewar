#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../../includes/op.h"
#include <fcntl.h>
#include "../../libft/libft.h"
#include <stdio.h>
#include "../../includes/corewar.h"
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

int main(int ac, char **av)
{
    
}
