#include "../includes/corewar.h"

int		check_file(char *file)
{
	int i;
	int len;
	int j;

	i = 0;
	j = 0;
	while (file[i])
	{
		if (file[i] == '.')
			j = i;
		i++;
	}
	i = j;
	if (!file[i])
		return (-1);
	len = ft_strlen(&file[i]);
	if (ft_strcmp(".s", &file[i]) == 0)
		return (1);
	return (-1);
}

void	create_file_error(t_env *env, int i)
{
	free_all(env, env->header);
	error(i, -1, -1, NULL);
}

void	create_file_cor(char *file_name, t_header *header, t_env *env)
{
	char	*new_name;
	int		len;

	if (check_file(file_name) == -1)
		create_file_error(env, 2);
	len = ft_strlen(file_name) - 2;
	if (!(new_name = ft_strnew(len)))
		create_file_error(env, 8);
	ft_memcpy(new_name, file_name, len);
	if (!(new_name = ft_strjoin_fr(new_name, ".cor", 1)))
		create_file_error(env, 8);
	if ((header->fd = open(new_name, O_WRONLY | O_CREAT, 0777)) < 0)
	{
		free(new_name);
		create_file_error(env, 12);
	}
	if ((write_header_magic(header, new_name, 0)) == -1)
	{
		free(new_name);
		create_file_error(env, 8);
	}
	ft_strdel(&new_name);
}
