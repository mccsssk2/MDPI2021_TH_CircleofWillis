function makeNoiseSamples(n)
len = 9000;

if ~exist('input', 'dir')
  mkdir('input');
end
interval=100;
for i = 1:interval:n
X = pinknoise(len, interval)';

writematrix(X,'input/pinkNoise.dat','Delimiter','tab', 'WriteMode','append')

Y = exprnd(1,len,interval)';
writematrix(Y,'input/expNoise.dat','Delimiter','tab', 'WriteMode','append')
end

end
