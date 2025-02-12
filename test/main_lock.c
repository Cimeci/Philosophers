/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lock.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:33:04 by inowak--          #+#    #+#             */
/*   Updated: 2025/02/12 10:33:08 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock; // Déclaration du mutex
int shared_data = 0;

void *thread_function(void *arg)
{
    pthread_mutex_lock(&lock);
    printf("Thread accède à la ressource partagée.\n");
    shared_data++;
    printf("Valeur de shared_data : %d\n", shared_data);
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main()
{
    pthread_mutex_init(&lock, NULL);
    
    pthread_t t1, t2;
    pthread_create(&t1, NULL, thread_function, NULL);
    pthread_create(&t2, NULL, thread_function, NULL);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);
    return EXIT_SUCCESS;
}

