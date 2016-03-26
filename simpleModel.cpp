#include "simpleModel.h"

int simpleModel::Load(char *inFile)
{
	fstream modelFile;			// Start File Streaming
	modelFile.open(inFile);	

	if (modelFile.is_open())    // If File Opened correctly, begin passing through it
	{
		char currentLine[255];	// Char array for containing the contents of a line of text
		
		while(modelFile.good())
		{
			modelFile.getline(currentLine, 255);	// Get the first line of the file
			
			if(strlen(currentLine) == 0)			// If the line is empty, don't parse it
			{
				continue;
			}

			// Scan the first 3 characters from the line, ignoring whitespace
			// Use the characters to determine when to begin parsing which pieces of data
			sscanf(currentLine, " %c %c %c", &lineChar1, &lineChar2, &lineChar3);

			// If at <vertices> begin Parsing Vertices
			if ((lineChar1 == '<') && (lineChar2 == 'v'))
			{
				modelFile.getline(currentLine, 255);	// Go to next line after the heading
				
				// Parse lines while in the vertices section
				// Stopping at </>
				while (sscanf(currentLine, "%f %f %f", &vFloat1, &vFloat2, &vFloat3) != 0)
				{
					// If a line is empty, don't parse it and move to the next
					if((strlen(currentLine) == 0))     
					{
						modelFile.getline(currentLine, 255);
						continue;
					}

					vertices.push_back(Vector());       // Add new Vertex

					vertices.back().x = vFloat1;		// Place Points into Vertices Vector
					vertices.back().y = vFloat2;
					vertices.back().z = vFloat3;
					
					modelFile.getline(currentLine, 255);
				}
			}
			
			// If at <traingles> being parsing Triangle Section
			if ((lineChar1 == '<') && (lineChar2 == 't') && (lineChar3 == 'r'))
			{
				modelFile.getline(currentLine, 255);		// Go to next line after heading
				
				// parse lines while in the Triangle section, stopping at </>
				while (sscanf(currentLine, " %d %d %d %d %d %f %f %f %f %f %f", &vecInd1, &vecInd2, &vecInd3, &normInd, &texInd, &tex1x, &tex1y, &tex2x, &tex2y, &tex3x, &tex3y) != 0)
				{

					// If a line is empty, don't parse it and move to the next
					if((strlen(currentLine) == 0))
					{
						modelFile.getline(currentLine, 255);
						continue;
					}

					triangles.push_back(Triangle());        // Add new Triangle

					triangles.back().vert1 = vecInd1;		// Place vertices from index points in the Triangle vector
					triangles.back().vert2 = vecInd2;
					triangles.back().vert3 = vecInd3;

					triangles.back().norm1 = normInd;		// Place normals from the index point in the Triangle vector
					triangles.back().norm2 = normInd;
					triangles.back().norm3 = normInd;
					
					modelFile.getline(currentLine, 255);
				}
			}
		}
		modelFile.close();
	}

	else
	{
		cout << "Unable to open .model file.";
		return 0;
	}

	return 1;
}

// Draws the Model on the screen using the parsed Vector and Triangle information
void simpleModel::Create()
{
	glBegin(GL_TRIANGLES);

	for (int i = 0; i < triangles.size(); i++)
	{
		glVertex3f(vertices[triangles[i].vert1].x, vertices[triangles[i].vert1].y, vertices[triangles[i].vert1].z);
		glVertex3f(vertices[triangles[i].vert2].x, vertices[triangles[i].vert2].y, vertices[triangles[i].vert2].z);
		glVertex3f(vertices[triangles[i].vert3].x, vertices[triangles[i].vert3].y, vertices[triangles[i].vert3].z);
	}

	glEnd();
}