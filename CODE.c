/*
 * Image Channel Interchanger
 * This program reads a BMP image and interchanges the color channels
 * based on the user's choice. Supported conversions include RGB to various other orders like BGR, GRB, etc.
 *
 * Usage:
 * 1. Input a valid BMP image file.
 * 2. Select an option for the channel conversion.
 * 3. The output will be a new BMP file with modified color channels.
 *
 * Author: Harshith
 */

#include <stdio.h>
#include <stdlib.h>  // For exit function

int main() {
    unsigned char r, g, b;
    int choice;
    FILE *input_file, *output_file;
    unsigned char header[54];

    // Prompt user for channel conversion choice
    printf("Enter the choice for channel interchange:\n");
    printf("1. RGB to RGB\n2. RGB to GRB\n3. RGB to BRG\n4. RGB to BGR\n5. RGB to GBR\n6. RGB to RBG\n");
    scanf("%d", &choice);

    // Open input and output files
    input_file = fopen("ENTER THE PATH OF YOUR INPUT FILE", "rb");
    if (input_file == NULL) {
        printf("Error: Unable to open input file!\n");
        exit(1);
    }
    output_file = fopen("ENTER THE PATH OF YOUR OUTPUT FILE", "wb+");
    if (output_file == NULL) {
        printf("Error: Unable to open output file!\n");
        fclose(input_file);
        exit(1);
    }

    // Read the BMP header (54 bytes)
    fread(header, sizeof(unsigned char), 54, input_file);
    fwrite(header, sizeof(unsigned char), 54, output_file);

    // Extract width and height from the BMP header
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    printf("Image Width: %d\n", width);
    printf("Image Height: %d\n", height);

    // Validate choice
    if (choice < 1 || choice > 6) {
        printf("Invalid choice! Please enter a value between 1 and 6.\n");
        fclose(input_file);
        fclose(output_file);
        exit(1);
    }

    // Process image pixels
    for (int i = 0; i < height * width; i++) {
        r = fgetc(input_file);
        g = fgetc(input_file);
        b = fgetc(input_file);

        // Write pixels to output based on user choice
        switch (choice) {
            case 1:  // RGB to RGB
                fputc(r, output_file);
                fputc(g, output_file);
                fputc(b, output_file);
                break;
            case 2:  // RGB to GRB
                fputc(r, output_file);
                fputc(b, output_file);
                fputc(g, output_file);
                break;
            case 3:  // RGB to BRG
                fputc(b, output_file);
                fputc(r, output_file);
                fputc(g, output_file);
                break;
            case 4:  // RGB to BGR
                fputc(b, output_file);
                fputc(g, output_file);
                fputc(r, output_file);
                break;
            case 5:  // RGB to GBR
                fputc(g, output_file);
                fputc(b, output_file);
                fputc(r, output_file);
                break;
            case 6:  // RGB to RBG
                fputc(g, output_file);
                fputc(r, output_file);
                fputc(b, output_file);
                break;
        }
    }

    // Close the files
    fclose(input_file);
    fclose(output_file);

    printf("Image processing completed.\n");

    return 0;
}
