function makeRandomPars(n)

if ~exist('input', 'dir')
  mkdir('input');
end

%meresennetwister
rng(1, 'twister');
% latin hypercube sampling
R = lhsdesign(n, 100);
R = R .* 1.5 + 0.5;

writematrix(R,'input/randomPars.dat','Delimiter','tab')


end
