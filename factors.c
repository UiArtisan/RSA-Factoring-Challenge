#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <sys/types.h>
#if defined(_WIN32) || defined(_WIN64)
typedef long ssize_t;
#endif

/**
 * main - Entry point.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Return: 0 on success, 1 on error.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return (1);
	}

	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	mpz_t number, p, q;
	FILE *file = fopen(argv[1], "r");

	if (file == NULL)
	{
		printf("File not found!\n");
		return (1);
	}

mpz_inits(number, p, q, NULL);

    while ((read = getline(&line, &len, file)) != -1)
    {
        // Convert line to a GMP integer
        mpz_set_str(number, line, 10);

        int found = 0;

        // Start dividing from 2 to find the factors
        for (mpz_set_ui(p, 2); mpz_cmp(p, number) < 0; mpz_add_ui(p, p, 1))
        {
            if (mpz_divisible_p(number, p) != 0)
            {
                mpz_cdiv_q(q, number, p);  // Calculate q = number / p

                // Ensure the larger factor is printed first
                if (mpz_cmp(p, q) > 0)
                {
                    gmp_printf("%Zd=%Zd*%Zd\n", number, p, q);
                }
                else
                {
                    gmp_printf("%Zd=%Zd*%Zd\n", number, q, p);
                }

                found = 1;
                break;  // Stop after finding the first factor pair
            }
        }

        // In case no factors are found (should not happen with valid inputs)
        if (!found)
        {
            gmp_printf("%Zd is a prime number or could not be factorized\n", number);
        }
    }

    if (line != NULL)
        free(line);
    mpz_clears(number, p, q, NULL);
    fclose(file);
    return (0);
}
