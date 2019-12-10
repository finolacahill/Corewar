/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libsrcs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 10:18:48 by adietric          #+#    #+#             */
/*   Updated: 2019/12/06 15:18:12 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSRCS_H
# define LIBSRCS_H

# include <unistd.h>
# include <stdlib.h>

char				*ft_strcat(char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *src);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnew(size_t size);
char				*ft_strchr(const char *s, int c);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isdigit(int c);
int					ft_isspace(int c);
void				*ft_memalloc(size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_nblen(int nb);
unsigned long long	ft_puissance(int nbr, int p);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, int n);
void				ft_putstr(char const *s);
void				ft_putnbr(int nbr);
void				ft_putchar(char c);
void				ft_reverse(char **str);
void				ft_memcpy(void *dest, const void *src, size_t n);

#endif
