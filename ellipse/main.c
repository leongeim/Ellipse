//Der Header stdarg.h stellt Funktionen bereit, welche die notwendigen Adressberechnungen
//der Parameterliste einer Ellipse vornehmen.
#include <stdarg.h>
#include <stdio.h>

int print_char(char* eingabe, ...)
{
	//Deklaration eines Adress-Zeigers
	va_list arg_ptr;
	int sizeEingabe = 0;
	int count = 0;
	char para;

	while (eingabe[sizeEingabe] != '\0')
	{
		sizeEingabe++;
	}

	va_start(arg_ptr, eingabe);

	for (int i = 0; i < sizeEingabe; i++)
	{
		if (eingabe[i] == '%' && eingabe[i + 1] == 'c')
		{
			printf("%c", va_arg(arg_ptr, char));
			i++;
			count++;
		}
		else
		{
			printf("%c", eingabe[i]);
		}
	}

	//Zurücksetzen in den Ausgangszustand
	va_end(arg_ptr);

	return count;
}

void main()
{
	printf("%d", print_char("Die Buchstaben sind %c und %c.\nHier finden Sie alles von %c bis %c.\n",
		'a', 'b', 'c', 'd'));

	getchar();
}

