#include "../includes/vm.h"

void op_live(t_all *vm, int i)
{
    if (i >= 0 && i < vm->total_champ)
    {
        vm->champs[i].live++; //or equal to cycle number? How to we check when was last live
        vm->last_alive = vm->champs[i].id;
        printf("A process shows that player %d (%s is alive\n", vm->champs[i].id, vm->champs[i].name);
    }
}