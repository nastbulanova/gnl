#include "gnl.h"

int ft_strlen(char *str)
{
	int i;

	if (!str)
		return(0);
	i = 0;	
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}
char	*ft_strjoin(char *str1, char *str2)
{
	char	*result;
	int		i;
	int		j;

	if (!str2)
		return (NULL);
	result = NULL;
	result = (char*)malloc(sizeof(char) * (ft_strlen(str1)) + ft_strlen(str2) + 1);
	if (!result)
	{
		if (str1)
			free(str1);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (str1 && str1[j] != '\0')
		result[i++] = str1[j++];
	j = 0;
	while (str2[j] != '\0')
	{
		result[i++] = str2[j];
		if (str2[j] == '\n')
			break ;
		j++;
	}
	result[i] = '\0';
	if (str1)
		free(str1);
	return (result);
}

int	ft_move_buf(char *str)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (str[i] != '\0')
	{
		if (flag)
		{
			str[j] = str[i];
			j++;
		}
		if (str[i] == '\n')
			flag = 1;
		str[i] = '\0';
		i++;
	}
	return (flag);
}

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char        *line;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	bytes = 0;
	while (1)
	{
		if (!buffer[0])
			bytes = read(fd, buffer, BUFFER_SIZE);
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
		if (ft_move_buf(buffer) || bytes == 0)
			break ;
	}
	if (line[0] == '\0')
        return (free(line), NULL);
	return (line);
}

int main()
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open("test", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
	return(0);
}
