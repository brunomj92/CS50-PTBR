#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define BLOCK_SIZE 512

typedef uint8_t  BYTE;

int main(int argc, char *argv[])
{
    // Ensure proper usage: um argumento de linha de comando
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    // Open input file
    char *file = argv[1];
    FILE *raw_file = fopen(file, "r");

    if (raw_file == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", file);
        return 1;
    }

    bool found_jpg = false;
    int count = 0;
    BYTE buffer[BLOCK_SIZE];
    char filename[8];
    FILE *img = NULL; //outptr, pointer to the current JPEG file
    while (fread(buffer, BLOCK_SIZE, 1, raw_file) == 1)
    {
        // Ensure infile is (likely) a JPEG file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) //new block, new file
        {
            if (found_jpg)
            {
                fclose(img);
            }
            else
            {
                found_jpg = true;
            }
            //open a new JPEG
            sprintf(filename, "%03i.jpg", count);
            img = fopen(filename, "w");
            if (img == NULL)
            {
                fclose(raw_file);
                fprintf(stderr, "Could not create %s.\n", filename);
                return 3;
            }
            count++;
        }
        if (found_jpg)
        {
            fwrite(buffer, BLOCK_SIZE, 1, img); // write 512 bytes until a new JPEG is found
        }
    }
    //stop at end of file
    // Close infile
    fclose(raw_file);
    // Close outfile if there is one
    if (found_jpg)
    {
        fclose(img);
    }
    return 0;
}
