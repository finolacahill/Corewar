#include "../includes/vm.h"

void	declare_winner(t_all *vm)
{
	if (is_player_nb(vm->last_alive, vm) == 1)
		ft_printf("THE WINNER IS PLAYER NUMBER %d, %s!!!\n", vm->last_alive, vm->champs[vm->last_alive - 1].name);
	else
	{
		ft_printf("A mystery player, number %d, has won", vm->last_alive); //or it was a draw?
	}	
}

int     run_vm(t_all *vm, t_process *process)
{
	t_op		*op_table;

	if (!(op_table = (t_op*)malloc(sizeof(t_op) * 16)))
		return (error_run_vm(vm, process, op_table));
//add malloc protections for init op_check
	op_table = init_op_check(vm, op_table);
	vm->cycles_to_die = CYCLE_TO_DIE;
	process = load_processes(vm, process);
	if (process->start == -1)
		return (error_run_vm(vm, process, op_table));
	while (check_alive(vm, process) == 1)
		if ((run_processes(vm, process, op_table) == -100))
			return (0);
			//FREE ZL THINGS HErE
	declare_winner(vm);
	free_op_table(op_table);
	return (0);
}