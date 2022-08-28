#1st Task
#Read an image from file (for example picture.jpg) and retur a 2D matrix with a grayscale image
#Function file2gray(path) - returns a matrix with an image that can be viewed using imshow()
#Sources
#How to switch from RGB to grayscale - https://octave.sourceforge.io/image/function/rgb2gray.html - Transform an image or colormap from red-green-blue (RGB) color space to a grayscale intensity image.

function grayImage = file2gray(path)
    grayImage = rgb2gray(imread(path));
endfunction

#2nd Task
#Use 2D convolution to an image. Function need to return edited image
#Function filter1(img, kernel) - returns a matrix with an image that can be viewed using imshow();
#Funkcija  - kas atgriež matricu ar att?lu, ko var r?d?t ar imshow().

function result = filter1(img, kernel)
    result = uint8(conv2(img,kernel,'same'));
endfunction

#3rd Task
#Check filter kernel. What does the filter kernel do? Write a function that checks it and in comments write te conclusion about the results
#Function test3(img) - That returns a matrix with an image after editing with filter kernel h
#Conclusions about the results (compared grayscale and the result)
# * The filter seems like to be working like an edge detector, but not as strong as the 4th Task one 
function result = test3(img)
    h = [4 3 2; 1 0 -1; -2 -3 -4];
    result = uint8(conv2(img, h, 'same')); #not sure if uint8 is needed, without it the picture is binary color
endfunction

#4th Task
#Find a filter, that makes the mentioned changes: Find edges in intensity image
#Function edgifyer(img) - Where img is a 2D image matrix
#Sources
#How to find edges in an image - https://ch.mathworks.com/help/images/ref/edge.html#:~:text=BW%20%3D%20edge(%20I%20%2C%20method%20)%20detects%20edges%20in%20image,orientation%20of%20edges%20to%20detect.
#How to add a pkg - Console error prompt (The 'edge' function belongs to the image package from Octave Forge which you have installed but not loaded.  To load the package, run 'pkg load image' from the Octave prompt.)

function result = edgifyer(img)
    pkg load image;
    result = edge(img);
endfunction

#5th Task
#Find a filter, that makes the mentioned changes: Creates an image negative, from a colored image
#Funkcija negimage(colorimg) - Where img is a 2D image matrix
#Sources
#How to create an image negative (used in code is a simplified version) - https://www.geeksforgeeks.org/negative-of-an-image-in-matlab/
#How to invert every integer value in a matrix - https://octave.sourceforge.io/image/function/imcomplement.html

function result = negimage(colorimg)
   #result = 255-colorimg;    
   result = bitcmp(colorimg);
endfunction

##Test kernel
#test = [-4,-2,-1,-2,-4; -2,-1,0,-1,-2; -1,0,40,0,1 ; -2,-1,0,-1,-2; -4,-2,-1,-2,-4;];

##Test file path
#path = "2KN00JjZ.jpg";

##1st Task test       
#imshow(file2gray(path));
##2nd Task test   
#imshow(filter1(file2gray(path), test));
#3rd Task test
#imshow(test3(file2gray(path)));
#subplot(1,2,1), imshow(file2gray(path))
#subplot(1,2,2), imshow(test3(file2gray(path)))
##4th Task test
#imshow(edgifyer(file2gray(path)));
##5th Task test
#imshow(negimage(imread(path)));





