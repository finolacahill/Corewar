#include "../../includes/vm.h"

uint16_t		check_op_live(t_all *all, uint8_t *content)
{	
	int		i;

	(void)content;
	i = 0;
	return (op_check_tab[0].dir_size + 1);
}



int		is_player_nb(int id, t_all *vm)
{
	int i;
	i = -1;
	while (++i < vm->total_champ)
	{
		if (vm->champs[i].id == id)	//THIS MUST BE CHANGED, IS JUST FOR TESTING
			return (1);
	}
	return (0);
	
}

void	op_live(t_all *vm, t_process *p)
{
	int p1;
	
	p1 = get_next_bytes(vm, p, 4, 0);
//	ft_printf("THE NUMBER IS %d\n", p1);
//	ft_print_arena(vm, 64, p->pc);
	if (is_player_nb(p1, vm) == 1)
	{
		vm->champs[p1 - 1].last_live = vm->cycles;
		p->live_calls = vm->cycles;
//		ft_printf("A process shows that player number %d, %s, is alive.\n", p1, vm->champs[p1 - 1].name);
		if (vm->last_alive_cycle <= vm->cycles)
		{
			vm->last_alive = p1;
			vm->last_alive_cycle = vm->cycles;
		}
		++vm->nbr_live_since_check;
	}
}