#include "../includes/vm.h"

int     op_live(t_all *vm, int pc)
{
    printf("live reg stored at %i.", vm->arena[pc + 1]);
    printf("stay here for 10 cycles.\n");
    return (pc + 2);
}

int     op_ld(t_all *vm, int pc)
{
    printf("ld: opc code of %d", vm->arena[pc + 1]);
    printf("reg of %d, reg of %d.", vm->arena[pc+2], vm->arena[pc +3]);
    return (pc + 4);
}

int op_st(t_all *vm, int pc)
{
    printf("st: opc code of %d", vm->arena[pc + 1]);
    printf("reg of %d, reg/ind of %d.", vm->arena[pc+2], vm->arena[pc +3]);
    return (pc + 4);
}

int op_add(t_all *vm, int pc)
{
    printf("add: opc code of %d", vm->arena[pc + 1]);
    printf("reg of %d, reg of %d reg of %d.", vm->arena[pc+2], vm->arena[pc +3], vm->arena[pc + 4]);
    return (pc + 5);
}

int op_sub(t_all *vm, int pc)
{
    printf("sub: opc code of %d", vm->arena[pc + 1]);
    printf("reg of %d, reg of %d reg of %d.", vm->arena[pc+2], vm->arena[pc +3], vm->arena[pc + 4]);
    return (pc + 5);
}

int op_and(t_all *vm, int pc)
{
    printf("and: opc code of %d", vm->arena[pc + 1]);
    printf("reg/i/dir of %d, reg/i/dir of %d reg of %d.", vm->arena[pc+2], vm->arena[pc +3], vm->arena[pc + 4]);
    return (pc + 5);
}

int op_or(t_all *vm, int pc)
{
    printf("or: opc code of %d", vm->arena[pc + 1]);
    printf("reg/i/dir of %d, reg/i/dir of %d reg of %d.", vm->arena[pc+2], vm->arena[pc +3], vm->arena[pc + 4]);
    return (pc + 5);
}

int op_xor(t_all *vm, int pc)
{
    printf("xor: opc code of %d", vm->arena[pc + 1]);
    printf("reg/i/dir of %d, reg/i/dir of %d reg of %d.", vm->arena[pc+2], vm->arena[pc +3], vm->arena[pc + 4]);
    return (pc + 5);
}

int op_zjmp(t_all *vm, int pc)
{
    printf("zjmp: dir of %d", vm->arena[pc + 1]);
    return (pc + 2);
}
//not working. Can't accurately return pc code without taking
//into account OPC and hence the coming size of the parameters following it. 
// so must decode ocp first. 
int   load_process(t_all *vm, int pc)
{
    int i = vm->arena[pc];
    
    printf("pc = %d, i = %d\n", pc, i);
    if (i == 1)
        pc = op_live(vm, pc);
    if (i == 2)
        pc = op_ld(vm, pc);
    if (i == 3)
        pc = op_st(vm, pc);
    if (i == 4)
        pc = op_add(vm, pc);
    if (i == 5)
        pc = op_sub(vm, pc);
    if (i == 6)
        pc = op_and(vm, pc);
    if (i == 7)
        pc = op_or(vm, pc);
    if (i == 8)
        pc = op_xor(vm, pc);
    if (i == 9)
        pc = op_zjmp(vm, pc);
    if (i == 10)
        pc = pc + 5; //ldi
    if (i == 11)
        pc = pc + 7; //sdi
    if (i == 12)
        pc = pc + 2; //fork
    if (i == 13)
        pc = pc + 4; //lld
    if (i == 14)
        pc = pc + 5; //lldi
    if (i == 15)
        pc = pc + 2; //lfork
    if (i == 16)
        pc = pc + 3; //aff
    return (pc);
}
