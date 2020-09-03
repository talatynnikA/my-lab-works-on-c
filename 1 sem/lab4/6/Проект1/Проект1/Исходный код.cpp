#include <iostream>
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int k;
	puts("vy lubite chitat? (1-da, 2-net)");
	std::cin >> k;
	switch (k)
	{
	case 1: { puts("Kakiye knigi vy lyubite bol'she? (1- Detektivy, 2-Romany, 3- Fentezi)");
		std::cin >> k;
		
		switch (k)
		{
		case 1: puts("Mogu posovetovat' vam Detektivnyy roman Agaty Kristi, Desyat' negrityat"); break;
		case 2: puts("Vam mozhet ponravitsya Gordost' i predubezhdeniye – shedevr angliyskoy literatury, napisannyy Dzheyn Osten"); break;
		case 3: puts("Korol' voronov Meggi Stivotera - otlichnaya kniga v svoyem zhanre");
			
		}
		break;
		
	}
	case 2: puts("ochen' zhal'"); break;
	default: puts("Nekorrektnyy variant"); break;
	}

	system("pause");
}
