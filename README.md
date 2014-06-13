#qabel-client

Qabel client

## howto built

### First install all dependencies:
`sudo apt-get install qt5-base-static qt5-default qt5-qmake qtmultimedia5-dev`

### Checkout the sources:
```
mkdir qabel
cd qabel
git clone https://github.com/Qabel/qabel-client.git 
git clone https://github.com/Qabel/qabel-lib.git
```

### Build qabel-lib
```
cd qabel-lib 
mkdir build
cd build
cmake ..
make
cd ../../
```

### Build qabel-client
```
cd qabel-client
mkdir build
cd build
qmake ..
make
cd ../../
```

### Run the client
`export LD_LIBRARY_PATH=/path/to/qabel/qabel-lib/build/src/libqabel.so:$LD_LIBRARY_PATH`
