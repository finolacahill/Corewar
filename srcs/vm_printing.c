#include "../includes/vm.h"

static void print_top_line(int len)
{
    int z;

    z = -1;
    ft_printf("\n        ");
    while (++z < len)
        ft_printf("%02d ",z);
    ft_putchar('\n');
    ft_printf("\n---------------------------------------------------------------------");
    ft_printf("------------------------------------------------------------------------\n");
}

static void print_line(t_all *vm, int len, int start)
{
    int i;
    int x;

    i = start - 1;
    x = 0;
    while (++i < len + start)
    {
        if (i >= vm->champs[x].start &&
            i < vm->champs[x].start + (int)vm->champs[x].len_exec_code)
            {
                ft_printf("\033[0;35m%02x ", vm->arena[i]);
                if (i == vm->champs[x].start + (int)vm->champs[x].len_exec_code - 1)
                    ++x;
            }
        else
        {
            if (vm->arena[i] != 0)
                ft_printf("\033[0;35m%02x ", vm->arena[i]);
            else
                ft_printf("\033[0m%02x ", vm->arena[i]);
        }
    }
}

static void print_hex(start)
{
    ft_printf("%#05x : ", start);
}

void ft_print_arena(t_all *vm, int len)
{
    int start = 0;
 
    print_top_line(len);
    while (start < MEM_SIZE)
    {
        print_hex(start);
        print_line(vm, len, start);
        ft_putchar('\n');
        start += len;
    }    
}