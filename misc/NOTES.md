- GLSL
The **OpenGL Shader Language**
  - [GLSL Data Types](https://wikis.khronos.org/opengl/Data_Type_(GLSL))

  vec4 values can be accessed by using either xyzw, rgba or stpq
  [this video](https://www.youtube.com/watch?v=3mfvZ-mdtZQ) has good explanations


- Vertex Shaders
process vertex data to determine the position of shapes in **3D space**; "polygons"

- Fragment Shaders
compute the color and other attributes **of each pixel** (or fragment) that'll be rendered on the screen; "pixel shader"
it works with "fractions" of pixels; the first pixel coordinate of an image is always 0,0 and the last is always 1,1 no matter the size of the image; normalised values
can result in "texels", when texture pixels are a different size from screen pixels



- Distortion Texture
i.e. determines how and where coordinates are gonna be pushed; overlays your texture
