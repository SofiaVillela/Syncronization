#include "sync_car.h"

void station_init(struct station *station){
    station->quant_assentos_livres = 0;
    station->quant_passageiros = 0;
    station->vagao = false;

    pthread_mutex_init(&station->mutex, NULL);
    pthread_cond_init(&station->cond_passageiro, NULL);
    pthread_cond_init(&station->cond_vagao, NULL);

}

void station_on_board(struct station *station){
    pthread_mutex_lock(&station->mutex);
    pthread_mutex_unlock(&station->mutex);
}

void station_wait_for_car(struct station *station){
    pthread_mutex_lock(&station->mutex);
    station->quant_passageiros++;
    while(station->vagao == false || station->quant_assentos_livres == 0 || station->quant_passageiros == 0){
        pthread_cond_wait(&station->cond_passageiro, &station->mutex);
    }
    station->quant_assentos_livres--:
    station->quant_passageiros--:
    if(quant_assentos_livres == 0 || quant_passageiros == 0){
        pthread_cond_signal(&station->cond_vagao);
    }
    pthread_cond_signal(&station->cond_vagao);
}