#include "../../includes/op.h"
#include <fcntl.h>
#include "../../libft/libft.h"
#include <stdio.h>
#include "../../includes/corewar.h"

void    create_file_cor(char *file_name, header_t *header)
{
    char *new_name;
    int len;
    char *header_magic;
    int j;
    int i;
    char *res;
    
    res = ft_strnew(8);
    j = 0;
    i = 0;
    len = ft_strlen(file_name) - 2;
    new_name = ft_strnew(len);
    ft_memcpy(new_name, file_name, len);
    new_name = ft_strjoin_fr(new_name, ".cor", 1);
    header->fd = open(new_name, O_WRONLY | O_CREAT, 0777);
    write(1, "Writing output program to ", 26);
    write(1, new_name, ft_strlen(new_name));
    header->magic = COREWAR_EXEC_MAGIC;
    header_magic = ft_uitoa_base(header->magic, 16, 0);
    header_magic = ft_strjoin_fr("00", header_magic, 2);
    while (header_magic[i])
    {
        res[j] = ft_strtol(&header_magic[i], 16, 2);
        i = i + 2;
        j++;
    }
    write(header->fd, res, 4);
    ft_printf("%s\n", header_magic);
    ft_strdel(&res);
    ft_strdel(&header_magic);
    ft_strdel(&new_name);
}

void    every_go(char *av, t_env *env)
{
    int     fd;
    char    *line;
    int     i;
    
    i = 0;
    fd = open(av, O_RDONLY);
   while (get_next_line(fd, &line) == 1)
    {
        if (line_ispoint(line) == 1)
            go_cmd(env, line);
        else if (line_empty(line) == 1)
        {   
            i = get_label(line, env);
            ft_printf("line apres get_label ==%s\n", &line[i]);
            i = i + get_instruc(&line[i], env);
            ft_printf("line apres get_label ==%s\n", &line[i]);
            get_params(&line[i], env);
            next_instruc(env);
        }
            free(line);
        i = 0;
    }
    //ft_printf("ok");
    //ft_strdel(&line);
   // print_label(env->label);
    //print_instruc(env->instruc);
    close(fd);
}

void    write_name_comment(header_t *header, int fd, t_env *env)
{
    int len;
    char c;
    int s;
    char *size;

    s = 4;
    c = 0;
    size = ft_uitoa_base(len_instruc(env->instruc) / 2, 16, 0); 
    //len_instruc(env->instruc) / 2;
    s = s - ft_strlen(size);
    while (s > 0)
    {
        size = ft_strjoin_fr("0", size, 2);
        s--;
    }
    //ft_printf("size of all == %s\n", size);
    len = PROG_NAME_LENGTH - ft_strlen(header->prog_name);
    //ft_printf("len == %d\n", len);
    write(fd, header->prog_name, ft_strlen(header->prog_name));
      //ft_printf("len == %d\n", len);
    while (len > 0)
    {
        write(fd, &c, 1);
        len--;
    }
    len = 4;
    while (len > 0)
    {
        write(fd, &c, 1);
        len--;
    }
    // separtion de la fonction en deux
    char *hexa_size;
    int j;
    int i;

    i = 0;
    j = 0;
    hexa_size = ft_strnew(4);
    while (size[i])
    {
        hexa_size[j] = ft_strtol(&size[i], 16, 2);
        i = i + 2;
        j++;
    }
    len = 4 - j;
    while (len > 0)
    {
        write(fd, &c, 1);
        len--;
    }
   //ft_printf("hexa == %d\n", hexa_size[0]);
    write(fd, hexa_size, 2);
    write(fd, header->comment, ft_strlen(header->comment));
    len = COMMENT_LENGTH - ft_strlen(header->comment);
   // ft_printf("len for comment == %d\n", len);
    while (len > 0)
    {
        write(fd, &c, 1);
        len--;
    }
    len = 4;
    while (len > 0)
    {
        write(fd, &c, 1);
        len--;
    }
    ft_strdel(&hexa_size);
    ft_strdel(&size);
}

void    write_to_file(t_instruc *instruc, int fd, header_t *header, t_env *env)
{
    char *res;
    int i;
    int j;
    int len;
    t_instruc *tmp;

    tmp = instruc;
    write_name_comment(header, fd, env);
    while (tmp->next)
    {
        len = (ft_strlen(tmp->hexa_instruc) / 2) + 1;
        j = 0;
        i = 0;
        res = ft_strnew(len);
        res[j] = dec_to_hexa(tmp->opcode);
        j++;
        while (tmp->hexa_instruc[i])
        {
            res[j] = ft_strtol(&tmp->hexa_instruc[i], 16, 2);
            j++;
            i = i + 2;
        }
        write(fd, res, len);
        ft_strdel(&res);
        tmp = tmp->next;
    }
}

int main(int ac, char **av)
{
    t_env    *env;
    int i;

    i = 1;
    if (ac == 1)
        return (-1);
    while (av[i])
    {
        env = init_env();
        every_go(av[i], env);
        create_file_cor(av[i], env->header); 
        write_to_file(env->instruc, env->header->fd, env->header, env);
        free_all(env, env->header);
        i++;
    }
    while (1);
    return (0);
}
