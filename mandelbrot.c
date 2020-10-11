#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

int main(){
	printf("\n\n\n\tStart Simulation? <<---\n\tExit?\n");
	getchar();
	char b[1997] = {0}; // setting up CHAR array
	double T = -1.280886813852703198790550231933625, W = 0.436655189099076576530933380126953125; // (r;i) coordinates for zoom focus
	//double T = -1.7885036468505859375, W = -0.02143096923828125; //(r;i) for minibrot
	float f = 0.125;
	

	for(float c = 1.0; c < powf(2, 42); c += f){ /* at 2^18 mandelbrotSIM breaks down*/
		int o = 0, j = 0, l = 0;
		f *= 1.0625;
		for (double y = (W+(3.375/c)); y >= (W-(3.375/c)); y -= (0.28125/c)){
			//printf("\n"); // use if you want choppy animations but everywhere
			for (double x = (T-(9/c)); x <= (T+(4.5/c)); x += (0.1703125/c)){
				double r = x;
				double i = y;
				
				for(j = 0; j < 42; j++){ //mandelbrot math
					double z = r*r - i*i;
					i = 2*r*i;
					r = z+x; /*x^2 - y^2 + 2xyi*/
					i += y;
					
					if(r > 2 || i < -2 || r < -2 || i > 2){
					break;}
				}
				b[o] = " .,-~%=-+*<!72&@#-,>I%nqMK*=~,.%*2&qn<=~-,K"[j > 0 ? j : 0];
				o += 1; //otherwise use " .,-~=+|<!*%e$@&#-,>I%nqM" nd 17, or keep 11 and " .,-~:;=!*$@"
				if(o > 1995){
					printf("\n%s", b);
					getchar();
					usleep(170000);
					l = 1;
				break;}
			}
			if(l != 0){
			break;}
		}
	}
	printf("\n\nhere is where the DEMO ends, please buy the ZOOM_dlc for more zoomage fun x3");
	getchar();
	return 0;	
}
