
#Function that returns 1 second of a given sound file
function result = onesec(sample, fs)
  result = [sample(1:fs,:)];
endfunction

#Helper function to return frequency of a given note relative to C
function fre = get_fre(num)
    C_freq = 261.6256; #frequency of the note C, I know i could take A, bur C is easier

    fre = C_freq * power(2, (num/12));
endfunction 

#Function that creates an audio file that contains an octave (from C to C) each note length is 0.25s
function stereo = oneoctave(fs) 
    octave = [];  

    #Array with all notes in an octave
    notes = [get_fre(0) get_fre(2) get_fre(4) get_fre(5) get_fre(7) get_fre(9) get_fre(11) get_fre(12)];
    note_length = 0.25;

    #goes through all notes, creates sin waves and links them together
    for i = 1 : 8
        samples_per_period = (fs)/notes(i);
        step = 2*pi / samples_per_period;
        limit = (fs)*step;
        t = 0: step: limit*note_length;
        s = sin(t);
        octave = [octave; s'];
    endfor
    
    #creates stereo output
    stereo = [octave octave];
endfunction


#Function that adds 3 sin waves together
function sine3 = sine3(f1, f2, f3, a1, a2, a3, fs, length)
    
    sine__ = [];

    #array of all given frequencies
    frequencies = [f1 f2 f3];
    #array of all given amplitudes
    amplitudes = [a1 a2 a3];

    #loops over all frequencies, creates sin waves, adds apmlitudes, places in array
    for i = 1:3
        samples_per_period = (fs)/frequencies(i); 
        step = pi*2 / samples_per_period;
        limit = fs*step*length;
        t = 0:step:limit;
        s1 = sin(t);
        s1 = s1'; 
        s1_ = s1 * amplitudes(i);
        sine__ = [[sine__ ],[s1]]; #probably sine__ = [sine__ s1] would work just fine, but i was too afraid to try it (this result was made from trial and error)
    endfor
    #adds all 3 sine wavews together
    sine3 = sine__(:,1) +  sine__(:,2) + sine__(:,3);  
    #i do not know if stereo is needed
    sine3 = [sine3 sine3];
endfunction  





