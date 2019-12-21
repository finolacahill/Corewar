#include "../includes/vm.h"

int			get_duration(t_all *vm, int opc)
{
	if (opc == 1 || opc == 4 || opc == 5 || opc == 13)
		return (vm->cycles + 10);
	if (opc == 2 || opc == 3)
		return (vm->cycles + 5);
	if (opc == 6 || opc == 7 || opc == 8)
		return (vm->cycles + 6);
	if (opc == 9)
		return (vm->cycles + 20);
	if (opc == 10 || opc == 11)
		return (vm->cycles + 25);
	if (opc == 12)
		return (vm->cycles + 800);
	if (opc == 14)
		return (vm->cycles + 50);
	if (opc == 15)	
		return (vm->cycles + 1000);
	if (opc == 16)	
		return (vm->cycles + 2);
	return (1);
}

static void	init_registers(t_process *p)
{
	int i;

	i = 0;
	p->r[0] = p->id;
	while (++i < REG_NUMBER)
		p->r[i] = 0;
}

t_process	*init_process(t_all *vm, t_champs *c, t_process *p)
{	
	if (!(p = ft_memalloc(sizeof(t_process))))
		return (error_process(p));
	if (!(p->decode = malloc((sizeof(int)) * 4)))
		return (error_process(p));
	p->id = c->id;
	p->carry = 0;
	init_registers(p);
	p->live_calls = -1;
	p->start = c->start;
	p->op = c->exec_code[0];
	p->pc = p->start;
	p->next = NULL;
	p->exec_cycle = get_duration(vm, p->op);
	p->bytes = 0;
	c->last_live = 0;
	p->op_fail = 0;
	p->all_dead = 0;
	if ((if_no_opcode(p)) == 1)
		p->opc = 0;
	else
		p->opc = c->exec_code[1];
	p = ft_decode_byte(p->opc, p);
	return (p);
}

int init_arena(t_all *vm)
{
    int     i;
    int     divide;

    i = 0;
    divide = 0;
    vm->cycles = 0;
    vm->last_alive = 0;
    vm->last_alive_cycle = 0;
    vm->nbr_live_since_check = 0;
    vm->total_checks = 0;
    vm->total_process = vm->total_champ;
    if (!(vm->arena = ft_memalloc((sizeof(unsigned char)) * MEM_SIZE)))
        return (-1);
    while (i < vm->total_champ)
    {
        vm->champs[i].start = divide;
        ft_memcpy(&vm->arena[divide], vm->champs[i].exec_code, vm->champs[i].len_exec_code);
        ++i;
        divide = divide + MEM_SIZE / vm->total_champ;
    }
 // ft_print_arena(vm);
   return (0);
}