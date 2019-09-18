/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:54:49 by elchrist          #+#    #+#             */
/*   Updated: 2019/09/10 19:56:18 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>

void ft_print_numbers(void)
{
	char digit;

	digit = '0';
	while (digit <= '9')
	{
		write(1, &digit, 1);
		digit++;
	}
}

int main()
{
	ft_print_numbers();
	return (0);
}
