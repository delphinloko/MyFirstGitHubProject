#include <stdio.h>

#define BUF_SIZE 512

int main()
{
    FILE *rawFile = fopen("card.raw", "r");
    if (!rawFile) {
        printf("Could not open \"card.raw\".\n");
        return 1;
    }

    FILE *jpgFile = NULL;
    char jpgName[8];
    unsigned char jpgID = 0;
    unsigned char buf[BUF_SIZE];

    while (fread(buf, BUF_SIZE, 1, rawFile)) {
        if (buf[0] == 0xFF && buf[1] == 0xD8 && buf[2] == 0xFF) {
            if (jpgFile)
                fclose(jpgFile);

            sprintf(jpgName, "%03d.jpg", jpgID);
            jpgID++;

            jpgFile = fopen(jpgName, "w");
            if (!jpgFile) {
                printf("Could not create \"%s\".\n", jpgName);
                fclose(rawFile);
                return 2;
            }
        }

        if (jpgFile)
            fwrite(buf, BUF_SIZE, 1, jpgFile);
    }

    fclose(jpgFile);
    fclose(rawFile);
    return 0;
}