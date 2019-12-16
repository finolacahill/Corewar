
#include "../includes/vm.h"

void ft_print_arena(t_all *vm)
{
    int i = -1; 
    int j = -1;
    int colour = 0;
    int x = 0;
    int z = -1;
 
    while (++z < 64)
        ft_printf("%02d ", z);
    ft_printf("\n---------------------------------------------------------------------------------------------------------------------------------------------\n");
    while (++i < MEM_SIZE)
    {
        if (i >= vm->champs[x].start &&
            i < vm->champs[x].start + (int)vm->champs[x].len_exec_code)
            {
                printf("\033[0;35m%02x ", vm->arena[i]);
                if (i == vm->champs[x].start + (int)vm->champs[x].len_exec_code - 1)
                    ++x;
            }
        else
        {
            if (vm->arena[i] != 0)
                printf("\033[0;35m%02x ", vm->arena[i]);
            else
                printf("\033[0m%02x ", vm->arena[i]);
        }
        if (++j == 63)
        {
            printf("\n");
            j = -1;
        }
    }
}

int init_arena(t_all *vm)
{
  //  t_arena *a;
    int     i;
    int     divide;

    i = 0;
    divide = 0;
    vm->cycles = 0;
    vm->last_alive = 0;
    vm->last_alive_cycle = 0;
    vm->nbr_live_since_check = 0;
    vm->total_checks = 0;
    if (!(vm->arena = ft_memalloc((sizeof(unsigned char)) * MEM_SIZE)))
        return (-1);
    printf ("%d\n", vm->total_champ);
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