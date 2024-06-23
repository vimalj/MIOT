#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	int buttonVal, oldButtonVal = 0;

	FILE *fp; 

	while(1)
	{
		//printf("Reading button...\n");
		
		fp = fopen("/sys/class/gpio/gpio60/value", "r+");
		fscanf(fp, "%i", &buttonVal);
		fclose(fp);
		
		if(buttonVal != oldButtonVal)
		{
			printf("buttonVal: %i\n", buttonVal);
		}

		oldButtonVal = buttonVal;

		usleep(100000);
	}	
	
	return 0;
}
