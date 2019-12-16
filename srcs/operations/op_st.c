#include "../../includes/vm.h"

uint16_t		check_op_st(t_all *all, uint8_t *content)
{
	int			i;

	(void)content;
	i = 0;
	if (!(content[1]) || is_in(content[1], op_check_tab[2].ocp_value) != 1)
		return (0);
	i += content[1] == 80 ? 2 * 1 : 0;
	i += content[1] == 112 ? 1 + IND_SIZE : 0;
	i += 2;
	return (i);
}



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
        param2 = get_next_bytes(vm, p, 2, 2) % MEM_SIZE;//should idx_mod here?
     //   printf("param2 without idx mod= %d\n", get_next_bytes(vm, p, 2, 2));
     //   printf("param2 with mem siz (%d) mod= %d\n", MEM_SIZE,  get_next_bytes(vm, p, 2, 2) % MEM_SIZE);
      //  printf("param2 = %d\n", param2);
        load_value(vm, param2, 4, param1); //have added an id_x mod to load_value
      //  ft_printf("\treg = %d loaded at pc %d + %d\n", param1, p->pc, param2);
      //  ft_printf("\tin hez, %02X\n", p->pc + param2);
    }
    check_carry(p, param1);
 //   int test = get_next_bytes(vm, p, 4, param2 - 1);
 //   printf("is %d == %d\n", param1, test);  
}