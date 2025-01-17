// C Implementation for drawing ellipse 
#include <graphics.h> 

int main() 
{ 
	// gm is Graphics mode which is a computer display 
	// mode that generates image using pixels. 
	// DETECT is a macro defined in "graphics.h" header file 
	 int gd = DETECT, gm;
    const char* data = "C:\\MinGW\\lib\\libbgi.a"; // Path to your BGI file

    // Initialize the graphics system
    initgraph(&gd, &gm, (char*)data);

	// location of ellipse 
	int x = 250, y = 200; 

	// here is the starting angle 
	// and end angle 
	int start_angle = 0; 
	int end_angle = 360; 

	// radius from x axis and y axis 
	int x_rad = 100; 
	int y_rad = 50; 


	// ellipse function 
	ellipse(x, y, start_angle, 
	end_angle, x_rad, y_rad); 

	getch(); 

	// closegraph function closes the graphics 
	// mode and deallocates all memory allocated 
	// by graphics system . 
	closegraph(); 

	return 0; 
} 
