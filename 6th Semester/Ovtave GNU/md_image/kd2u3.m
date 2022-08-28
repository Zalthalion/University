%k2u3 Ieva Rebeka Korolkova, ik18061

filter = [-4,-2,-1,-2,-4;-2,-1,0,-1,-2;-1,0,40,0,-1;-2,-1,0,-1,-2;-4,-2,-1,-2,-4]; %test filter to use later

function k2u3(input_name, output_name, filter)
  
  [IMG, MAP, ALPHA] = imread(input_name); %read the picture
  
  %seperate each dimension / color in the picture, so I can work on each of them seperately
  red = IMG(:,:,1); %red is the first column of the matrix
  green = IMG(:,:,2); %green is the second column of the matrix
  blue = IMG(:,:,3); %blue is the third column of the matrix
  
  %aplying filter to each dimension of the picture
  red_new = conv2(red, filter, "same"); %applying the filter to the red colour
  green_new = conv2(green, filter, "same"); %applying the filter to the green colour
  blue_new = conv2(blue, filter, "same"); %applying the filter to the blue colour
  
  %combining the dimensions and creating a new file
  IMG_new = cat(3,red_new, green_new, blue_new); %concatination with 3 dimensions to reassamble the picture with its colours
  imwrite(IMG_new, output_name); %writing the new picture in the file
  
endfunction

%Test - Results
%k2u3("picture.jpg", "picture.jpg", filter)
%The example filter generates a picture with very intesified sharpness.
%The sharpness it looks like is applied to each pixel. 
%It looks like the filter is also implementing some edge detection and intensifies the lines of the picture.