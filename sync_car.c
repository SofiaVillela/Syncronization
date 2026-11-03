#include "sync_car.h"

void station_init(struct station *station){
    station->quant_assentos_livres = 0;
    station->quant_passageiros = 0;
    station->vagao = false;

    pthread_mutex_init(&station->mutex, NULL);
    pthread_cond_init(&station->cond_passageiro, NULL);
    pthread_cond_init(&station->cond_vagao, NULL);

}