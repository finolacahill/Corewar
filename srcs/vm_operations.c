#include "../includes/vm.h"

void    check_carry(t_process *p, int param)
{
	if (p != NULL ) //kill flag?
	{
		if (param == 0)
			p->carry = 1;
		else
			p->carry = 0;
	}
	ft_printf("\tcarry is now %d\n", p->carry);
}

static void	check_cycle_decrease(t_all *vm)
{
	if (vm->nbr_live_since_check >= NBR_LIVE
		|| vm->total_checks >= MAX_CHECKS)
	{
		vm->cycles_to_die -= CYCLE_DELTA;
		vm->total_checks = 0;
	}
	else
	{
		++vm->total_checks;
	}
	vm->nbr_live_since_check = 0; 
}

void		kill_process(t_process *p, int id)
{
	t_process *tracker;
	t_process *prev;

	tracker = p;
	prev = NULL;
	while (tracker != NULL)
	{
		if (tracker->id == id)
		{
			printf("kill process id %d\n", id);
			if (prev == NULL)
			{
				p = p->next;
				free(tracker); //make a proper free process function
				tracker = p;
			}
			if (prev != NULL)
			{
				prev->next = tracker->next;
				free(tracker);
				tracker = prev->next;
			}
		}
		else
		{
			prev = tracker;
			tracker = tracker->next;
		}		
	}
}

int         check_alive(t_all *vm, t_process *p)
{
	int i;
	int alive;

	i = -1;
	alive = 0;
	if (vm->cycles == 0)
		return (1);
//	printf("vm->cycles = %d to_die = %d\n", vm->cycles, vm->cycles_to_die);
	while (++i < vm->total_champ)
	{
		if (vm->champs[i].last_live != -2)
		{
			if (vm->champs[i].last_live < vm->cycles - vm->cycles_to_die)
			{
		//		printf("current live = %d, cycle = %d\n", vm->champs[i].last_live, vm->cycles - vm->cycles_to_die);
				kill_process(p, vm->champs[i].id);
				vm->champs[i].last_live = -2;
			}
		else
			++alive;
		}
	}
	check_cycle_decrease(vm);
	if (alive > 1)
		return (1);
	return (0);
}