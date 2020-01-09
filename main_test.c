#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

int main (int ac, char **av)
{
	// int			fd;
	// uint8_t		buff[BUFF_SIZE + 1];
	// int			ret;
	// size_t		cor_size;
	// uint8_t		*cor_content;

	// cor_content = NULL;
	// fd = open("test.cor", O_RDWR);
	// ret = read(fd, buff, BUFF_SIZE);
	// cor_size = ret;

	// 													printf("===> ret = %d\n", ret);
	// 													// int it = -1;
	// 													// while (++it < 20)
	// 														printf("|%d| \n", buff[136]);
	// 														printf("|%d| \n", buff[137]);
	// 														printf("|%d| \n", buff[138]);
	// 														printf("|%d| \n", buff[139]);
	// buff[137] = 25;
	// 														printf("|%d| \n", buff[136]);
	// 														printf("|%d| \n", buff[137]);
	// 														printf("|%d| \n", buff[138]);
	// 														printf("|%d| \n", buff[139]);
	// buff[ret] = '\0';
	// close(fd);

	// char	*str = "test.cor";
	// // FILE *fichier;
	// // fichier = fopen(str, "w");
	// // fichier->
	// fd = open(str, O_RDWR);
	// write(fd, buff, ret);
	// close(fd);
	char **res;

	res = ft_strsplit("bjr les amis",' ');
	return (0);
}