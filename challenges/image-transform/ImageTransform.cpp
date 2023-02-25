#include <iostream>
#include <cmath>
#include <cstdlib>

#include "uiuc/PNG.h"
#include "uiuc/HSLAPixel.h"
#include "ImageTransform.h"

/* ******************
   (Begin multi-line comment...)

   Write your name and email address in the comment space here:

Name:
Email:

(...end multi-line comment.)
 ******************** */

using uiuc::PNG;
using uiuc::HSLAPixel;

/**
 * Returns an image that has been transformed to grayscale.
 *
 * The saturation of every pixel is set to 0, removing any color.
 *
 * @return The grayscale image.
 */

const double ILLINI_BLUE = 216.0;
const double ILLINI_ORANGE = 11.0;

int exponentiation(int a,int b) {
    if (b == 1)
        return a;
    if ( b % 2 == 1)
        return a * exponentiation(a, b - 1);
    int tmp_exp = exponentiation(a, b / 2);
    return tmp_exp * tmp_exp;
}

PNG grayscale(PNG image) {
    /// This function is already written for you so you can see how to
    /// interact with our PNG class.
    for (unsigned x = 0; x < image.width(); x++) {
        for (unsigned y = 0; y < image.height(); y++) {
            HSLAPixel & pixel = image.getPixel(x, y);

            // `pixel` is a reference to the memory stored inside of the PNG `image`,
            // which means you're changing the image directly. No need to `set`
            // the pixel since you're directly changing the memory of the image.
            pixel.s = 0;
        }
    }

    return image;
}



/**
 * Returns an image with a spotlight centered at (`centerX`, `centerY`).
 *
 * A spotlight adjusts the luminance of a pixel based on the distance the pixel
 * is away from the center by decreasing the luminance by 0.5% per 1 pixel euclidean
 * distance away from the center.
 *
 * For example, a pixel 3 pixels above and 4 pixels to the right of the center
 * is a total of `sqrt((3 * 3) + (4 * 4)) = sqrt(25) = 5` pixels away and
 * its luminance is decreased by 2.5% (0.975x its original value).  At a
 * distance over 160 pixels away, the luminance will always decreased by 80%.
 * 
 * The modified PNG is then returned.
 *
 * @param image A PNG object which holds the image data to be modified.
 * @param centerX The center x coordinate of the crosshair which is to be drawn.
 * @param centerY The center y coordinate of the crosshair which is to be drawn.
 *
 * @return The image with a spotlight.
 */
PNG createSpotlight(PNG image, int centerX, int centerY) {
    for (unsigned x = 0; x < image.width(); x++) {
        for (unsigned y = 0; y < image.height(); y++) {
            HSLAPixel & pixel = image.getPixel(x, y);
            int x_2 = abs(int(centerX - x));
            int y_2 = abs(int(centerY - y));
            // cout << "x: " << x << endl;
            // cout << "y: " << y << endl;
            // cout << "x_2: " << x_2 << endl;
            // cout << "y_2: " << y_2 << endl;
            // double pow_x = (double)x_2 * x_2;
            // double pow_y = (double)y_2 * y_2;
            // double pow_x = pow(x_2,2);
            // double pow_x = pow(x_2,2);
            // int pow_x = exponentiation(x_2,2);
            // int pow_y = exponentiation(y_2,2);
            int pow_x = pow(x_2,2);
            int pow_y = pow(y_2,2);
            // cout << "pow_x: " << pow_x << endl;
            // cout << "pow_y: " << pow_y << endl;
            double distance = (double)sqrt((pow_x)+(pow_y));
            // cout << x_2 << "^2 - " << y_2 << "^2" << " = " << distance << endl;;
            // cout << "(" << centerX << " - " << x << ")^2 + " << "(" << centerY 
            //     << " - " << y << ")^2 = " << distance <<  endl;
            double per_dec = (double)(distance * 0.005);
            double per_inv = (double)1.000 - per_dec;
            // cout << "distance: " << distance << endl;
            // cout << "per_dec: " << per_dec << endl;
            // cout << "per_inv: " << per_inv << endl;
            if(distance > 160){
                pixel.l *= 0.2;
                // cout << "over 160px: pixel.l -> " << pixel.l << endl;
            }else{
                pixel.l *= per_inv;
                // cout << "pixel.l *= per_inv -> " << pixel.l << endl; 
            }
        }
    }

    return image;
}


/**
 * Returns a image transformed to Illini colors.
 *
 * The hue of every pixel is set to the a hue value of either orange or
 * blue, based on if the pixel's hue value is closer to orange than blue.
 *
 * @param image A PNG object which holds the image data to be modified.
 *
 * @return The illinify'd image.
 **/
PNG illinify(PNG image) {


    for (unsigned x = 0; x < image.width(); x++) {
        for (unsigned y = 0; y < image.height(); y++) {
            HSLAPixel & pixel = image.getPixel(x, y);
            // `pixel` is a reference to the memory stored inside of the PNG `image`,
            // which means you're changing the image directly. No need to `set`
            // the pixel since you're directly changing the memory of the image.
            double hue = pixel.h;
            // take the short way round in the circle
            double f_oj = (double)min(abs(hue - ILLINI_ORANGE), 360 - abs(hue - ILLINI_ORANGE)); 
            double f_blue = (double)min(abs(hue - ILLINI_BLUE), 360 - abs(hue- ILLINI_BLUE)); 
            // if(f_oj < f_blue)
            //     pixel.h = ILLINI_ORANGE;
            // else
            //     pixel.h = ILLINI_BLUE;
            pixel.h = (f_oj < f_blue ) ? ILLINI_ORANGE : ILLINI_BLUE;
        }
    }

    return image;
}


/**
 * Returns an immge that has been watermarked by another image.
 *
 * The luminance of every pixel of the second image is checked, if that
 * pixel's luminance is 1 (100%), then the pixel at the same location on
 * the first image has its luminance increased by 0.2.
 *
 * @param firstImage  The first of the two PNGs, which is the base image.
 * @param secondImage The second of the two PNGs, which acts as the stencil.
 *
 * @return The watermarked image.
 */
PNG watermark(PNG firstImage, PNG secondImage) {
    
    for (unsigned x = 0; x < secondImage.width(); x++) {
        for (unsigned y = 0; y < secondImage.height(); y++) {
            HSLAPixel & base_img_pixel = firstImage.getPixel(x, y);
            HSLAPixel & stencil_img_pixel = secondImage.getPixel(x, y);
            double lum = base_img_pixel.l;
            if(stencil_img_pixel.l == 1.0){
                double check_lum = lum + 0.2;
                if(check_lum >= 1.0)
                    base_img_pixel.l = 1.0;
                else
                    base_img_pixel.l += 0.2;
            }
        }
    }

    return firstImage;
}
