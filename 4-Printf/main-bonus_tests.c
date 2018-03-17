/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 17:38:08 by mkamel            #+#    #+#             */
/*   Updated: 2018/03/17 12:35:45 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"
#include <stdio.h>
#include <limits.h>
#include <locale.h>

int        main()
{
	setlocale(LC_ALL, "");
	int			oct;
	int        ret;
	int        comp;

	ret = 0;
	comp = 0 ;
	oct = 666;

// -------------------------------------------------
// ----------------WILDCARD TEST-------------------
	ret += ft_printf("{%.2x}\n", 123);
	comp += printf("{%.2x}\n", 123);
/*
	ret += ft_printf("{%3*p}\n", 10, 0);
	comp += printf("{%3*p}\n", 10, 0);

	ret += ft_printf("{%3*p}\n", -10, 0);
	comp += printf("{%3*p}\n", -10, 0);


	ret += ft_printf("{%*.**.*d}\n", -15, 10, 22, 5, 42);
	comp += printf("{%*.**.*d}\n", -15, 10, 22, 5, 42);

	ret += ft_printf("{%*.*s}\n", 18, -1, "424242");
	comp += printf("{%*.*s}\n", 18, -1, "424242");

	ret += ft_printf("{%*.*s}\n", 18, 3, "424242");
	comp += printf("{%*.*s}\n", 18, 3, "424242");

*/


// -------------------------------------------------
// ---------------- %n TEST -------------------
/*
	ret += ft_printf("{123456789 %4.2s %#+0-99.9n}","MAHAHAHA", &oct);
	printf("\noct = %d\n", oct);
	comp += printf("{123456789 %4.2s %#+0-99.9n}","MAHAHAHA", &oct);;
	printf("\noct = %d\n", oct);

	ret += ft_printf("123456789 %10.5n", &oct);
	printf("\noct = %d\n", oct);
	comp += printf("123456789 %10.5n", &oct);
	printf("\noct = %d\n", oct);

	ret += ft_printf("{oct = %d, the number of the BEAST! %4.2s %#+0-99.9n}",oct, "MAHAHAHA", &oct);
	printf("\noct = %d\n", oct);
	comp += printf("{oct = %d, the number of the BEAST! %4.2s %#+0-99.9n}",oct, "MAHAHAHA", &oct);
	printf("\noct = %d\n", oct);
*/

//-------------------------------------------------
// ---------------- $ TEST -------------------

/*
	ft_putchar('\n');
	ret += ft_printf("123%0 10#5$d et  %4$d\n", 1, 2, 3, 4, 5, 6);
	comp += printf("123%0 10#5$d et  %4$d\n", 1, 2, 3, 4, 5, 6);

	ft_printf("1er arg : %d puis le 5{red}%0 10#5$s{eoc} je reviens au 1er : {gre}%1$d{eoc}\n", 1, 2, 3, 4, "cinq", 6);
	ret += ft_printf("1er arg : %d puis le 5%0 10#5$s je reviens au 1er : %1$d\n", 1, 2, 3, 4, "cinq", 6);
	comp += printf("1er arg : %d puis le 5%0 10#5$s je reviens au 1er : %1$d\n", 1, 2, 3, 4, "cinq", 6);
;

	ret += ft_printf("le cinq en octal avec une largeur de 10 et 0 : %0 10#5$o et le 4 en d %4$d puis on revient au 1 en x %1$x et puis on redonne la suite en d : %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6);
	comp += printf("le cinq en octal avec une largeur de 10 et 0 : %0 10#5$o et le 4 en d %4$d puis on revient au 1 en x %1$x et puis on redonne la suite en d : %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6);
	ret += ft_printf("Quand on met la precision devant le $ ca ne fonctionne pas : %0 10#.5$o et  %4$d\n", 1, 2, 3, 4, 5, 6);
	comp += printf("Quand on met la precision devant le $ ca ne fonctionne pas : %0 10#.5$o et  %4$d\n", 1, 2, 3, 4, 5, 6);
*/


