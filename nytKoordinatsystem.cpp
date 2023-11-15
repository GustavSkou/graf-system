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

void genKoordinatsystem(int size) {

    for(float y = 0; y < size; y=y+0.5) {
    
        for(float x = 0; x < size; x=x+0.5) {
            float xkoordinat = x;
            float ykoordinat = y;
            string tegn = " . ";

            tile flise(xkoordinat, ykoordinat, tegn);
            tiles.push_back(flise);
        }
    }
}

void sortKoordinatsystem(int size) {

    float x = 0;
    float y = size - 0.5;

    for (int n = 0; n < tiles.size(); n++) {                        //swap nr 1
        
        for (int i = 0; i < tiles.size(); i++) {                    //swap nr 2
            
            if (tiles[i].xAksen == x && tiles[i].yAksen == y) {

                swap (tiles[n], tiles[i] );

                x = x + 0.5;    
                
                if (x == size) {                                    
                    x = 0;
                    y = y - 0.5;    
                }

                break;
            }
        }
    }
}  

void streamKoordinatsystem(const int size) {                            // update koordinatsystem
    
    for (int n = 0; n < tiles.size(); n++) {

        if (tiles[n].xAksen == size-0.5) {
            
            //cout << "("<< tiles[n].xAksen << "," << tiles[n].yAksen << ")\n" ;
            cout << tiles[n].tegn << "\n";
        }
        else {
        
            //cout << "("<< tiles[n].xAksen << "," << tiles[n].yAksen << ")" ;
            cout << tiles[n].tegn;
        }
    }
}

void grafTegner(int size) {
    for (int n = 0; n < tiles.size(); n++) {
        float x = tiles[n].xAksen;

        float y = sin(x/2)+3; 

        float yDeci = y - floor(y);
        
        y = (0.25 <= yDeci && yDeci < 0.75) ? y = (y-yDeci) + (0.5 - yDeci + yDeci) :
        y = (0.25 > yDeci)                  ? floor(y): 
        y = ceil(y);
        //cout << y << "\n";

        tiles[n].tegn = (tiles[n].yAksen == y) ? tiles[n].tegn = " X " : tiles[n].tegn = tiles[n].tegn;    
    } 
}

int main(){    
    int size = 10;

    genKoordinatsystem(size);

    sortKoordinatsystem(size);

    grafTegner(size*2);                   // skal tage en funktion som input

    streamKoordinatsystem(size);

    return 0;
}