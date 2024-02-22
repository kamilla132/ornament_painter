/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaalimag <kaalimag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:50:11 by alhakala          #+#    #+#             */
/*   Updated: 2023/11/19 17:53:54 by kaalimag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		putchar(int ch);
void	first(int count, int *the_last_char);
void	last(int count);
void	middle_part(int count, int *the_last_char, int *the_first_char);
void	while_function(int count, int *the_last_char, int *the_first_char);
int	g_x;
int	g_y;

void	rush(int x, int y)
{
	int	count;
	int	the_last_char;
	int	the_first_char;

	g_x = x;
	g_y = y;
	if (g_x <= 0 || g_y <= 0)
	{
		return ;
	}
	the_last_char = 0;
	the_first_char = 0;
	count = 1;
	while (count <= (g_x * g_y + g_y))
	{
		while_function(count, &the_last_char, &the_first_char);
		count++;
	}
}

void	while_function(int count, int *the_last_char, int *the_first_char)
{
	if (count <= g_x + 1)
	{
		first (count, the_last_char);
	}
	else if (count >= ((g_x * g_y + g_y) - g_x))
	{
		last(count);
	}
	else
	{
		middle_part(count, the_last_char, the_first_char);
	}
}

void	first(int count, int *the_last_char)
{
	if (count == 1)
	{
		putchar('A');
	}
	else if (count == g_x)
	{
		putchar('C');
	}
	else if (count == g_x + 1)
	{
		putchar('\n');
		*the_last_char = count;
	}
	else
	{
		putchar('B');
	}
}

void	last(int count)
{
	if (count == ((g_x * g_y + g_y) - g_x))
	{
		putchar('A');
	}
	else if (count == ((g_x * g_y + g_y) - 1))
	{
		putchar('C');
	}
	else if (count == (g_x * g_y + g_y))
	{
		putchar('\n');
	}
	else
	{
		putchar('B');
	}
}

void	middle_part(int count, int *the_last_char, int *the_first_char)
{
	if (count == *the_last_char + 1)
	{
		putchar('B');
		*the_first_char = count;
	}
	else if (count == (*the_first_char + g_x - 1))
	{
		putchar('B');
	}
	else if (count == (*the_first_char + g_x))
	{
		putchar('\n');
		*the_last_char = count;
	}
	else
	{
		putchar(' ');
	}
}
