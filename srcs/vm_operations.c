#include "../includes/vm.h"

void		get_next_bytes(t_all *vm, t_process *p, int *value, int len)
{
	int		val;
	int		i;

	val = 0;
	i = 0;
	while (++i <= len)
	{
		val <<= 8;
		val += vm->arena[((p->pc + i) % MEM_SIZE)];
	}
	*value = val;
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