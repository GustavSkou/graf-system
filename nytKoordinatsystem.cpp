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
vector<tile> koordtiles;


void genKoordinatsystem(int size) {

    for(float y = 0; y < size; y=y+0.5) {
    
        for(float x = 0; x < size; x=x+0.5) {
            float xkoordinat = x;
            float ykoordinat = y;
            string tegn;

            tile flise(xkoordinat, ykoordinat, tegn);
            tiles.push_back(flise);
        }
    }
}

void sortKoordinatsystem(int size) {

    for (float y = size; y >= 0; y=y-0.5) {

        for (float x = 0; x < size; x=x+0.5) {

            for (int n = 0; n < tiles.size(); n++) {

                if (tiles[n].yAksen == y && tiles[n].xAksen == x) {

                    float xkoordinat = x;
                    float ykoordinat = y;
                    string tegn = " . ";

                    tile sortflise(xkoordinat, ykoordinat, tegn);
                    koordtiles.push_back(sortflise);
                    break;
                }
            }
        }
    }
}   

void streamKoordinatsystem(const int size) {                            // update koordinatsystem
    
    cout << "\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n";
    
    for (int n = 0; n < koordtiles.size(); n++) {

        if (koordtiles[n].xAksen == size-0.5) {
            
            //cout << "("<< koordtiles[n].xAksen << "," << koordtiles[n].yAksen << ")\n" ;
            cout << koordtiles[n].tegn << "\n";
        }
        else {
        
            //cout << "("<< koordtiles[n].xAksen << "," << koordtiles[n].yAksen << ")" ;
            cout << koordtiles[n].tegn;
        }
    }
}

void grafTegner(int size) {
    for (int n = 0; n < koordtiles.size(); n++) {
        float x = koordtiles[n].xAksen;

        float y = sin(x/2)+3; 

        float yDeci = y - floor(y);
        
        y = (0.25 <= yDeci && yDeci < 0.75) ? y = (y-yDeci) + (0.5 - yDeci + yDeci) :
        y = (0.25 > yDeci)                  ? floor(y): 
        y = ceil(y);
        cout << y << "\n";

        koordtiles[n].tegn = (koordtiles[n].yAksen == y) ? koordtiles[n].tegn = " X " : koordtiles[n].tegn = koordtiles[n].tegn;    
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