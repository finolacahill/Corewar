#include "../../includes/op.h"
#include <fcntl.h>
#include "../../libft/libft.h"
#include <stdio.h>
#include "../../includes/corewar.h"

int     get_ocp(t_instruc *instruc)
{
    char *ocp;
    int i;
    int j;
    int res;

    j = -1;
    ocp = ft_strnew(8);
    i = 0;
    while (instruc->params[i] != 0)
    {
        if (instruc->params[i] == T_REG)
        {
            ocp[++j] = '0';
            ocp[++j] = '1';
        }
        else if (instruc->params[i] == T_DIR)
        {
            ocp[++j] = '1';
            ocp[++j] = '0';
        }
        else if (instruc->params[i] == T_IND)
        {
            ocp[++j] = '1';
            ocp[++j] = '1';
        }
        i++;
    }
    while (j < 7)
        ocp[++j] = '0';
        ft_printf("ocp == %s\n", ocp);
    res = bi_to_dec(ocp);
    ft_strdel(&ocp);
    ocp = ft_uitoa_base(res, 16, 0);
    if (ft_strlen(ocp) == 1)
        ocp = ft_strjoin_fr("0", ocp, 2);
    instruc->hexa_instruc = ft_strjoin_fr(ocp, instruc->hexa_instruc, 3);
    return (1);
}