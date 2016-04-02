# EECE 478 Computer Graphics: Model Viewer

### Part 1 of 3

This project uses OpenGL and GLUT to model and render various things, from single models to entire scenes.

Part 1 is a simple model viewing application. A world space is created with a floor grid and camera controls are implemented to allows the user to navigate and change the view. *simpleModel* is used to read the data from a model file specified in the command line arguments, and to draw the image in wireframe. This currently defaults to the included ClockTower model.

The executable can be controlled using the following inputs:

**WASD** is used to move the position of the camera, with **E** and **C** controlling elevation.
The **Arrow Keys** rotate the viewpoint.

**H** toggles the floor grid, **J** toggles the teapot.

The Mouse controls the rotation and translation of the imported object. The **Right Mouse Button** is used to toggle between rotation and translation mode. The imported object is rotated using the motion of the mouse, as well as holding down the **Left Mouse Button**.
