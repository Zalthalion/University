function stereo = oneoctave(fs)
octave = [];  
for i = 0 : 7
  freq = 261.6256 * power(2, (i/12));
  samples_per_period = (fs)/freq;
  step = 2*pi / samples_per_period;
  limit = (fs)*step;
  t = 0: step: limit*0.25;
  s = sin(t);
  octave = [octave; s'];
endfor
stereo = [octave octave];

endfunction

function result = onesec(sample, fs)
  result = [sample(1:fs,:)];
endfunction

function sine3(f1, f2, f3, a1, a2, a3, fs, length)

smth = something;
smth = onesec(something, 44100);

test = something(1:44100,1);

something = oneoctave(44100);

audiowrite ("octave.wav", something, fs);


y = sin(2*pi*220*(x-phaseShift));
y = amplitude * sin(2*pi*(x-phaseShift)/period);
x = linspace(0, 3*period, 500); % 500 points between 0 and 3*period
xlabel('X', 'FontSize', 20);
ylabel('Y', 'FontSize', 20);
title('My Awesome Homework Solution', 'FontSize', 20);
grid on;