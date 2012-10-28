#bin/bash
cd ..
#//ls src/*.cpp src/*.h > po/POTFILES.in 
#//cd po
#//xgettext -a -C ../src/route_pi.cpp -o route_pi.pot

#cd plugins/{$plugin}/
find src/ -name \*.cpp -or -name \*.h -or -name \*.hpp >po/POTFILES.in
