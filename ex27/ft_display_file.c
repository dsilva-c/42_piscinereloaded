/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-c <dsilva-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:31:05 by dsilva-c          #+#    #+#             */
/*   Updated: 2025/10/09 12:44:31 by dsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 4096

void	ft_putstr_err(char *str);
void	display_file_content(char *filename);

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putstr_err("File name missing.\n");
		return (1);
	}
	if (argc > 2)
	{
		ft_putstr_err("Too many arguments.\n");
		return (1);
	}
	display_file_content(argv[1]);
	return (0);
}

void	ft_putstr_err(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

void	display_file_content(char *filename)
{
	int		fd;
	int		bytes_read;
	char	buffer[BUFFER_SIZE];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_err("Cannot read file.\n");
		return ;
	}
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		write(1, buffer, bytes_read);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read == -1)
	{
		ft_putstr_err("Cannot read file.\n");
		close(fd);
		return ;
	}
	close(fd);
}
