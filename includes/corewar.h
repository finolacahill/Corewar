#ifndef COREWAR_H
# define COREWAR_H

typedef struct s_label
{
    char *label;
    int adress;
    struct s_label *next;
}           t_label;

typedef struct s_instruc
{
    int  opcode;
    char *params;
    int   ocp;
    int adress;
    struct s_label *label;
    char *hexa_instruc;
    struct s_instruc *next;
}           t_instruc;

typedef struct s_env
{
    struct s_instruc *instruc;
    struct s_label   *label;
}               t_env;

t_env   *init_env();
t_instruc   *new_instruct();
t_label     *new_label();
#endif