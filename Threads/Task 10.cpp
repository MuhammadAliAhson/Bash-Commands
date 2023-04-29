#include <iostream>
#include <pthread.h>
#include <semaphore.h>

using namespace std;

sem_t withdrawal_sem, deposit_sem;
pthread_mutex_t lock;
int account_balance = 0;

void *withdraw(void *arg) {
    while(true) {
        pthread_mutex_lock(&lock);
        if(account_balance < 10) {
            cout << "Insufficient balance for withdrawal, waiting for deposit." << endl;
            sem_wait(&withdrawal_sem);
        }
        else {
            account_balance -= 10;
            cout << "Withdrawal successful. Current balance: " << account_balance << endl;
            sem_post(&deposit_sem);
        }
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void *deposit(void *arg) {
    while(true) {
        pthread_mutex_lock(&lock);
        account_balance += 11;
        cout << "Deposit successful. Current balance: " << account_balance << endl;
        sem_post(&withdrawal_sem);
        sem_post(&withdrawal_sem);
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t withdrawal1, withdrawal2, deposit1, deposit2;
    sem_init(&withdrawal_sem, 0, 0);
    sem_init(&deposit_sem, 0, 0);
    pthread_mutex_init(&lock, NULL);

    pthread_create(&withdrawal1, NULL, withdraw, NULL);
    pthread_create(&withdrawal2, NULL, withdraw, NULL);
    pthread_create(&deposit1, NULL, deposit, NULL);
    pthread_create(&deposit2, NULL, deposit, NULL);

    pthread_join(withdrawal1, NULL);
    pthread_join(withdrawal2, NULL);
    pthread_join(deposit1, NULL);
    pthread_join(deposit2, NULL);

    sem_destroy(&withdrawal_sem);
    sem_destroy(&deposit_sem);
    pthread_mutex_destroy(&lock);

    return 0;
}

