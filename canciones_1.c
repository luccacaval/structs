#include <stdio.h>
#include <string.h>

struct cancion{
    char nombre[100];
    char artista[100];
    int duracion_seg;
    float tamanio_kb;
};

void print_song(struct cancion item){
    printf("Nombre %sArtista %sDuracion %dsegs \nPeso %dkb", item.nombre,item.artista,item.duracion_seg,item.tamanio_kb);
}

int main(void){
    char buffer[100];
    struct cancion item;
    printf("Ingrese el nombre de la cancion\n");
    fgets(buffer, 100, stdin);
    strcpy(item.nombre, buffer);
    printf("Ingrese el nombre del artista\n");
    fgets(buffer, 100, stdin);
    strcpy(item.artista, buffer);
    printf("Ingrese la duracion de la cancion en segundos\n");
    scanf("%d", &item.duracion_seg);
    getchar();
    printf("Ingrese el peso del archivo de la cancion en KB\n");
    scanf("%0.2f", &item.tamanio_kb);
    getchar();
    print_song(item);
}