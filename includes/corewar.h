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
    int *params;
    int   ocp;
    int adress;
    int is_ocp;
    struct s_label *label;
    char *hexa_instruc;
    char *hexa_params;
    int  for_direct;
    struct s_instruc *next;
}           t_instruc;

typedef struct s_env
{
    struct s_instruc *instruc;
    struct s_label   *label;
}               t_env;

typedef struct s_op
{
    char *instruc;
    int nbr_params;
    int param_type[3];
    int opcode;
    int i_dont_know;
    char *real_name;
    int registre;
    int for_direct;
}               t_op;

t_env   *init_env();
t_instruc   *new_instruct();
t_label     *new_label();
int       get_label(char *line, t_env *env);
void    print_instruc(t_instruc *instruc);
void    print_label(t_label *labels);
int get_instruc(char *line, t_env *env);
int     get_params(char *line, t_env *env);
#endif