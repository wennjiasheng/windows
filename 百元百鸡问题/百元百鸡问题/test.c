#include<stdio.h>

int main()
{
	int x, y, z;
	for (x = 1; x < 120; x++)
	{
		for (y = 1; y < 120; y++)
		{
			for (z = 1; z < 120; z++)
			{
				if ((x + y + z == 120) && (x  + 4 * y + 6 * z == 300)&&(y>z))
					printf("\n x= %d  y=%d  z=%d", x, y, z);
			}
		}
		
	}
	system("pause");
	return 0;
}