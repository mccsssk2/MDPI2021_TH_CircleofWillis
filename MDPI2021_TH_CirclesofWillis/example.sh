#!/usr/bin/env bash

wd=$(pwd)

# Create and move to a run directory
if [[ ! -d example ]]; then
  mkdir example
fi
cd example

# Generate input files
matlab -nodisplay -nojvm -batch "userpath('${wd}/scripts'); makeNoiseSamples(1); makeRandomPars(1)"

# Run a single instance under control and AF conditions
${wd}/cbf 0 0 0
${wd}/cbf 0 1 0
