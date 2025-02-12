/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_join.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:26:52 by inowak--          #+#    #+#             */
/*   Updated: 2025/02/12 10:26:57 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void *arg)
{
    printf("Thread en cours...\n");
    sleep(2);
    printf("Thread terminé !\n");
    return NULL;
}

int main()
{
    pthread_t thread;
    if (pthread_create(&thread, NULL, thread_function, NULL) != 0)
    {
        perror("Erreur pthread_create");
        return EXIT_FAILURE;
    }
    
    pthread_join(thread, NULL); // Attendre la fin du thread
    printf("Thread rejoint avec succès !\n");
    return EXIT_SUCCESS;
}

