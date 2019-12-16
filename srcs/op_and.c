/*
** Does an AND bitwise operation between 1st and 2nd param
** both came be (rg/ind/d4). Stores in third val (reg)
Modifies the carry.
*/

#include "../includes/vm.h"

void    op_and(t_all *vm, t_process *p)
{
    int pm1;
    int pm2;
    int bytes_read;

    bytes_read = 1;
    pm1 = get_unspecified_val(vm, p, &bytes_read, 0);
    pm2 = get_unspecified_val(vm, p, &bytes_read, 1);
    if (p->op_fail == 1)
        return ;
    load_val_in_reg(vm, p, pm1 & pm2, bytes_read);
    if (p->op_fail != 1)
        check_carry(p, pm1 & pm2);    
}
