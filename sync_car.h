#ifndef SYNC_CAR_H
#include <stdbool.h>
#include <pthread.h>
#define SYNC_CAR_H

struct station
{
    int quant_assentos_livres;
    int quant_passageiros;
    int quant_embarcando;
    bool vagao;
    pthread_mutex_t mutex;
    pthread_cond_t cond_passageiro;
    pthread_cond_t cond_vagao;
};

void station_init(struct station *station);
void station_load_car(struct station *station, int count);
void station_wait_for_car(struct station *station);
void station_on_board(struct station *station);
#endif