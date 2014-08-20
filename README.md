#qabel-client

Qabel client

## howto built

### First install all dependencies:
`sudo apt-get install qt5-base-static qt5-default qt5-qmake qtmultimedia5-dev`libjson-c-dev

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

--

#### Build qabel-client on OS X 10.9.2
Dependencies can be installed with homebrew. `qabel-lib` requires openssl 1.*.  As OS X comes with openssl 0.9.8y we need to install fitting openssl libs via homebrew as described below. For the cmake step with qabel-lib we provide the alternate openssl version.

##### Requirements & Dependencies with homebrew
```
$ brew install qt5
$ brew install json-c
$ brew linkapps --force
$ brew install openssl
```

#### Build qabel-lib
OS 10.9 has openssl 0.9 default, lets override that with our freshly brewed openssl for the cmake step:

`
$ cmake -D CMAKE_PREFIX_PATH=/usr/local/Cellar/openssl/1.0.1h/ ..
`
