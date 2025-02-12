/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_detach.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:25:38 by inowak--          #+#    #+#             */
/*   Updated: 2025/02/12 10:25:44 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void *arg)
{
    printf("Thread détaché en cours...\n");
    sleep(2);
    printf("Thread détaché terminé !\n");
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
    
    pthread_detach(thread); // Le thread se termine seul, pas besoin de pthread_join
    sleep(3); // Attendre pour voir l'affichage du thread détaché
    return EXIT_SUCCESS;
}

