echo replacing "° with \u00b0 to facillitate windoze build"
sed -i 's_°_\\u00b0_g' routegui.cpp
sed -i 's_°_\\u00b0_g' routegui_impl.cpp

