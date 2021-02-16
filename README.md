# tetrisTiler
Tile the plane with tetris pieces.

Doesn't follow the official repartition of pieces types (yet ?). 

### build

`sudo apt install libsdl2-dev libsdl2-2.0-0 -y;`

`git clone https://github.com/CesarChaussinand/tetrisTiler.git`

`cd tetrisTiler`

`mkdir build`

`cd build`

`cmake ../`

`make`


### use

<code>
./tetrisTile [maximum level of substitution] [window size (px)] [size of the margin between pieces (px)]
  </code>


### screenshot

![example](https://raw.githubusercontent.com/CesarChaussinand/tetrisTiler/main/tetrisTiling_4_600_2.jpg)
