/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:35:51 by amaso             #+#    #+#             */
/*   Updated: 2022/07/04 14:49:40 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//Tocca checkare che in tutti gli input ci siano solo numeri dallo 0 al 9, e se ci sta uno spazio tra un numero e un altro tocca mandarlo in pasto a split.
//Una volta che so quanti numeri ho posso iniziare a inserirlo nello A stack
//Continua qui, inserisci e gestisci lo split dell'input, ricorda che quando vai a splittare il count sarà già ad uno, quindi aumenta il count di pars.push di N-1.
void	ft_parsing(int argc, char *argv[], t_push *push)
{
	int	i;
	int	c;

	i = 0;
	c = -1;
	push->pars.count = 0;
	while (++i < argc)
	{
		while (++c < ft_strlen(argv[i]))
		{
			if (c != 0 && argv[i][c] == 32)
				ft_split(argv[i], push);
			if (argv[i][c] > 57 || argv[i][c] < 48)
				ft_error("forbidden char on the input");
		}
		push->pars.count++;
		c = -1;
	}
}

int	main(int argc, char *argv[])
{
	t_push	push;

	ft_parsing(argc, argv, &push);
}
