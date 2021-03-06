#include "route.h"
#include "voiture.h"
using namespace std;

       Route::Route() : m_lenght(72),m_type(0),m_vmax(3)  {m_road.reserve(72);}
       Route::Route(int lenght, int type, int vmax) : m_lenght(lenght),m_type(type),m_vmax(vmax)  {m_road.reserve(lenght);}

       int Route::nmbr_car() const{
            // Le nombre de voiture est juste �gal a la taille du tableau m_road
            return m_road.size();
        }

       void Route::add_car() {if(m_road.size() <= m_lenght) {
           Voiture *tutur;
           bool FoundPos = false;
           int TryPos = 0;
                // On cherche la position la plus proche de 0 ou un trou est disponible.

                if(m_road.size() >= 1){
                    while (!FoundPos) {

                        FoundPos = true;
                            // On verifie qu'aucune voiture n'est sur TryPos
                                    for(int i=0;i<=m_road.size();i++) {
                                        if (m_road[i].m_p == TryPos) {FoundPos=false;}
                                    }
                                if(!FoundPos) {TryPos++;}
                    }
                }

            // A ce stade, TryPos contient la plus petite position qu'on cherchait.
            // On ajoute la tuture.
            tutur = new Voiture(TryPos);
            m_road.push_back(*tutur);
            delete (tutur);
       }}

       void Route::remove_car() {if(m_road.size()>0)   m_road.erase(m_road.begin());}

       void Route::display(){
           int nmbr_vehicules=0;
           bool has_tutur = false;
           for (int col=0;col<=m_lenght;col++) {
            has_tutur = false;
                if(m_road.size() > 0){
                    for (int i=0;(unsigned)i<=m_road.size();i++) {
                        if(m_road[i].m_p == col) {has_tutur=true;}
                    }
                }

                if(has_tutur) {
                   cout<<">";
                }
                else {
                    cout<<"_";
                }

           }
           cout<<endl;
           cout<<endl;
           cout<<endl;
           cout<<endl;
           cout<<endl;
           cout<<endl;
           cout<<endl;
           cout<<endl;
           for (int d=0;d<=m_lenght;d++) {
           }

        maj_route();
       }
        void Route::maj_route() {
            if (m_road.size() > 0) {
                for (int i=0;i<=m_road.size();i++) {
                 m_road[i].maj_voiture(*this);
                }
            }
        }
