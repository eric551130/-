
#include <cmath>

#include <GL/glut.h>

int mx = 0, my = 0;
void fnt();
void box(float x, float y, float z);
void normal(float n[], float p0[], float p1[], float p2[]);
void rectangle(float w, float h);
void mouseMove(int x, int y) {
	mx = x;
	my = y;
	glutPostRedisplay();
}
void hemiSphere(GLfloat fRadius, GLint iSlices, GLint iStacks);


void init(void)
{
	GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat position[] = { 0.0, 3.0, 3.0, 0.0 };

	GLfloat lmodel_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat local_view[] = { 0.0 };
	glClearColor(0.50f, 0.50f, 0.50f, 0.0f);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_DEPTH_TEST);

}


void render(GLfloat ambr, GLfloat ambg, GLfloat ambb,
	GLfloat difr, GLfloat difg, GLfloat difb,
	GLfloat specr, GLfloat specg, GLfloat specb, GLfloat shine)
{
	GLfloat mat[4];



	mat[0] = ambr; mat[1] = ambg; mat[2] = ambb; mat[3] = 1.0;
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
	mat[0] = difr; mat[1] = difg; mat[2] = difb;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
	mat[0] = specr; mat[1] = specg; mat[2] = specb;
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
	glMaterialf(GL_FRONT, GL_SHININESS, shine * 128.0);

}


void display(void)
{	
	GLUquadricObj* q;// Create a pointer to Quadric
	q = gluNewQuadric();// Create a new quadratic

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glClearDepth(1.0f);                     // Depth buffer setup
	glEnable(GL_DEPTH_TEST);                // Enables depth testing
	glTranslatef(0.0, 0.0, -46.0);
	glRotatef(mx, 0.0f, 1.0f, 0.0f);
	glRotatef(my, 1.0f, 0.0f, 0.0f);


	render(0.0215, 0.1745, 0.0215,
		0.07568, 0.61424, 0.07568, 0.633, 0.727811, 0.633, 0.6);
	

	glEnable(GL_COLOR_MATERIAL);
	glColor3f(0.0f, 0.0f, 0.7f);
	//left foot
	glPushMatrix();
	box(8, 3, 4);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, 3, 0);
	box(5, 8, 4);
	glPopMatrix();


	//right foot
	glPushMatrix(); 
	glTranslatef(0, 0, 8);
	box(8, 3, 4);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, 3, 8);
	box(5, 8, 4);
	glPopMatrix();
//////////////////////////////
	glColor3f(0.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(2, 5, 0);
	box(2, 13, 3);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2, 5, 8);
	box(2, 13, 3);
	glPopMatrix();


	glColor3f(0.4f, 0.1f, 0.0f);
	glPushMatrix();
    glTranslatef(0, 26, 3.5);
	glRotatef(90, 1.0f, 0.0f, 0.0f);	
	gluCylinder(q, 7, 10, 15, 32, 16);
	glPopMatrix();
	//hand
	glPushMatrix();
	glTranslatef(0, 26, 12);
	box(5, 2, 6);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 26, -5);
	box(5, 2, 6);
	glPopMatrix();

	/// ////////////////////////////////////////
	/// handbot
	
	glColor3f(0.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(0, 19, 14);
	glRotatef(-20, 1.0f, 0.0f, 0.0f);
	box(3, 15, 2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 19, -7);
	glRotatef(20, 1.0f, 0.0f, 0.0f);
	box(3, 15, 2);
	glPopMatrix();

	////////////////////////
	// handbotbot
	glColor3f(0.0f, 0.0f, 0.7f);
	glPushMatrix();
	glTranslatef(0, 17, 14.5);
	glRotatef(-20, 1.0f, 0.0f, 0.0f);
	box(4, 6, 4);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 17, -7.5);
	glRotatef(20, 1.0f, 0.0f, 0.0f);
	box(4, 6, 4);
	glPopMatrix();

	/// ////////////////////////////////////////

	glColor3f(0.88f, 0.39f, 0.0f);
	glPushMatrix();
	glTranslatef(0, 26, 4);
	glRotatef(-90, 0.0f, 0.0f, 1.0f);
	hemiSphere(6, 32, 32);
	glPopMatrix();


	glFlush();
}

void reshape(int w, int h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);

	gluPerspective(120.0, (float)w / (float)h, 0.01, 50.0);
	glMatrixMode(GL_MODELVIEW);

}

int main()
{

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);

	glutCreateWindow("Normal");
	init();
	glutReshapeFunc(reshape);
	glutMotionFunc(mouseMove);

	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}


