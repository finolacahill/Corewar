#include "../includes/vm.h"

/*
** First param is a reg, second is either a reg or a IND.
** Puts values of the reg into the second param.
** if value of reg == 0, carry is 1, else carry is 0
*/

void    op_st(t_all *vm, t_process *p)
{
    int     param1;
    int     param2;

    if ((param1 = get_reg_val(vm, p, 1)) == -1)
        return ;   
    if  (p->decode[1] == REG_SIZE)
    {
        if ((param2 = get_reg_val(vm, p, 2)) == -1)
            return ;
    }
    else
    {
       param2 = get_ind(vm, p, 2);
    }
    printf("\treg = %d loaded at pc %d + %d\n", param1, p->pc, param2); 
    load_value(vm, ((p->pc + param2) % MEM_SIZE), 4, param1);
 //   int test = get_next_bytes(vm, p, 4, param2 - 1);
 //   printf("is %d == %d\n", param1, test);
    
}