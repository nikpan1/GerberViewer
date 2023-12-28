G04 - a comment
%MOMM+% - unit set to mm 
%FSLAX__Y__ - format specification
- for example 36 - 3 integers, 6 fractional
%TF.Part... - nothing important
%LPD*% - set polarity to dark
%ADD10C,0.010*% - define aperture number 1- as 0.01mm circle
D10* - select aperture 10 as current aperture 
X__Y__D02* - set current point to (0, 0)
G01* - linear interpolation
X500000Y0D01* - create draw graphical object with current aperture 10
from current point(0,0) to end point(5,0)
Y500000D01* - draw with current aperture from current position to known position
X0D01* - from (5,5) to (0, 5)
X__Y__D02 - set current point to ...
M02*


%ADD12R,0.6X0.6*% Define aperture 12 as a rectangle with size 0.6 x 0.6 mm
%ADD15O,0.4X01.00*% Define aperture 15 as an obround with size 0.4 x 1 mm
%ADD10C,0.1*% Define aperture 10 as a circle with diameter 0.1 mm

X20000000D03* Create a flash with the current aperture at (20, 15).
Y is modal.
