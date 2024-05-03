/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djewapat <djewapat@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:55:24 by djewapat          #+#    #+#             */
/*   Updated: 2024/05/03 16:55:24 by djewapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_get_line(char *buffer)
{
	char	*str;
	size_t	len;
	size_t	i;

	if (!*buffer)
		return (NULL);
	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (buffer[len] == '\n')
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = buffer[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_next_line(char *buffer)
{
	size_t		i;
	size_t		j;
	char		*next;

	if (!*buffer)
	{
		free (buffer);
		return (NULL);
	}
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	next = (char *)malloc(sizeof(char) * ((ft_strlen(buffer) - i) + 1));
	if (next == NULL)
		return (NULL);
	j = 0;
	while (buffer[i] != '\0')
		next[j++] = buffer[i++];
	next[j] = '\0';
	if (!*next)
		return (free(next), free(buffer), NULL);
	free (buffer);
	return (next);
}

static char	*ft_read_line(int fd, char *buffer)
{
	char	*temp;
	int		read_byte;

	temp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	read_byte = 1;
	while (read_byte != 0 && !ft_strchr(buffer, '\n'))
	{
		read_byte = read(fd, temp, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free (buffer);
			free (temp);
			return (NULL);
		}
		temp[read_byte] = '\0';
		buffer = ft_strjoin(buffer, temp);
	}
	free (temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_read_line(fd, buffer[fd]);
	if (buffer == NULL)
		return (NULL);
	line = ft_get_line(buffer[fd]);
	buffer[fd] = ft_next_line(buffer[fd]);
	return (line);
}

#include <fcntl.h>

int main ()
{
	int fd1 = open("a.txt", O_RDONLY);
	int fd2 = open("c.txt", O_RDONLY);
	char *line;

	line = get_next_line(fd1);
	printf("%s\n", line);
	free(line);
	line = get_next_line(fd2);
	printf("%s\n", line);
	free(line);
	line = get_next_line(fd1);
	printf("%s\n", line);
	free(line);
	line = get_next_line(fd2);
	printf("%s\n", line);
	free(line);
	line = get_next_line(fd2);
	printf("%s\n", line);
	free(line);
	line = get_next_line(fd1);
	printf("%s\n", line);
	free(line);
	line = get_next_line(fd1);
	printf("%s\n", line);
	free(line);
	close(fd1);
	close(fd2);
}