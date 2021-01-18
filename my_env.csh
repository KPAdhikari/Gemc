##!/bin/csh -f
source /site/env/syscshrc
source /group/clas12/packages/setup.csh
module load clas12/2.1

## kp: It doesn't seem to work from file. I needed to execute
##     each line in the terminal.

#cd devel/source
#scons OPT=1 -j4
#cd ..
#cp source/gemc .
#./gemc rgf_spring2020_lund.gcard
