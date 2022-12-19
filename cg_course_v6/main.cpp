#include "../libwinbgi/src/graphics.h"
#include <stdio.h>
#include "cube.h"
#include "polygon.h"
#include "prism.h"

// USE_MY_COOL_FEATURE

int main()
{

	cube* Cube = new cube();
	Cube->move(250, 400, -40);
	Cube->scale(0.5, 0.5, 0.5);

	prism* Prism = new prism();
	Prism->move(350, 400, -40);
	

	initwindow(1000, 700);
	Cube->paint();
	Prism->paint();
	
	char c;
	while (true)
	{
		c = getch();
		switch (c)
		{
		case 'u':
			Prism->move(0, -40, 0);
			break;
		case 'j':
			Prism->move(0, 40, 0);
			break;
		case 'h':
			Prism->move(-40, 0, 0);
			break;
		case 'k':
			Prism->move(40, 0, 0);
			break;
		case 'n':
			Prism->move(0, 0, 40);
			break;
		case 'm':
			Prism->move(0, 0, -40);
			break;

		case 'y':
			Prism->scale(0.5, 0.5, 0.5);
			break;
		case 'i':
			Prism->scale(2, 2, 2);
			break;
		case '7':
			Prism->rotate(30, 0);
			break;
		case '8':
			Prism->rotate(-30, 0);
			break;
		case '9':
			Prism->rotate(30, 1);
			break;
		case '0':
			Prism->rotate(-30, 1);
			break;
		case '-':
			Prism->rotate(30, 2);
			break;
		case '=':
			Prism->rotate(-30, 2);
			break;

		case '~':
			closegraph();
			return 0;

		case 'w':
			Cube->move(0, -40, 0);
			break;
		case 's':
			Cube->move(0, 40, 0);
			break;
		case 'a':
			Cube->move(-40, 0, 0);
			break;
		case 'd':
			Cube->move(40, 0, 0);
			break;
		case 'z':
			Cube->move(0, 0, 40);
			break;
		case 'x':
			Cube->move(0, 0, -40);
			break;

		case 'q':
			Cube->scale(0.5, 0.5, 0.5);
			break;
		case 'e':
			Cube->scale(2, 2, 2);
			break;
		case '1':
			Cube->rotate(30, 0);
			break;
		case '2':
			Cube->rotate(-30, 0);
			break;
		case '3':
			Cube->rotate(30, 1);
			break;
		case '4':
			Cube->rotate(-30, 1);
			break;
		case '5':
			Cube->rotate(30, 2);
			break;
		case '6':
			Cube->rotate(-30, 2);
			break;
		default:
			break;
		}
		
		
		clearviewport();
		Cube->paint();
		Prism->paint();

	}

	getch();
	closegraph();
	return 0;
}


