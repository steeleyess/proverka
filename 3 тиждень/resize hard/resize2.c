// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // збільшувач зображення
    float mnojnik=0;
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }
    mnojnik = atof(argv[1]);
    // перевірка чи введено ціле число
    if(mnojnik==0)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    if(mnojnik>=1&&mnojnik<=100)
    {
        int ichislo = round(mnojnik);
        BITMAPINFOHEADER bii;
        BITMAPFILEHEADER bff;

        bii=bi;
        bii.biHeight=bi.biHeight*ichislo;
        bii.biWidth=bi.biWidth*ichislo;
        int biiHeight = abs(bii.biHeight);

        int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE) % 4)) % 4;
        int padding1 = (4 - (bii.biWidth * sizeof(RGBTRIPLE) % 4)) % 4;

        bii.biSizeImage=(bii.biWidth*biiHeight)*3+padding1*biiHeight;

        bff=bf;
        bff.bfSize=54+bii.biSizeImage;


        // write outfile's BITMAPFILEHEADER
        fwrite(&bff, sizeof(BITMAPFILEHEADER), 1, outptr);

        // write outfile's BITMAPINFOHEADER
        fwrite(&bii, sizeof(BITMAPINFOHEADER), 1, outptr);




        // iterate over infile's scanlines
        for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
        {
            //копірка рядків
            for (int l=0; l<ichislo; l++)
            {
                // iterate over pixels in scanline
                for (int j = 0; j < bi.biWidth; j++)
                {
                    // temporary storage
                    RGBTRIPLE triple;

                    // read RGB triple from infile
                    fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                    // write RGB triple to outfile
                    for(int m=0;m<ichislo;m++)
                    {
                        fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                    }
                }

                // skip over padding, if any
                fseek(inptr, padding, SEEK_CUR);

                // then add it back (to demonstrate how)
                for (int k = 0; k < padding1; k++)
                {
                    fputc(0x00, outptr);
                }
                fseek(inptr, 54+(bi.biWidth*3+padding)*i, SEEK_SET);
            }
            fseek(inptr, 54+(bi.biWidth*3+padding)*(i+1), SEEK_SET);
        }
    }
    else
    {
        if(mnojnik>=0.5&&mnojnik<=1)
        mnojnik=0.5;
        int ichislo = 1/mnojnik;

        BITMAPINFOHEADER bii;
        BITMAPFILEHEADER bff;

        bii=bi;
        bii.biHeight=bi.biHeight*mnojnik;
        bii.biWidth=bi.biWidth*mnojnik;
        int biiHeight = abs(bii.biHeight);

        int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE) % 4)) % 4;
        int padding1 = (4 - (bii.biWidth * sizeof(RGBTRIPLE) % 4)) % 4;

        bii.biSizeImage=(bii.biWidth*biiHeight)*3+padding1*biiHeight;

        bff=bf;
        bff.bfSize=54+bii.biSizeImage;


        // write outfile's BITMAPFILEHEADER
        fwrite(&bff, sizeof(BITMAPFILEHEADER), 1, outptr);

        // write outfile's BITMAPINFOHEADER
        fwrite(&bii, sizeof(BITMAPINFOHEADER), 1, outptr);




        // iterate over infile's scanlines
        for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
        {
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                // write RGB triple to outfile
                if((i+1)%ichislo==0&&(j+1)%ichislo==0)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }

            // skip over padding, if any
            fseek(inptr, padding, SEEK_CUR);
            // then add it back (to demonstrate how)
            if((i+1)%ichislo==0)
            {
                for (int k = 0; k < padding1; k++)
                {
                    fputc(0x00, outptr);
                }
            }
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
