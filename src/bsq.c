/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 11:38:19 by fheaton-          #+#    #+#             */
/*   Updated: 2020/11/11 11:38:19 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern int g_error;

int main(int argc, char const *argv[])
{
	int i;

	i = 0;
	g_error = 0;
	if (argc == 1)
		solve(0);
	else if (argc >= 2)
		while (++i < argc)
			solve(open(argv[i]));
	return 0;
}
