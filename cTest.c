#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	FILE *fp;
	unsigned long int i, len = 0;
	int read;
	char *ptr, *line;
	unsigned long int factor1 = 0, factor2 = 0, num;

	if (argc != 2)
			return (-1);

	fp = fopen(argv[1], "r");
	/*printf("opened file");*/
	if (fp == NULL)
		return (-1);

	while ((read = getline(&line, &len, fp)) != -1)
	{
		num = strtoul(line, &ptr, 10);
		/*printf("made it to loop");*/
		if (num == 0)
			return (-1);

		for (i = 2; i <= num / 2; i++)
		{
			if (num % i == 0)
			{
				factor1 = num / i;
				factor2 = i;
				break;
			}
		}

		if (factor1 == 0 && factor2 == 0)
			printf("%lu has no factors\n", num);
		else
			printf("%lu=%lu*%lu\n", num, factor1, factor2);
	
		factor1 = 0;
		factor2 = 0;
	}

	fclose(fp);
    if (line)
        free(line);
	return (0);
}
