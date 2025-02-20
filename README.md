# Image Channel Interchanger  

## Description  
The **Image Channel Interchanger** is a C program that reads a BMP image and allows the user to interchange the color channels. The user can choose between multiple color channel conversions, such as RGB to BGR, GRB, and more.  

## Features  
- Supports BMP images as input.  
- Allows users to choose from six different color channel mappings.  
- Reads image width and height from the BMP header.  
- Saves the modified image as a new BMP file.  

## Usage  

### Requirements  
- C compiler (e.g., GCC)  
- BMP image file as input  

### Compilation  
```sh
gcc CODE.c -o image_converter
```

### Running the Program  
```sh
./image_converter
```

### Steps  
1. Run the program.  
2. Enter the number corresponding to your desired color conversion:  
   - **1**: RGB to RGB  
   - **2**: RGB to GRB  
   - **3**: RGB to BRG  
   - **4**: RGB to BGR  
   - **5**: RGB to GBR  
   - **6**: RGB to RBG  
3. The program processes the image and saves the output BMP file.  

## Notes  
- The input and output file paths should be specified in the program before execution.  
- Ensure that the BMP file is not compressed, as the program does not support compressed BMP formats.  

## Author  
Harshith  
