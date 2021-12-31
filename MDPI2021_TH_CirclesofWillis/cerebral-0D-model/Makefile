# This file is part of PM3 Cerebral 0D model.

# PM3 Cerebral 0D model is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# PM3 Cerebral 0D model is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with PM3 Cerebral 0D model.  If not, see <https://www.gnu.org/licenses/>.

# makefile.
# customized for TH/pm3
# change all DRIVER instances to whatever it needs to be.
whoisthis=${USER}
#
#
CC       	= mpicc
CFLAGS   	= -g -O2
INCLUDE  	= /home/pm3user/software/sundials/instdir/include
MY_APP	 	= #PM3 Cerebral 0D model
LIB	 			= -L/home/pm3user/software/sundials/instdir/lib

cbf:	ursino.c
	${CC} ${CFLAGS} -I${INCLUDE} -c ursino.c -o ursino.o
	${CC} ${CFLAGS} ursino.o -I${INCLUDE} -lm ${LIB} -lsundials_cvodes -lsundials_nvecserial -o ${MY_APP}

run:
	./${MY_APP}

clean:
	rm  ${MY_APP}

veryclean:
	rm -r *.dat ${MY_APP} ${MY_APPI} *.o *~ *.txt *.out
