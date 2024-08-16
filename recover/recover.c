#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Verify arguments (must be one argument in a line of code)
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    // Open image and verifies if its open correctly
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 1;
    }

    // Variables
    FILE *img = NULL;
    BYTE buffer[512];
    char filename[8];
    int file_count = 0;
    int found_jpeg = 0;

    // Read 512 bytes at a time
    while (fread(buffer, sizeof(BYTE), 512, file) == 512)
    {
        // Check if its the start of a new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // If already found a jpeg, close the previous one
            if (found_jpeg == 1)
            {
                fclose(img);
            }
            else
            {
                found_jpeg = 1;
            }

            // Open a new file for writing
            sprintf(filename, "%03i.jpg", file_count++);
            img = fopen(filename, "w");
            if (img == NULL)
            {
                fprintf(stderr, "Could not create %s.\n", filename);
                return 1;
            }
        }

        // If a jpeg file is found, write to the file
        if (found_jpeg == 1)
        {
            fwrite(buffer, sizeof(BYTE), 512, img);
        }
    }

    // Close any other files
    if (img != NULL)
    {
        fclose(img);
    }

    fclose(file);
    return 0;
}
