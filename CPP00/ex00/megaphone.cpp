
#include <iostream>

int main(int argc, char *argv[])
{
	int	i;
	int	j;

	if (argc > 1)
	{
		for (i = 1; argv[i] != NULL; i++)
		{
			//std::cout << argv[i] << std::endl;
			for (j = 0; argv[i][j] != '\0'; j++)
				std::cout << (char)toupper(argv[i][j]);
			if (argv[i][j + 1] == ' ')
				std::cout << ' ';
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}