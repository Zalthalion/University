#Author - Juris Freidenfelds JF18017
#Reads the audio file
[y,s] = audioread("./test2.ogg");

#Plots the read audio purely just for visuals
#plot(y);

#Splits the signal into frames
#0.1 is in seconds
frame_duration = 0.1;
frame_length = frame_duration*s;

#The length of the whole signal
len = length(y);

#Total number of frames
num_frames = floor(len/frame_length);

#Array for the recreated signal
new_sig = zeros(len,1); 

count = 0;

#A for loop that goes through all the frames
for k = 1 : num_frames
  
  frame = y( (k-1)*frame_length + 1 : frame_length*k);
  
  #Gets the maximal amplitude in the frame
  max_val = max(frame);
  
  #If the amplitude is larger than the chose treshold, then we want to add this signal to the new one
  if(max_val > 0.08)
    count = count+1;
    
    #Adds the frame to the new signal
    new_sig((count-1)*frame_length+1 : frame_length*count) = frame;
  end
 end

#Did not know how to thrim the silence in the end, so had to use a static number to fir in the frame 
#for k = 0 : length(new_sig)
#  if(new_sig(k) == 0)
#    new_sig(k) = [];
#  end
#end

new_sig(160000:end) = [];
#Plots the new signal just for visuals
plot(new_sig);

#Creates the new audio file
audiowrite ("./test2_nonsilent.ogg", new_sig, s);
