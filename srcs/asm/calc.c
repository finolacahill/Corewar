#include "../../includes/op.h"
#include <fcntl.h>
#include "../../libft/libft.h"
#include <stdio.h>
#include "../../includes/corewar.h"

int     bi_to_dec(char *bi)
{
    int i;
    int len;
    int res;

    res = 0;
    i = 0;
    while (bi[i] && bi[i] == '0')
        i++;
    len = ft_strlen(&bi[i]) - 1;
    while (len >= 0)
    {
        if (bi[i] == '1')
            res = res + ft_power(2, len);
        i++;
        len--;
    }
    return (res);
}
