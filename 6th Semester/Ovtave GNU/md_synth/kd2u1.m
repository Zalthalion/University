#?ener?t ska?as failu, kas “sp?l? akordu” – vienlaic?gi tr?s notis Do, Mi un Sol no okt?vas, kur? La nots frekvence ir 440Hz. vienu sekundi. Funkcijai kd2u1 j??ener? matrica ar akordu, pie?emot ka m?r?jumu biežums ir 44100, un j?saglab? k? audio fails “akords.wav”. Dots, ka:

#Katra nots jebkur? okt?v? ir ar divas reizes liel?ku frekvenci ne k? t? pati nots iepriekš?j? (zem?k?) okt?v?;
#Katras n?kam?s nots frekvence ir ieg?stama iepriekš?jo pareizinot ar koeficientu K (kas jums j?noskaidro). Pavisam okt?v? kop? ir 12 notis: Do, Do#, Re, Re#, Mi, Fa, Fa#, Sol, Sol#, La, La#, Si.

function stereo = kd2u1()

  fs = 44100; #sample rate
  octave = [];  #Tukša rezult?ta matrica
  
  doFreq = 261.64; #Do frekvence
  miFreq = doFreq * power(2, (4/12)); #mi frekvence. 4 == nots atraš?n?s vieta okt?v? (do == 0)
  solfreq = doFreq * power(2, (7/12)); #sol frekvence. 7 == nots atraš?n?s vieta okt?v? (do == 0)
  
  notes = [doFreq, miFreq, solfreq];
  
  for i=1:3
    #Izveido nots sinuso?du balstoties uz frekvenci
    freq = notes(1,i);
    samples_per_period = (fs)/freq;
    step =2*pi / samples_per_period;
    limit = (fs)*step;
    t = 0: step: limit;
    s = sin(t);
    
    #Pievieno rezult?tu matricai
    octave = [octave s'];
    
  endfor
  
  stereo = [octave octave];
  #Izveido audio failu
  audiowrite ("akords.wav", stereo, fs);  
  
endfunction

test = kd2u1();


