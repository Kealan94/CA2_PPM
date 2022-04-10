//Created by kealan crilly on 05/04/2022.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "Image.h"
#include <string>

bool Image::load(string filename) {

    //Code to make the PPM file
    const int W = 320;
    const int H = 256;
    std::ofstream fout("output.ppm");
    if (fout.fail()) return -1; // error
    fout << "P6\n";
    fout << W << " " << H << "\n";
    fout << "255\n";
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            fout << (rand() % 256) << " ";//red
            fout << (rand() % 256) << " ";//green
            fout << (rand() % 256) << " ";//blue
        }
        fout.close();
    }
    std::ifstream ifs;

        ifs.open("output.ppm", std::ios::binary);
        // need to spec. binary mode for Windows users
        Image Img;
        try {
            if (ifs.fail()) {
                throw ("Can't open input file");
            }
            std::string header;
            int w, h;
            ifs >> header;
            if (strcmp(header.c_str(), "P6") != 1) throw ("Can't read input file");
            ifs >> w >> h;
            Img.w = w;
            Img.h = h;

            // Img.pixels = new Image::Rgb[w * h]; // this is throw an exception if bad_alloc
            ifs.ignore(256, '\n'); // skip empty lines in necessary until we get to the binary data
            unsigned char pix[3]; // read each pixel one by one and convert bytes to floats
            for (int i = 0; i < w * h; ++i) {
                ifs.read(reinterpret_cast<char *>(pix), 3);
                Img.pixels[i].r = pix[0] / 255.f;
                Img.pixels[i].g = pix[1] / 255.f;
                Img.pixels[i].b = pix[2] / 255.f;
            }
            ifs.close();
        }
        catch (const char *err) {
            fprintf(stderr, "%s\n", err);
            ifs.close();
        }
        return false;
    }

bool Image::loadRaw(string filename)
{
    return false;
}
bool Image::savePPM(string filename) {
Image img;
        if (img.w == 0 || img.h == 0) { fprintf(stderr, "Can't save an empty image\n");
        }

        std::ofstream ofs;
        try {
            ofs.open("output.ppm", std::ios::binary);
            if (ofs.fail()) throw("Can't open output file");
            ofs << "P6\n" << img.w << " " << img.h << "\n255\n";
            unsigned char r, g, b;
            // loop over each pixel in the image, clamp and convert to byte format
            for (int i = 0; i < img.w * img.h; ++i) {
                ofs << r << g << b;
            }
            ofs.close();
        }
        catch (const char *err) {
            fprintf(stderr, "%s\n", err);
            ofs.close();
        }
    return false;
}

void Image::filterRed()
{

}
void Image::filterGreen()
{

}
void Image::filterBlue()
{

}
void Image::greyScale()
{

}
void Image::flipHorizontal()
{


}
void Image::flipVertically()
{


}
void Image::AdditionalFunction2()
{

}
void Image::AdditionalFunction3()
{

}
void Image::AdditionalFunction1()
{

}

/* Functions used by the GUI - DO NOT MODIFY */
int Image::getWidth()
{
    return w;
}

int Image::getHeight()
{
    return h;
}

Rgb* Image::getImage()
{
    return pixels;
}