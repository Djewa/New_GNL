/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djewapat < djewapat@student.42bangkok.com> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:32:55 by djewapat          #+#    #+#             */
/*   Updated: 2024/05/04 11:32:55 by djewapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

# define OPEN_MAX 1024

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int find);
char	*ft_strjoin(char *s1, char *s2);

#endif