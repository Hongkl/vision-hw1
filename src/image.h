#ifndef IMAGE_H
#define IMAGE_H

// DO NOT CHANGE THIS FILE

typedef struct{
    int w,h,c;
    float *data;
} image;


// Basic operations
float get_pixel(image im, int x, int y, int c);
void set_pixel(image im, int x, int y, int c, float v);
image copy_image(image im);
image rgb_to_grayscale(image im);
image grayscale_to_rgb(image im, float r, float g, float b);
void rgb_to_hsv(image im);
void hsv_to_rgb(image im);
void shift_image(image im, int c, float v);
void scale_image(image im, int c, float v);
void clamp_image(image im);
image get_channel(image im, int c);
int same_image(image a, image b);
image sub_image(image a, image b);
image add_image(image a, image b);


// Loading and saving
image make_image(int w, int h, int c);
image load_image(char *filename);
void save_image(image im, const char *name);
void save_png(image im, const char *name);
void free_image(image im);

// Resizing
float nn_interpolate(image im, float x, float y, int c);
image nn_resize(image im, int w, int h);
float bilinear_interpolate(image im, float x, float y, int c);
image bilinear_resize(image im, int w, int h);

// Filtering
image convolve_image(image im, image filter, int preserve);
image make_box_filter(int w);
image make_highpass_filter();
image make_sharpen_filter();
image make_emboss_filter();
image make_gaussian_filter(float sigma);
void feature_normalize(image im);
void threshold_image(image im, float thresh);
void pow_image(image im, float s);
void minimum_image(image im, float thresh);

#endif

