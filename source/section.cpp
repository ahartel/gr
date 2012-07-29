#include "section.h"
#include <GL/freeglut.h>

Section::Section() {
	for (int i=0; i<10; i++) {
		subsections.push_back(std::make_tuple(1,1,1,1));
	}
}

void Section::render() {
	std::list<pipeTile>::iterator it;
	it = subsections.begin();
	glPushMatrix();
	while (it != subsections.end()) {
		draw_pipe_tile();
		glTranslatef(0,0,-2);
		it++;
	}
	glPopMatrix();
};

void Section::draw_pipe_tile() {
	//glBegin(GL_LINES);
	glPushMatrix();
	// left wall
	glColor3f (1.0, 1.0, 1.0);  /* the current RGB color is red: */
	glTranslatef(-1,0,+1);
	glRotatef(90,0,1,0);
	glRectf(-1.f,0.f,+1.f,+2.f);
	// left wall's contour
	glColor3f (0.0, 0.0, 1.0);  /* the current RGB color is red: */
	glBegin(GL_LINE_STRIP);
	glVertex3f(-1,0,0);
	glVertex3f(+1,0,0);
	glVertex3f(+1,+2,0);
	glVertex3f(-1,+2,0);
	glVertex3f(-1,0,0);
	glEnd();
	// end of left wall
	glPopMatrix();
	glPushMatrix();
	// right wall
	glColor3f (1.0, 1.0, 1.0);  /* the current RGB color is red: */
	glTranslatef(+1,0,+1);
	glRotatef(90,0,1,0);
	glRectf(-1.f,0.f,+1.f,+2.f);
	// right wall's contour
	glColor3f (0.0, 0.0, 1.0);  /* the current RGB color is red: */
	glBegin(GL_LINE_STRIP);
	glVertex3f(-1,0,0);
	glVertex3f(+1,0,0);
	glVertex3f(+1,+2,0);
	glVertex3f(-1,+2,0);
	glVertex3f(-1,0,0);
	glEnd();
	// end of right wall
	glPopMatrix();
	glPushMatrix();
	// bottom wall
	glColor3f (1.0, 1.0, 1.0);  /* the current RGB color is red: */
	glRotatef(90,1,0,0);
	glRectf(-1.f,0.f,+1.f,+2.f);
	// bottom wall's contour
	glColor3f (0.0, 0.0, 1.0);  /* the current RGB color is red: */
	glBegin(GL_LINE_STRIP);
	glVertex3f(-1,0,0);
	glVertex3f(+1,0,0);
	glVertex3f(+1,+2,0);
	glVertex3f(-1,+2,0);
	glVertex3f(-1,0,0);
	glEnd();
	// end of bottom wall
	glPopMatrix();
	glPushMatrix();
	// top wall
	glColor3f (1.0, 1.0, 1.0);  /* the current RGB color is red: */
	glTranslatef(0,2,0);
	glRotatef(90,1,0,0);
	glRectf(-1.f,0.f,+1.f,+2.f);
	// top wall's contour
	glColor3f (0.0, 0.0, 1.0);  /* the current RGB color is red: */
	glBegin(GL_LINE_STRIP);
	glVertex3f(-1,0,0);
	glVertex3f(+1,0,0);
	glVertex3f(+1,+2,0);
	glVertex3f(-1,+2,0);
	glVertex3f(-1,0,0);
	glEnd();
	// end of top wall
	glPopMatrix();
}
