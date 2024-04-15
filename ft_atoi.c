/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmiszkie <wmiszkie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:23:47 by wmiszkie          #+#    #+#             */
/*   Updated: 2024/03/24 16:23:50 by wmiszkie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h> 
/*Poniższa funkcja ft_atoi przekształca ciąg znaków (const char *str) na liczbę
całkowitą (int). Funkcja atoi (skrót od "ASCII to integer") jest standardową
funkcją w języku C, która konwertuje ciąg znaków (reprezentowany jako wskaźnik
na char) na liczbę całkowitą typu int. Ciąg znaków powinien składać się z
opcjonalnych białych znaków, opcjonalnego znaku (plus + lub minus -) i sekwencji
cyfr. Oto szczegółowy opis tego, jak atoi przetwarza ciąg znaków na liczbę:*/

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	return (res * neg);
}

int main() {
    char *str1 = "   -1234";
    char *str2 = "+5678";
    char *str3 = "   -0";
    char *str4 = "2147483647";  // Maksymalna wartość dla int
    char *str5 = "-2147483648"; // Minimalna wartość dla int

    // Testowanie funkcji ft_atoi na różnych ciągach znaków
    printf("ft_atoi(\"%s\") = %d\n", str1, ft_atoi(str1));
    printf("ft_atoi(\"%s\") = %d\n", str2, ft_atoi(str2));
    printf("ft_atoi(\"%s\") = %d\n", str3, ft_atoi(str3));
    printf("ft_atoi(\"%s\") = %d\n", str4, ft_atoi(str4));
    printf("ft_atoi(\"%s\") = %d\n", str5, ft_atoi(str5));

    return 0;
}

/*
1. Deklaracja zmiennych int i - indeks aktualnie przetwarzanego znaku w ciągu.
   int neg - wskaźnik, czy liczba jest ujemna. 1 oznacza liczbę dodatnią, -1
   liczbę ujemną. int res - wynikowa wartość, która będzie przechowywać
   konwertowaną liczbę.

2. Inicjalizacja zmiennych i jest ustawione na 0, aby zacząć od początku ciągu.
   neg na 1, zakładając na początku, że liczba jest dodatnia. res na 0, ponieważ
   na początku nie mamy jeszcze żadnych cyfr.

3. Pętla while kontynuowana jest do momentu napotkania znaku, który nie jest
   białym znakiem. W C białe znaki to spacje (' '), tabulacje oraz różne inne
   znaki kontrolne (kody ASCII od 9 do 13, włączając w to znak nowej linii,
   poziomą i pionową tabulację itp.).

4. Sprawdzenie znaku Jeśli napotkany zostanie znak '-' lub '+', sprawdzane jest,
   czy liczba jest negatywna czy też pozostaje dodatnia. Jeśli jest to znak
   minusa, neg zostaje przemnożone przez -1. Po sprawdzeniu znaku, indeks i jest
   inkrementowany, aby pominąć ten znak przy dalszym przetwarzaniu.

5. Konwersja znaków na cyfry Następna pętla while jest odpowiedzialna za
   przekształcenie ciągu znaków reprezentujących cyfry (od '0' do '9') na
   rzeczywistą wartość liczbową. Każda cyfra jest przekształcana z char na int
   (przez odjęcie wartości '0'), a następnie dodawana do wyniku po pomnożeniu
   dotychczasowego wyniku przez 10 (przesunięcie miejsca dziesiętnego).
   
6. Zwrócenie wyniku
Wynikowa wartość res jest mnożona przez neg (które może być 1 lub -1 w zależności od znaku liczby) i zwracana jako wynik funkcji.
*/