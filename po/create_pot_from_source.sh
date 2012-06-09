#bin/bash
cd ..
ls src/*.cpp src/*.h > po/POTFILES.in 
cd po
xgettext -a -C ../src/route_pi.cpp -o route_pi.pot

