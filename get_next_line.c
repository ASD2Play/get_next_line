/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alasoare <alasoare@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:57:43 by alasoare          #+#    #+#             */
/*   Updated: 2024/10/30 10:02:39 by alasoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*clear_buffer(char **buffer_store)
{
	if (*buffer_store)
	{
		free(*buffer_store);
		*buffer_store = NULL;
	}
	return (NULL);
}

static char	*get_line(char **buffer_store)
{
	char	*newline_position;
	char	*line;
	char	*remaining_buffer;
	size_t	line_length;

	if (!*buffer_store)
		return (NULL);
	newline_position = ft_strchr(*buffer_store, '\n');
	if (newline_position)
	{
		line_length = newline_position - *buffer_store + 1;
		line = (char *)malloc((line_length + 1) * sizeof(char));
		if (!line)
			return (clear_buffer(buffer_store));
		ft_strappend(line, *buffer_store, NULL, line_length + 1);
		remaining_buffer = ft_strdup(newline_position + 1);
		free(*buffer_store);
		*buffer_store = remaining_buffer;
		if (*buffer_store && **buffer_store == '\0')
			clear_buffer(buffer_store);
		return (line);
	}
	line = ft_strdup(*buffer_store);
	clear_buffer(buffer_store);
	return (line);
}

static ssize_t	read_file(int fd, char **buffer_store)
{
	char	*temp_buffer;
	char	*temp_store;
	ssize_t	bytes_read;

	temp_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp_buffer)
		return (-1);
	bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		temp_buffer[bytes_read] = '\0';
		if (*buffer_store)
			temp_store = ft_strjoin(*buffer_store, temp_buffer);
		else
			temp_store = ft_strdup(temp_buffer);
		free(*buffer_store);
		*buffer_store = temp_store;
		if (ft_strchr(temp_buffer, '\n'))
			break ;
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
	}
	free(temp_buffer);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*buffer_store;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read_file(fd, &buffer_store) < 0)
		return (clear_buffer(&buffer_store));
	return (get_line(&buffer_store));
}
