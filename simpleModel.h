#ifndef SIMPLEMODEL_H
#define SIMPLEMODEL_H

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>
#include <glut.h>

using namespace std;

typedef struct		// Vector Structure, for x, y, z vertices
{
	float x;
	float y;
	float z;
}
Vector;

typedef struct		// Triangle Structure, for 3 vertices combined
{
	int vert1; 
	int vert2; 
	int vert3;

	int norm1;
	int norm2;
	int norm3;
}
Triangle;

class simpleModel
{
	public:

		int simpleModel::Load(char *inFile);	// Method to load the .model file
		void simpleModel::Create();				// Outputs the model to the screen

		vector<Vector> vertices;				// Variables
		vector<Triangle> triangles;
		vector<Vector> normals;

		char lineChar1, lineChar2, lineChar3;	// Used to find sections while parsing lines

		float vFloat1, vFloat2, vFloat3;		// Used to temporarily store Vertex Data

		int vecInd1, vecInd2, vecInd3;			// Used to temporarily store Triangle Vertex Indices

		int normInd;							// Used to temporarily store the Normal Index
		int texInd;								// Used to temporarily store the Texture Index

		float tex1x;							// Used to temporarily store the Texture Coords
		float tex1y;
		float tex2x;
		float tex2y;
		float tex3x;
		float tex3y;

};


#endif