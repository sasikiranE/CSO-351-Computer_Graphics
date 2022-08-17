#include <iostream>
#include <math.h>
#include <GL/glut.h>

using namespace std;

float H, K, A, B;

void plot_four_points(float x, float y) {
    glVertex2i(H + x, K + y);  
    glVertex2i(H - x, K + y);  
    glVertex2i(H - x, K - y);  
    glVertex2i(H + x, K - y);  
}

void display(void) {

	float dx, dy, p1, p2, x, y;

	x = 0, y = B;
	
	// for first region.
	p1 = (B * B) - (A * A * B) + (A * A) / 4.0;
	dx = 2 * B * B * x;
	dy = 2 * A * A * y;

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);

	while (dx < dy) {
		plot_four_points(x, y);
		if (p1 < 0) {
			x += 1;
			dx = dx + (2 * B * B);
			p1 = p1 + dx + (B * B);
		}
		else {
			x += 1;
			y -= 1;
			dx = dx + (2 * B * B);
			dy = dy - (2 * A * A);
			p1 = p1 + dx - dy + (B * B);
		}
	}

	// for second region.
	p2 = ((B * B) * ((x + 0.5) * (x + 0.5))) + ((A * A) * ((y - 1) * (y - 1))) - (A * A * B * B);

	while (y >= 0) {
		plot_four_points(x, y);
		if (p2 > 0) {
			y -= 1;
			dy = dy - (2 * A * A);
			p2 = p2 + (A * A) - dy;
		}
		else {
			y -= 1;
			x += 1;
			dx = dx + (2 * B * B);
			dy = dy - (2 * A * A);
			p2 = p2 + dx - dy + (A * A);
		}
	}

	glEnd();
	glFlush();
}

void myInit (void) {
	// Reset background color with black (since all three argument is 0.0)
	glClearColor(1.0, 1.0, 1.0, 1.0);

	// Set picture color to green (in RGB model)
	// as only argument corresponding to G (Green) is 1.0 and rest are 0.0
	glColor3f(0.0, 0.0, 0.0);

	// Set width of point to one unit
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Set window size in X- and Y- direction
	gluOrtho2D(-780, 780, -420, 420);
}

int main(int argc, char **argv) {

    cout << "Enter Circle Center (h, k) : ";
    cin >> H >> K;
    cout << "Enter length of major (a) and minor (b) axes : ";
    cin >> A >> B;

	glutInit(&argc, argv);

	// Display mode which is of RGB (Red Green Blue) type
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// Declares window size
	glutInitWindowSize(960, 540);

	// Declares window position which is (0, 0)
	// means lower left corner will indicate position (0, 0)
	glutInitWindowPosition(0, 0);

	// Name to window
	glutCreateWindow("Ellipse using midpoint algo");

	// Call to myInit()
	myInit();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
