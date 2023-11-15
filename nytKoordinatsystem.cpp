#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class tile {
    public:
        float xAksen;
        float yAksen;
        string tegn;

        tile(float x, float y, string z){
            xAksen = x;
            yAksen = y;
            tegn = z;
        }
};

vector<tile> tiles;                             //vector(tiles) der skal indeholde objekterne fra tile classen

void genKoordinatsystem(float sizeX, float sizeY, double resolution) {

    for(float y = 0; y < sizeY ; y = y + resolution) {
    
        for(float x = 0; x < sizeX ; x = x + resolution) {
            float xkoordinat = x;
            float ykoordinat = y;
            string tegn = " . ";

            tile flise(xkoordinat, ykoordinat, tegn);
            tiles.push_back(flise);
        }
    }
}

void sortKoordinatsystem(float sizeX, float sizeY, double resolution) {
    
    float x = 0;
    float y = sizeY - resolution;

    for (int n = 0; n < tiles.size(); n++) {                        //swap nr 1
        
        for (int i = 0; i < tiles.size(); i++) {                    //swap nr 2
            
            if (tiles[i].xAksen == x && tiles[i].yAksen == y) {

                swap (tiles[n], tiles[i] );

                x = x + resolution;    
                
                if (x == sizeX) {                                    
                    x = 0;
                    y = y - resolution;    
                }

                break;
            }
        }
    }
}  

void koordakse(float sizeX, float sizeY, double resolution) {
    
    float i = (sizeX/resolution) * (sizeY/resolution) - (sizeX/resolution);

    for (int n = i; n < tiles.size(); n++) {

        float x = tiles[n].xAksen;

        if (x - floor(x) != resolution) {
            int roundX = round(x);

            if (roundX>=10) {
                tiles[n].tegn = " " + to_string(roundX) + "";
            }

            else {
                tiles[n].tegn = " " + to_string(roundX) + " ";
            }
        }
        else {
            tiles[n].tegn = " - ";
        }
        
    }

    for (int n = i - sizeX/resolution; n+sizeX/resolution > 0; n = n - sizeX/resolution) {
        float y = tiles[n].yAksen;

        if (y - floor(y) != resolution) {
            int roundY = round(y);

            if (roundY>=10) {
                tiles[n].tegn = " " + to_string(roundY) + "";
            }

            else {
                tiles[n].tegn = " " + to_string(roundY) + " ";
            }
        }
        else {
            tiles[n].tegn = " | ";
        }
       
    }
}

void streamKoordinatsystem(float sizeX, double resolution) {                            // update koordinatsystem
    
    for (int n = 0; n < tiles.size(); n++) {

        if (tiles[n].xAksen == sizeX-resolution) {
            
            //cout << "("<< tiles[n].xAksen << "," << tiles[n].yAksen << ")\n" ;
            cout << tiles[n].tegn << "\n";
        }
        else {
        
            //cout << "("<< tiles[n].xAksen << "," << tiles[n].yAksen << ")" ;
            cout << tiles[n].tegn;
        }
    }
}

void grafTegner() {
    for (int n = 0; n < tiles.size(); n++) {
        float x = tiles[n].xAksen;

        float y = sin(x/2)+3; 

        int floorY = floor(y);
        float yDeci = y - floorY;
        
        y = (0.25 <= yDeci && yDeci < 0.75) ? y = floorY + 0.5 :    // rund op/ned til 0,5
        y = (0.25 > yDeci)                  ? floorY:               // rund ned
        y = ceil(y);                                                // rund op

        tiles[n].tegn = (tiles[n].yAksen == y) ? tiles[n].tegn = " X " : tiles[n].tegn = tiles[n].tegn;    
    } 

    for (int n = 0; n < tiles.size(); n++) {
        double x = tiles[n].xAksen;

        double y = 20*(1.0 / (sqrt(2.0*3.14) * 1.25) ) * exp(-0.5 * pow( (x-8.0) / 1.25, 2.0));

        int floorY = floor(y);
        float yDeci = y - floorY;
        
        y = (0.25 <= yDeci && yDeci < 0.75) ? y = floorY + 0.5 :    // rund op/ned til 0,5
        y = (0.25 > yDeci)                  ? floorY:               // rund ned
        y = ceil(y);                                                // rund op

        tiles[n].tegn = (tiles[n].yAksen == y) ? tiles[n].tegn = " Y " : tiles[n].tegn = tiles[n].tegn;    
    } 
}

int main(){    
    float sizeX = 30.5;
    float sizeY = 10.5;
    double resolution = 0.5;

    genKoordinatsystem(sizeX, sizeY, resolution);

    sortKoordinatsystem(sizeX, sizeY, resolution);

    grafTegner();                   // skal tage en funktion som input

    koordakse(sizeX, sizeY, resolution);

    streamKoordinatsystem(sizeX, resolution);

    return 0;
}