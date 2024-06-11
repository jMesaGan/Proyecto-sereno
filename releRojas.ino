#include <TimeLib.h>//libreria tiempo

time_t t = now(); // Store the current time in time 

void setup() {

  pinMode(7, OUTPUT);

}

/*FUNCIONES AUXILIARES*/

//PRE:-
//POS:Prende el rele del pin 7 mins cantidad de minutos
void prenderLuz(int mins){

  digitalWrite(7, HIGH);  // turn the BULB on (HIGH is the voltage level)

  delay(mins*60*1000);//tiempo en milis para no hacer las cosas mal

  digitalWrite(7, LOW);  // turn the BULB off by making the voltage LOW
}

/*FIN FUNCIONES AUXILIARES*/

void loop() {
  t = now();
  if(hour(t)==8){
    prenderLuz(120);//se prende dos horas de 8 de la noche a 10 de la noche
  }
  if(hour(t)>=10 && hour(t)<=19){//Como lo conectan a las 12 del mediodia entonces es entre las 10 y las 7 am
      delay(random(2700000,3600000));//lo freno entre 45 min y una hora
      prenderLuz(random(1,3));//prendo la luz entre 1-3
  }
  delay(1000);//delay para q no explote el codigo
}
