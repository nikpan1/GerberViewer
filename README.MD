# Gerber data viewer and CSM 84VIII transpiler

## About
The repository contains an implementation of the Gerber data format parser written in C++. The created solution is used in the rest of the project, which is a program that uses the created bitmap to configure and create a program for the philips CSM 84 VIII machine.

## Gerber data 
The Gerber layer format is a 2D bi-level vector image format: the image is defined by resolutionindependent graphical objects. Bi-level or binary images in each point take one of two possible
values, typically labeled black and white.

## Dependencies
CPP 17
CMAKE 3.3
Google Tests 1.8
SDL 2.0
OpenCV 4.8.0
QT 6.6

## Additional resources
Official gerber data file format - https://www.ucamco.com/files/downloads/file_en/456/gerber-layer-format-specification-revision-2023-08_en.pdf?af3d09a62ff8542a6bbdc41b5b706612
Tokenization from - https://craftinginterpreters.com/
Homography usage - https://docs.opencv.org/3.4/d7/dff/tutorial_feature_homography.html


#### Gerber data is something awful.

![Alt Text](https://media0.giphy.com/media/ypSY231xdmQQqJsMnC/giphy.gif)
