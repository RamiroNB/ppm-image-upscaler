#include <stdio.h>
#include "lib_ppm.h"

int main()
{
	struct image_s data;
	struct image_s *image = &data;
	struct image_s n_data;
	struct image_s *n_image = &n_data;
	int i, j, r;
	int k = 0;
	int m = 0;

	r = read_ppm("lena.ppm", image);

	if (r == 0)
	{
		n_image->width = (image->width * 3);
		n_image->height = (image->height * 3);
		printf("original image -> width: %d, height: %d\n", image->width, image->height);
		printf("upscale image -> width: %d, height: %d\n", n_image->width, n_image->height);
		free_ppm(image);
	}

	r = new_ppm(n_image, n_image->width, n_image->height);
	if (r == 0)
	{

		m = 0;
		k = 0;
		for (int o = 0; o < image->height; o++)
		{
			for (int h = 0; h < image->width; h++)
			{
				// n_image->pix[k * n_image->width + m].r = 255;
				// n_image->pix[(k + 1) * n_image->width + m].r = 255;
				// n_image->pix[(k + 2) * n_image->width + m].r = 255;
				// n_image->pix[k * n_image->width + m + 1].g = 255;
				// n_image->pix[(k + 1) * n_image->width + m + 1].g = 255;
				// n_image->pix[(k + 2) * n_image->width + m + 1].g = 255;
				// n_image->pix[k * n_image->width + m + 2].b = 255;
				// n_image->pix[(k + 1) * n_image->width + m + 2].b = 255;
				// n_image->pix[(k + 2) * n_image->width + m + 2].b = 255;

				// set the red colum of the 3x3 pixel matrix
				if (image->pix[i * image->width + j].r < 75)
				{
					n_image->pix[k * n_image->width + m].r = 0;
					n_image->pix[(k + 1) * n_image->width + m].r = 0;
					n_image->pix[(k + 2) * n_image->width + m].r = 0;
				}
				else if (image->pix[i * image->width + j].r < 135)
				{
				}
				else if (image->pix[i * image->width + j].r < 180)
				{
				}
				else
				{
				}
				// set the green colum of the 3x3 pixel matrix

				// set the blue colum of the 3x3 pixel matrix

				m = m + 3;
			}
			m = 0;
			k = k + 3;
		}

		n_image->pix[1535 * n_image->width + 1535].r = 0;
		n_image->pix[1535 * n_image->width + 1535].g = 255;
		n_image->pix[1535 * n_image->width + 1535].b = 0;
		write_ppm("lena_upssacle.ppm", n_image);
		free_ppm(n_image);
	}

	return 0;
}
