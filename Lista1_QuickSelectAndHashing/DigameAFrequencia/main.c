#include <stdio.h>
#include <string.h>

#define ASCII_SIZE 95 // number of printable ASCII characters

int main()
{
    char line[1005];
    int freq[ASCII_SIZE] = {0}; // array to store the frequency of each ASCII character

    while (fgets(line, sizeof(line), stdin))   // read lines until end of file
    {
        int len = strlen(line);

        for (int i = 0; i < len - 1; i++)   // exclude the newline character at the end
        {
            int index = line[i] - 32; // shift the ASCII value to start at 0
            freq[index]++;
        }

        // find the maximum frequency
        int max_freq = 0;
        for (int i = 0; i < ASCII_SIZE; i++)
        {
            if (freq[i] > max_freq)
            {
                max_freq = freq[i];
            }
        }

        // print characters in ascending order of frequency
        for (int f = 1; f <= max_freq; f++)
        {
            for (int c = 0; c < ASCII_SIZE; c++)
            {
                if (freq[c] == f)
                {
                    printf("%d %d\n", c + 32, freq[c]); // shift back the ASCII value
                }
            }
        }

        memset(freq, 0, sizeof(freq)); // reset frequency array for next line
        printf("\n"); // separate output sets by blank line
    }

    return 0;
}
