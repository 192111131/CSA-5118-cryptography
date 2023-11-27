#include <stdio.h>
#include <string.h>
#define SIZE 5
void prepareKey(char *key, char matrix[SIZE][SIZE]) 
{
    int i, j, k = 0;
    int exists[26] = {0};
    for (i = 0; i<strlen(key); i++) 
	{
        if (key[i] == 'j')
            key[i] = 'i';
        if (!exists[key[i] - 'A']) 
		{
            matrix[k / SIZE][k % SIZE] = key[i];
            exists[key[i] - 'A'] = 1;
            k++;
        }
    }
    for (i = 0; i < 26; i++) 
	{
        if (i != ('J' - 'A') && !exists[i]) 
		{
            matrix[k / SIZE][k % SIZE] = 'A' + i;
            k++;
        }
    }
}
void encryptPair(char matrix[SIZE][SIZE], char a, char b) 
{
    int i, j, r1, c1, r2, c2;
    for (i = 0; i < SIZE; i++) 
	{
        for (j = 0; j < SIZE; j++) 
		{
            if (matrix[i][j] == a) 
			{
                r1 = i;
                c1 = j;
            }
            if (matrix[i][j] == b) 
			{
                r2 = i;
                c2 = j;
            }
        }
    }
    if (r1 == r2) 
	{
        c1 = (c1 + 1) % SIZE;
        c2 = (c2 + 1) % SIZE;
    } 
	else if (c1 == c2) 
	{
        r1 = (r1 + 1) % SIZE;
        r2 = (r2 + 1) % SIZE;
    } 
	else 
	{
        int temp = c1;
        c1 = c2;
        c2 = temp;
    }
	printf("%c%c%c%c", matrix[r1][c1], matrix[r2][c2]);
}
void playfairEncrypt(char matrix[SIZE][SIZE], char *input) 
{
    int i;
	for (i = 0; i < strlen(input); i += 2) 
	{
        char a = input[i];
        char b = (i + 1 < strlen(input)) ? input[i + 1] : 'X';
        encryptPair(matrix, a, b);
    }
	printf("\n");
}
int main()
{
    char key[] = "MONKEY";
    char plaintext[] = "EDUCATION";
    char matrix[SIZE][SIZE];
	prepareKey(key, matrix);
	printf("Playfair Matrix:\n");
    for (int i = 0; i < SIZE; i++) 
	{
        for (int j = 0; j < SIZE; j++) 
		{
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("Plaintext: %s\n", plaintext);
    printf("Encrypted: ");
    playfairEncrypt(matrix, plaintext);
	return 0;
}
