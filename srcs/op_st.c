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

    if ((param1 = get_reg_val(vm, p, 1)) == -1 && p->op_fail == 1)
        return ;
    if  (p->decode[1] == REG_SIZE)
    {
        load_val_in_reg(vm, p, param1, 2);
        if (p->op_fail == 1)
            return ;
    }
    else
    {

    printf("p1 = %d\n", param1);
      param2 = get_ind(vm, p, 2);
      printf("param2 = %d\n", param2);
      printf("pc = %d\n", p->pc);
      printf("pc = %02x\n", vm->arena[p->pc]);
      load_value(vm, p->pc + param2, 4, param1);
    }
    check_carry(p, param1);
 //   int test = get_next_bytes(vm, p, 4, param2 - 1);
 //   printf("is %d == %d\n", param1, test);  
}