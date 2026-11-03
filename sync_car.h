#include <stdbool.h>
#ifndef SYNC_CAR_H
#define SYNC_CAR_H

struct station
{
    int quant_assentos_livres;
    int quant_passageiros;
    bool vagao;
};

station_init(struct station *station);
station_load_car(struct station *station, int count);
station_wait_for_car(struct station *station);
station_on_board(struct station *station);
#endif