//-------------------------------------------------
// ---------------- %fF TEST -------------------
/*
	ft_putchar('\n');
   ret += ft_printf("%#-+15.5F %-4f\n", 10.0/0.0, "abc");
	comp += printf("%#-+15.5F %-4f\n", 10.0/0.0, "abc");

	ret += ft_printf("%#-+15.5f\n", 0.0);
	comp += printf("%#-+15.5f\n", 0.0);

	ret += ft_printf("%#0 18f\n", 25.6789);
	comp += printf("%#0 18f\n", 25.6789);

	ret += ft_printf("%0+- 18.5f\n", 25.6789);
	comp += printf("%0+- 18.5f\n", 25.6789);

//	AVEC LE FLAG L 
	ret += ft_printf("%#-+15.5Lf\n", 2.725000e+02L);
	comp += printf("%#-+15.5Lf\n", 2.725000e+02L);

	ret += ft_printf("{%f}{%f}", (1.0 / 0.0), "c");
	comp +=printf("{%f}{%f}", (1.0 / 0.0), "c");

	ret += ft_printf("{%.2f}{%.2F}\n", 0.0, 0);
	comp += printf("{%.2f}{%.2F}\n", 0.0, 0);

	ret += ft_printf("{%f}{%F}\n", 1444565444646.6465424242242, 1444565444646.6465424242242);
	comp += printf("{%f}{%F}\n", 1444565444646.6465424242242, 1444565444646.6465424242242);
*/
//-------------------------------------------------
// ---------------- COLOR TEST -------------------


//	ft_putchar('\n');
//	ft_printf("aha, du {red}rouge {eoc} du {cya} bleu du {whi}blanc du {yel}jaune du {gre}vert {und}souligne {bal}gras et finalement{eoc} plus rien...{red}{bal}{und}MAHAHA{eoc}\n");


//-------------------------------------------------
//---------------- %b TEST -------------------
/*
	ft_printf("{%b}\n", 0);
	ft_printf("{%b}\n", 42);
	ft_printf("{%b}\n", 255);
	ft_printf("{%b}\n", 256);
	ft_printf("{%b}\n", 65535);
	ft_printf("{%b}\n", 65536);
	ft_printf("{%b}\n", "WTF");
	ft_printf("{%b}\n", "42 is for the brave");
*/



//-------------------------------------------------
//---------------- %WTF TEST -------------------



//	ret += ft_printf("%.5@\n");
//	comp += printf("%.5@\n");

// !!! Les  2 suivant sont a faire faire un par un !!!

//	ret += ft_printf("%#*.10x\n", 10);
//	comp += printf("%#*.10x\n", 10);
//	ret += ft_printf("%#4d %15d %d\n", 10);
//	comp += printf("%#4d %15d %d\n", 10);


//	ret += ft_printf("%#.10x\n", 0);
//	comp += printf("%#.10x\n", 0);


//	ret = ft_printf("{%05d}\n", "WTF");
//	comp = printf("{%05d}\n", "WTF");

// ATTENTION : l'int WTF est ENOOOORRMEE
//	ret += ft_printf("{%05.*d}\n", "WTF", 42);
//	comp += printf("{%05.*d}\n", "WTF", 42);


//	ret += ft_printf("%lc titi\n", 0xffff);
//	comp += printf("%lc titi\n", 0xffff);

//	ret += ft_printf("%lc\n", 254);
//	comp += ft_printf("%lc\n", 254);

//	ret += ft_printf("%10.0ls\n", 0);
//	comp += ft_printf("%10.0ls\n", 0);


//	ret += ft_printf("%+#-010.5y\n", 0);
//	comp += printf("%+#-010.5y\n", 0);

//	ret += ft_printf("%+#-05.10y\n", 0);
//	comp += printf("%+#-05.10y\n", 0);

	printf("\nret = %d\ncomp = %d\n", ret, comp);
}

