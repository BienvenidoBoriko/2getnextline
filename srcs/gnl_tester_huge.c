/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_tester_huge.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:41:21 by mchardin          #+#    #+#             */
/*   Updated: 2019/11/14 20:49:10 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int		fd;
	int		i;
	int		j;
	char	*line = 0;

	j = 1;
	printf("\n==========================================\n");
	printf("========== TEST 1 : The Alphabet =========\n");
	printf("==========================================\n\n");

	if (!(fd = open("files/huge_alphabet", O_RDONLY)))
	{
		printf("Error in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		free(line);
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);
	if (BUFFER_SIZE == 0 && i == -1)
		printf ("Well Done - Returned -1\n");
	else if (BUFFER_SIZE == 0 && i != -1)
		printf ("Not Good - Did not return -1 for BUFFER_SIZE=0\n");
	else if (i == -1)
		printf ("Error in Fonction - Returned -1\n");
	else if (j == 1056)
		printf("\nRight number of lines\n");
	else if (j != 1056)
		printf("Not Good - Wrong Number Of Lines\n");
	j = 1;
	printf("\n==========================================\n");
	printf("========= TEST 8 : SUPER FAT FILE ========\n");
	printf("==========================================\n\n");

	if (!(fd = open("files/huge_file", O_RDONLY)))
	{
		printf("Error in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		free(line);
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);
	if (BUFFER_SIZE == 0 && i == -1)
		printf ("Well Done - Returned -1\n");
	else if (BUFFER_SIZE == 0 && i != -1)
		printf ("Not Good - Did not return -1 for BUFFER_SIZE=0\n");
	else if (i == -1)
		printf ("Error in Fonction - Returned -1\n");
	else if (j == 2916)
		printf("\nRight number of lines\n");
	else if (j != 2916)
		printf("Not Good - Wrong Number Of Lines\n");
	j = 1;
	printf("\n==========================================\n");
	printf("======== TEST 8 : SUPER LONG LINE ========\n");
	printf("==========================================\n\n");

	if (!(fd = open("files/huge_line", O_RDONLY)))
	{
		printf("Error in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
		j++;
	}
	printf("%s\n", line);
	free(line);
	close(fd);
	if (BUFFER_SIZE == 0 && i == -1)
		printf ("Well Done - Returned -1\n");
	else if (BUFFER_SIZE == 0 && i != -1)
		printf ("Not Good - Did not return -1 for BUFFER_SIZE=0\n");
	else if (i == -1)
		printf ("Error in Fonction - Returned -1\n");
	else if (j == 1)
		printf("\nRight number of lines\n");
	else if (j != 1)
		printf("Not Good - Wrong Number Of Lines\n");
	return (0);
}
