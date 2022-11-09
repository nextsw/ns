

HOW TO BUILD
=============


export PATH=~/dev/depot_tools:$PATH
export PATH=~/dev/flutter/engine/src/flutter/tools:$PATH


cp -rf ~/dev/flutter/engine/src/build .


Clone gn

build gn

gn gen out
ninja -C out
