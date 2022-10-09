#include <stdio.h>

int main()
{
	const short dens_dvp = 800, dens_dsp = 650, dens_derevo = 550;
	float h, w, d;
	short shelves_count;
	float size_backwall, size_sidewalls, size_updownwall, size_shelves;

	// Getting data
	printf("Insert h (180-220 cm), w (80-120 cm), d (50-90 cm)");
	scanf("%f %f %f", &h, &w, &d);
	if (h > 220 || h < 180 || w > 120 || w < 80 || d > 90 || d < 50)
	{
		printf("Invalid metrics");
		return 1;
	}
	// Back wall size

}