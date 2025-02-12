/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:23:21 by inowak--          #+#    #+#             */
/*   Updated: 2025/02/12 10:24:05 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void *arg)
{
	(void) arg;
    printf("Thread créé et en cours d'exécution !\n");
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
    return EXIT_SUCCESS;
}

