#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
pthread_t philosopher[5];
pthread_mutex_t chopstick[5];
float seconds = 1;
void *eat(int i){
    printf("philosopher %d is thinking !!\n", i+1);
    int ch1 = i;
    int ch2 = (i + 1) % 5;
    pthread_mutex_lock(&chopstick[ch1]);
    pthread_mutex_lock(&chopstick[ch2]);
    printf("philosopher %d is eating using chopstick[%d] and chopstick[%d] !!\n", i+1, ch1, ch2);
    sleep(seconds);
    pthread_mutex_unlock(&chopstick[ch1]);
    pthread_mutex_unlock(&chopstick[ch2]);
    printf("philosopher %d finished eating !!\n", i+1);
}
int main() {
    for (int i = 0; i < 5; i++){
        pthread_mutex_init(&chopstick[i], NULL);
    }
    for (int i = 0; i < 5; ++i) {
        pthread_create(&philosopher[i], NULL, (void *) eat, (void
        *)(intptr_t) (i));
    }
    for (int i = 0; i < 5; i++){
        pthread_join(philosopher[i], NULL);
    }
    return 0;
}