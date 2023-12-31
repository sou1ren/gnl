#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = (char *)s;
	while (n > 0)
	{
		*str = 0;
		str++;
		n--;
	}
}

char    *get_line(int fd, char *leftover)
{
    ssize_t bytes_read;
    char    *buffer;
    char    *unite;
    char    *tmp;

    unite = leftover;
    // printf("1_unite:%s\n", unite);
    buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    ft_bzero(buffer, BUFFER_SIZE);
    if (buffer == NULL)
        return (NULL);
    bytes_read = 1;
    while (!ft_strchr(unite, '\n'))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        // printf("bytes:%ld\n", bytes_read);
        buffer[bytes_read] = '\0';
        // printf("buffer:%s\n", buffer);
        if (bytes_read <= 0)
        {
            // printf("EOF_unite:%s\n", unite);
            buffer = NULL;
            free(buffer);
            return (unite);
        }
        // printf("unite:%s\n", unite);
        tmp = ft_strjoin(unite, buffer);
        // printf("tmp:%s\n",tmp);
        free(unite);
        unite = tmp;
        // buffer = NULL;
        // printf("last_unite:%s\n", unite);
    }
    free(buffer);
    return (unite);
}

int div_by_n(char *unite)
{
    int n;

    n = 0;
    while (unite[n] != '\n' && unite[n] != '\0')
        n++;
    return (n);
}

char    *get_next_line(int fd)
{
    char    *line;
    static char *leftover;
    char    *unite;
    int     n;
    int     i;
    int     len;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    // printf("1_leftover:%s\n", leftover);
    unite = get_line(fd, leftover);
    // printf("2_unite:%s\n",unite);
    if (unite == NULL)
        return (NULL);
    len = ft_strlen(unite);
    n = div_by_n(unite);
    i = 0;
    line = (char *)malloc((n + 2) * sizeof(char));
    if (line == NULL)
        return (NULL);
    while (i < n + 1)
    {
        line[i] = unite[i];
        i++;
    }
    line[i] = '\0';
    // printf("len-n:%d\n", (len-n));
    // printf("2_leftover:%s\n", leftover);
    if (n == len)
    {
        leftover = (char *)malloc(1);
        leftover = NULL;
        free(unite);
        return (line);
    }
    leftover = (char *)malloc((len-n)* sizeof(char));
    if (leftover == NULL)
        return (NULL);
    i = 0;
    while (i < len - n - 1)
    {
        leftover[i] = unite[n + 1 + i];
        i++;
    }
    leftover[i] = '\0';
    // printf("leftover:%s\n", leftover);
    free(unite);
    return (line);
}

// int main(void)
// {
//     char    str[] = "12\n34\n56\n";
//     int n = div_by_n(str);

//     printf("%d\n", n);
//     return (0);
// }

#include <fcntl.h>
int main(void)
{
    int fd;
    char    *line;
    fd = open("test1", O_RDONLY);
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        printf("%s", line);
        free(line);
    }
    // line = get_next_line(fd);
    // printf("line:%s", line);
    // free(line);    
    // line = get_next_line(fd);
    // printf("line:%s", line);
    // free(line);
    // line = get_next_line(fd);
    // printf("line:%s", line);
    // free(line);
    // line = get_next_line(fd);
    // printf("line:%s", line);
    // free(line);
    // line = get_next_line(fd);
    // printf("line:%s", line);
    // free(line);
    // line = get_next_line(fd);
    // printf("line:%s", line);
    // free(line);
    // line = get_next_line(fd);
    // printf("line:%s", line);
    // free(line);
    // line = get_next_line(fd);
    // printf("line:%s", line);
    // free(line);
    // line = get_next_line(fd);
    // printf("line:%s", line);
    // free(line);
    // line = get_next_line(fd);
    // printf("line:%s", line);
    // free(line);
    // line = get_next_line(fd);
    // printf("line:%s", line);
    // free(line);
    // line = get_next_line(fd);
    // printf("line:%s", line);
    // free(line);
    // line = get_next_line(fd);
    // printf("line:%s", line);
    // free(line);
    // line = get_next_line(fd);
    // printf("line:%s", line);
    // free(line);
    close(fd);
    return (0);
}
