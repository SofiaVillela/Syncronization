# Syncronization

##Sincronização do Metrô

O programa sincroniza o embarque de passageiros em vagões de metrô. Cada vagão e cada passageiro é uma thread. A sincronização usa um único mutex por estação e variáveis de condição da biblioteca Pthreads

## Arquivos
 
| Arquivo | Descrição |
| --- | --- |
| `sync_car.c` | Implementação das funções `station_init`, `station_load_car`, `station_wait_for_car` e `station_on_board` |
| `sync_car.h` | Definição da `struct station` (contadores, mutex e variáveis de condição) e protótipos das funções |
| `sync_car-runner.c` | Programa de teste fornecido pelo professor. Cria as threads de vagões e passageiros e verifica o comportamento das funções |
| `Makefile` | Compilação e limpeza dos arquivos gerados |

## Como compilar
 
```bash
make
```
 
Gera o executável `sync_car`.
 
## Como executar
 
```bash
./sync_car
```
 
## Como limpar
 
```bash
make clean
```
 
Remove o executável `sync_car`.

## Como testar
 
O próprio `sync_car-runner.c` é o teste. Como erros de sincronização dependem da ordem de execução das threads, o programa deve ser executado várias vezes. Para rodar 20 vezes seguidas e parar no primeiro erro:
 
```bash
for i in $(seq 1 20); do ./sync_car || break; done
```

## Sistema operacional
 
Implementado e testado no Ubuntu, executado pelo WSL no Windows.
 
Requisitos: `gcc`, `make` e a biblioteca Pthreads.