//从.raw文件中恢复.jpg图片，接受命令行参数

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage:./recover input.raw\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];
    char filename[8];
    FILE *img = NULL;
    int cnt = 0;

    // Repeat to read 512 bytes to a buffer
    while (fread(&buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        // Check start of new JPEG
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0))
        {
            if (cnt != 0)
            {
                fclose(img);
            }

            // Generate JPEG file
            sprintf(filename, "%03i.jpg", cnt);
            img = fopen(filename, "w");
            cnt++;
        }

        // Already found JPEG
        if (cnt != 0)
        {
            fwrite(&buffer, 1, BLOCK_SIZE, img);
        }
    }

    fclose(file);
    fclose(img);
    return 0;
}
