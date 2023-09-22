#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <vector>
#include <string>
using namespace std;

class Person{
private:
    Person* next;
    string nombre;
    int arriveAt;
    int triaje;
public:
    Person(int arriveAt, int triaje, string nombre, Person* next){
        this->arriveAt=arriveAt;
        this->next=next;
    }
    int getArriveAt(){
        return arriveAt;
    }
    int setTriage(int clasif){
        this->triaje=clasif;
    }
    int getTriage(){
        return triaje;
    }
};

class Queue{
private:
    int personCounter = 0;
    Person* first;
    Person* last;

public:
    void addPersona(int triaje, string nombre){
        if(this->personCounter==0){
            this->first = new Person(personCounter, triaje, nombre, NULL);
            this->last = first;
            personCounter++;
        }
        else{
            this->last = new Person(personCounter,triaje, nombre, last);
            personCounter++;
        }
    }
};

int main() {

    vector<string> nombres = {
            "Juan", "Ana", "Luis", "Maria", "Carlos", "Sofia", "Pedro", "Laura", "Diego", "Elena",
            "Luisa", "Andres", "Isabel", "Pablo", "Lucia", "Mateo", "Valentina", "David", "Camila",
            "Gabriel", "Juana", "Sebastian", "Alejandra", "Felipe", "Fernanda", "Julio", "Daniela",
            "Ricardo", "Olivia", "Manuel", "Valeria", "Javier", "Paula", "Fernando", "Adriana", "Hector",
            "Mariana", "Raul", "Natalia", "Arturo", "Cristina", "Eduardo", "Martha", "Martin", "Beatriz",
            "Oscar", "Monica", "Hugo", "Silvia", "Roberto", "Diana", "Rosa", "Francisco", "Patricia",
            "Antonio", "Teresa", "Miguel", "Carmen", "Alejandro", "Rosa Maria", "José", "Rocio", "Raquel",
            "Carlos Alberto", "Susana", "Ramon", "Alicia", "Vicente", "Gloria", "Manuela", "Julian", "Beatriz",
            "Federico", "Yolanda", "Alberto", "Consuelo", "Raul", "Laura Elena", "Hernan", "Luz", "Eduardo",
            "Cecilia", "Gustavo", "Ana Maria", "Guillermo", "Dolores", "Marcos", "Tania", "Pedro Luis", "Veronica",
            "Rogelio", "Nora", "Fernando", "Mercedes", "Felipe", "Adela", "Alejandro", "Rosario", "Oscar",
            "Josefina"
    };

    Queue* codigoAzul = new Queue();
    Queue* estabilidadUrgente = new Queue();
    Queue* urgNormal = new Queue();
    Queue* urgLeve = new Queue();

    srand(time(nullptr));
    int pacientes = 50 + rand() % 121;
    for(int i=0; i<pacientes;i++){
        int triaje = 1 + rand() % 4;
        int indiceNombre = 1 + rand() % 100;
        string nombre = nombres[indiceNombre];
        if(triaje==1){
            codigoAzul->addPersona(1, nombre);
        } if(triaje==2) {
            estabilidadUrgente->addPersona(2, nombre);
        } if(triaje==3) {
            urgNormal->addPersona(3, nombre);
        } if(triaje==4) {
            urgLeve->addPersona(4, nombre);
        }
    }

    

}
