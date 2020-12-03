/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lflags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:22:17 by mrozniec          #+#    #+#             */
/*   Updated: 2020/12/03 16:22:17 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

#include "libflag.h"

static char	*ft_long_hexa(t_printf *wip)
{
	unsigned long temp;

	temp = va_arg(wip->ap, unsigned long int);
	if (wip->conv == X_MIN)
		return (ft_litoa_base(temp, "0123456789abcdef"));
	else if (wip->conv == X_MAJ)
		return (ft_litoa_base(temp, "0123456789ABCDEF"));
	else if (wip->conv == U_MIN)
		return (ft_litoa_base(temp, "0123456789"));
	else
		return (ft_litoa_base(temp, "01234567"));
}

static char	*ft_long_num(t_printf *wip)
{
	long temp;

	temp = va_arg(wip->ap, long);
	return (ft_llitoa((long long)temp));
}

static char	*ft_long_char(t_printf *wip)
{
	wchar_t	*str;
	char	*res;
	int		i;

	if (wip->conv == S_MIN)
	{
		i = 0;
		if ((str = va_arg(wip->ap, wchar_t *)) == NULL)
			return (ft_strdup("(null)"));
		res = ft_char_conv(str[i++]);
		while (str[i])
			res = ft_strjoinmod(res, ft_char_conv(str[i++]), 3);
	}
	else
		res = ft_char_conv(va_arg(wip->ap, wchar_t));
	return (res);
}

static char	*ft_long_nconv(t_printf *wip)
{
	long long	*res;
	long		*arg;

	arg = va_arg(wip->ap, long *);
	if (arg != NULL)
	{
		if (!(res = malloc(sizeof(long long))))
			return (NULL);
		*res = 0;
		if (res != NULL)
			wip->strdone = ft_join_ns(wip->strdone, "", res, 1);
		*arg = (long)*res;
		free(res);
	}
	return ("");
}

char		*ft_lflag(t_printf *wip)
{
	if (wip->conv == X_MAJ || wip->conv == X_MIN || wip->conv == U_MIN ||
		wip->conv == O_MIN)
		return (ft_long_hexa(wip));
	if (wip->conv == I_MIN || wip->conv == D_MIN)
		return (ft_long_num(wip));
	if (wip->conv == S_MIN || wip->conv == C_MIN)
		return (ft_long_char(wip));
	if (wip->conv == N_MIN)
		ft_long_nconv(wip);
	return ("");
}
