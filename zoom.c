#include <stdio.h>
#include "lib_ppm.h"

int main()
{
	struct image_s data;
	struct image_s *image = &data;
	struct image_s n_data;
	struct image_s *n_image = &n_data;
	int r;
	int k = 0;
	int m = 0;

	r = read_ppm("lena.ppm", image);

	if (r == 0)
	{
		n_image->width = (image->width * 3);
		n_image->height = (image->height * 3);
		printf("original image -> width: %d, height: %d\n", image->width, image->height);
		printf("upscale image -> width: %d, height: %d\n", n_image->width, n_image->height);
	}

	r = new_ppm(n_image, n_image->width, n_image->height);
	if (r == 0)
	{

		m = 0;
		k = 0;
		for (int i = 0; i < image->height; i++)
		{
			for (int j = 0; j < image->width; j++)
			{
				// set the red colum of the 3x3 pixel matrix
				int red_pixel = image->pix[i * image->width + j].r;
				if (red_pixel < 75) // char
				{
					n_image->pix[k * n_image->width + m].r = 0;
					n_image->pix[(k + 1) * n_image->width + m].r = 0;
					n_image->pix[(k + 2) * n_image->width + m].r = 0;
				}
				else if (red_pixel < 135)
				{
					n_image->pix[k * n_image->width + m].r = 0;
					n_image->pix[(k + 1) * n_image->width + m].r = image->pix[i * image->width + j].r;
					n_image->pix[(k + 2) * n_image->width + m].r = 0;
				}
				else if (red_pixel < 180)
				{
					n_image->pix[k * n_image->width + m].r = image->pix[i * image->width + j].r;
					n_image->pix[(k + 1) * n_image->width + m].r = 0;
					n_image->pix[(k + 2) * n_image->width + m].r = image->pix[i * image->width + j].r;
				}
				else
				{
					n_image->pix[k * n_image->width + m].r = image->pix[i * image->width + j].r;
					n_image->pix[(k + 1) * n_image->width + m].r = image->pix[i * image->width + j].r;
					n_image->pix[(k + 2) * n_image->width + m].r = image->pix[i * image->width + j].r;
				}
				// set the green colum of the 3x3 pixel matrix
				int green_pixel = image->pix[i * image->width + j].g;
				if (green_pixel < 75)
				{
					n_image->pix[k * n_image->width + m + 1].g = 0;
					n_image->pix[(k + 1) * n_image->width + m + 1].g = 0;
					n_image->pix[(k + 2) * n_image->width + m + 1].g = 0;
				}
				else if (green_pixel < 135)
				{
					n_image->pix[k * n_image->width + m + 1].g = 0;
					n_image->pix[(k + 1) * n_image->width + m + 1].g = image->pix[i * image->width + j].g;
					n_image->pix[(k + 2) * n_image->width + m + 1].g = 0;
				}
				else if (green_pixel < 180)
				{
					n_image->pix[k * n_image->width + m + 1].g = image->pix[i * image->width + j].g;
					n_image->pix[(k + 1) * n_image->width + m + 1].g = 0;
					n_image->pix[(k + 2) * n_image->width + m + 1].g = image->pix[i * image->width + j].g;
				}
				else
				{
					n_image->pix[k * n_image->width + m + 1].g = image->pix[i * image->width + j].g;
					n_image->pix[(k + 1) * n_image->width + m + 1].g = image->pix[i * image->width + j].g;
					n_image->pix[(k + 2) * n_image->width + m + 1].g = image->pix[i * image->width + j].g;
				}
				// set the blue colum of the 3x3 pixel matrix
				int blue_pixel = image->pix[i * image->width + j].b;
				if (blue_pixel < 75)
				{
					n_image->pix[k * n_image->width + m + 2].b = 0;
					n_image->pix[(k + 1) * n_image->width + m + 2].b = 0;
					n_image->pix[(k + 2) * n_image->width + m + 2].b = 0;
				}
				else if (blue_pixel < 135)
				{
					n_image->pix[k * n_image->width + m + 2].b = 0;
					n_image->pix[(k + 1) * n_image->width + m + 2].b = image->pix[i * image->width + j].b;
					n_image->pix[(k + 2) * n_image->width + m + 2].b = 0;
				}
				else if (blue_pixel < 180)
				{
					n_image->pix[k * n_image->width + m + 2].b = image->pix[i * image->width + j].b;
					n_image->pix[(k + 1) * n_image->width + m + 2].b = 0;
					n_image->pix[(k + 2) * n_image->width + m + 2].b = image->pix[i * image->width + j].b;
				}
				else
				{
					n_image->pix[k * n_image->width + m + 2].b = image->pix[i * image->width + j].b;
					n_image->pix[(k + 1) * n_image->width + m + 2].b = image->pix[i * image->width + j].b;
					n_image->pix[(k + 2) * n_image->width + m + 2].b = image->pix[i * image->width + j].b;
				}

				m = m + 3;
			}
			m = 0;
			k = k + 3;
		}

		free_ppm(image);
		write_ppm("lena_upssacle.ppm", n_image);
		free_ppm(n_image);
	}

	return 0;
}
