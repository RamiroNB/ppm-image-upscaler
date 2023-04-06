#include <stdio.h>
#include "lib_ppm.h"

int main(){
	struct image_s data;
	struct image_s *image = &data;
	struct image_s n_data;
	struct image_s *n_image = &n_data;
	int i, j, r;
	int k, m = 0;

	r = read_ppm("lena.ppm", image);

	if (r == 0){
		n_image->width=(image->width*3);
		n_image->height=(image->width*3);
		printf("original image -> width: %d, height: %d\n", image->width, image->height);
		printf("upscale image -> width: %d, height: %d\n", n_image->width, n_image->height);

		for (j = 0; j < image->height; j++){
			for (i = 0; i < image->width; i++){
				// printf("(%d %d) %02x %02x %02x\n", i, j,
				// 	   image->pix[j * image->width + i].r,
				// 	   image->pix[j * image->width + i].g,
				// 	   image->pix[j * image->width + i].b);
				//pegar um pixel e upscale pra matrix 3x3
				image->pix[j * image->width + i].r;
				image->pix[j * image->width + i].g;
				image->pix[j * image->width + i].b;
				
				if(image->pix[j * image->width + i].r<75){

				}else if(image->pix[j * image->width + i].r<135){
					
				}else if(image->pix[j * image->width + i].r<180){

				}else{
					
				}

			}
		}

		image->pix[50 * image->width + 20].r = 255;
		image->pix[50 * image->width + 20].g = 255;
		image->pix[50 * image->width + 20].b = 255;

		//write_ppm("lena_copy.ppm", image);
		write_ppm("lena_upssacle.ppm", image);
		free_ppm(image);
	}

	// r = new_ppm(image, 675, 428);

	// if (r == 0){
	// 	image->pix[100 * image->width + 125].r = 255;
	// 	image->pix[27 * image->width + 440].g = 255;

	// 	image->pix[371 * image->width + 10].r = 192;
	// 	image->pix[371 * image->width + 10].g = 192;
	// 	image->pix[371 * image->width + 10].b = 192;

	// 	write_ppm("test.ppm", image);
	// 	free_ppm(image);
	// }

	return 0;
}
