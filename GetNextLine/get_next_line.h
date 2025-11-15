/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:25:24 by mgumienn          #+#    #+#             */
/*   Updated: 2025/11/15 14:52:07 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
int		ft_strchr_gnl(char *str, int c);
size_t	ft_strlcpy_gnl(char **dest, char *src, size_t size);
char	*ft_strjoinc(char *s1, char c);
char	*ft_strdup_gnl(char *src);

#endif