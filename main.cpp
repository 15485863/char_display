#include <iostream>
#include <string>
#include <vector>
using namespace std;
int dimx=10;
int dimy=4;
string screen[1000][1000][3];
struct displayinfo{
    vector<string>bm;
    vector<int>fg;
    vector<int>bg;
    int fl;
    int md;
};
void display(displayinfo tile,int xloc,int yloc){
    auto flair=tile.fl;
    auto mode=tile.md;
    auto colorbg=tile.bg;
    auto colorfg=tile.fg;
    auto bm=tile.bm;
    for (int i = 0; i < 3; ++i) {
        string control;
        cout<<"\033["<<flair<<"m";
        if(mode==0){
            control="\033["+to_string(flair)+"m"+"\033[38;5;"+to_string(colorfg[0])+"m"+"\033[48;5;"+ to_string(colorbg[0])+"m";
        }else{
            control="\033[38;2;{"+to_string(colorfg[0])+"};{"+to_string(colorfg[1])+"};{"+to_string(colorfg[2])+"}m"+
                    "\033[38;2;{"+to_string(colorbg[0])+"};{"+to_string(colorbg[1])+"};{"+to_string(colorbg[2])+"}m";
        }
        screen[yloc*3+i][xloc][0]=control;
        screen[yloc*3+i][xloc][1]=bm[i];
        screen[yloc*3+i][xloc][2]="\033[0m";
    }
}
int main() {
    int color[1]={150};
    int color2[1]={140};
//    string bm[3]={"III",">*>","III"};
    displayinfo tiles[4];
    for (int i = 0; i < 4; ++i) {
        tiles[i].bg={51+i};tiles[i].fg={50+i};tiles[i].md=0;tiles[i].fl=0;
    }
    tiles[0].bm={"III",">*>","III"};
    tiles[1].bm={"I^I","I*I","I^I"};
    tiles[2].bm={"IvI","I*I","IvI"};
    tiles[3].bm={"III","<*<","III"};
    for (int i = 0; i < dimy; ++i) {
        for (int j = 0; j < dimx; ++j) {
            display(tiles[(i+j)%4],j,i);
        }
    }
    for (int i = 0; i < dimy*3; ++i) {
        for (int j = 0; j < dimx; ++j) {
            for (int k = 0; k < 3; ++k) {
                cout<<screen[i][j][k];
            }
        }
        cout<<'\n';
    }
    return 0;
}