void box(float x, float y, float z)
{	
	float u = x / 2, v = y / 2, w = z / 2;
	float p0[] = { -u, -v,  -w }, p1[] = { -u, -v,  w }, p2[] = { -u, v, -w },
		p3[] = { -u, v, w };
	float p4[] = { u, -v,  -w }, p5[] = { u, -v,  w }, p6[] = { u, v, -w },
		p7[] = { u, v, w };
	float n[] = { 0,0,0 };
	// Top face
	glBegin(GL_QUADS);

	normal(n, p7, p6, p2);
    glNormal3fv(n);

	glVertex3fv(p7);
	glVertex3fv(p6);
	glVertex3fv(p2);
	glVertex3fv(p3);
	glEnd();

	// Front face
	glBegin(GL_QUADS);
	normal(n, p1, p5, p7);
	glNormal3fv(n);

	glVertex3fv(p1);
	glVertex3fv(p5);
	glVertex3fv(p7);
	glVertex3fv(p3);
	glEnd();

	// Right face
	glBegin(GL_QUADS);
	normal(n, p5, p4, p6);
	glNormal3fv(n);

	glVertex3fv(p5);
	glVertex3fv(p4);
	glVertex3fv(p6);
	glVertex3fv(p7);
	glEnd();
	// Left face
	glBegin(GL_QUADS);
	normal(n, p0, p1, p3);
	glNormal3fv(n);

	glVertex3fv(p0);
	glVertex3fv(p1);
	glVertex3fv(p3);
	glVertex3fv(p2);
	glEnd();
	// Back face
	glBegin(GL_QUADS);
	normal(n, p2, p6, p4);
	glNormal3fv(n);

	glVertex3fv(p2);
	glVertex3fv(p6);
	glVertex3fv(p4);
	glVertex3fv(p0);
	glEnd();
	// Bottom face
	glBegin(GL_QUADS);
	normal(n, p4, p5, p1);
	glNormal3fv(n);

	glVertex3fv(p4);
	glVertex3fv(p5);
	glVertex3fv(p1);
	glVertex3fv(p0);
	glEnd();
}

void normal(float n[], float p0[], float p1[], float p2[])
{	
	float u[] = { 0,0,0 };
	float v[] = { 0,0,0 };
	float magnitude = 0;

	u[0] = p1[0] - p0[0];
	u[1] = p1[1] - p0[1];
	u[2] = p1[2] - p0[2];

	v[0] = p2[0] - p0[0];
	v[1] = p2[1] - p0[1];
	v[2] = p2[2] - p0[2];
	n[0] = u[1] * v[2] - u[2] * v[1];
	n[1] = u[2] * v[0] - u[0] * v[2];
	n[2] = u[0] * v[1] - u[1] * v[0];
	magnitude = sqrt(n[0] * n[0] + n[1] * n[1] + n[2] * n[2]);
	// normalization
	n[0] = n[0] / magnitude;
	n[1] = n[1] / magnitude;
	n[2] = n[2] / magnitude;
}



void rectangle(float w, float h)
{
	float n[] = { 0,0,0 };
	float p0[] = { 0,0,0 };
	float p1[] = { w,0,0 };
	float p2[] = { w,h,0 };
	float p3[] = { 0,h,0 };

	glBegin(GL_QUADS);
	normal(n, p0, p1, p2);

	glVertex3fv(p0);
	glVertex3fv(p1);
	glVertex3fv(p2);
	glVertex3fv(p3);
	glEnd();
}

void fnt()
{
	float n[] = { 0,0,0 };

	float p0[] = { 0,0,0 };
	float p1[] = { 5,0,0 };
	float p2[] = { 5,2,0 };

	float p3[] = { 2,5,0 };
	float p4[] = { 0,5,0 };

	glBegin(GL_POLYGON);
	normal(n, p0, p1, p2);
	glNormal3fv(n);
	glVertex3fv(p0);
	glVertex3fv(p1);
	glVertex3fv(p2);
	glVertex3fv(p3);
	glVertex3fv(p4);
	glEnd();
}

void hemiSphere(GLfloat fRadius, GLint iSlices, GLint iStacks)
{
	const double PI = 3.141592653589;
	GLfloat drho = PI / (GLfloat)iStacks;
	GLfloat dtheta = 2.0f * PI / (GLfloat)iSlices;
	GLfloat ds = 1.0f / (GLfloat)iSlices;
	GLfloat dt = 1.0f / (GLfloat)iStacks;
	GLfloat t = 1.0f;
	GLfloat s = 0.0f;
	GLint i, j; // Looping variables
	for (i = 0; i < iStacks; i++)
	{
		GLfloat rho = (GLfloat)i * drho;
		GLfloat srho = (GLfloat)(sin(rho));
		GLfloat crho = (GLfloat)(cos(rho));
		GLfloat srhodrho = (GLfloat)(sin(rho + drho));
		GLfloat crhodrho = (GLfloat)(cos(rho + drho));
			glBegin(GL_TRIANGLE_STRIP);
		s = 0.0f;
		for (j = 0; j <= iSlices / 2; j++)
		{
			GLfloat theta = (j == iSlices) ? 0.0f : j * dtheta;
			GLfloat stheta = (GLfloat)(-sin(theta));
			GLfloat ctheta = (GLfloat)(cos(theta));
			GLfloat x = stheta * srho;
			GLfloat y = ctheta * srho;
			GLfloat z = crho;
			glTexCoord2f(s, t);
			glNormal3f(x, y, z);
			glVertex3f(x * fRadius, y * fRadius, z * fRadius);
			x = stheta * srhodrho;
			y = ctheta * srhodrho;
			z = crhodrho;
			glTexCoord2f(s, t - dt);
			s += 2 * ds;
			glNormal3f(x, y, z);
			glVertex3f(x * fRadius, y * fRadius, z * fRadius);
		}
		glEnd();
		t -= dt;
	}
}

