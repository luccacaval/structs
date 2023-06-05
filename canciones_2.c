#include <stdio.h>
#include <string.h>

struct cancion{
    char nombre[100];
    char artista[100];
    int duracion_seg;
    float tamanio_kb;
};

struct cancion items[100];

void print_song(struct cancion item){
    printf("Nombre %sArtista %sDuracion %dsegs \nPeso %0.2fkb\n", item.nombre,item.artista,item.duracion_seg,item.tamanio_kb);
}


void search_song(int len,char *query){
    for (int i = 0; i < len; i++){
        if (!strcmp(items[i].artista, query) || !strcmp(items[i].nombre, query)){
            print_song(items[i]);
        }
    }
}

void print_all_songs(int len){
    for (int i = 0; i < len; i++){
        printf("Nombre %sArtista %sDuracion %dsegs \nPeso %0.2fkb\n", items[i].nombre,items[i].artista,items[i].duracion_seg,items[i].tamanio_kb);
    }
}

void create_song(int songs_count){
    char buffer[100];
    printf("Ingrese el nombre de la cancion\n");
    fgets(buffer, 100, stdin);
    strcpy(items[songs_count].nombre, buffer);
    printf("Ingrese el nombre del artista\n");
    fgets(buffer, 100, stdin);
    strcpy(items[songs_count].artista, buffer);
    printf("Ingrese la duracion de la cancion en segundos\n");
    scanf("%d", &items[songs_count].duracion_seg);
    getchar();
    printf("Ingrese el peso del archivo de la cancion en KB\n");
    scanf("%f", &items[songs_count].tamanio_kb);
    getchar();
    fflush(stdin);
    print_song(items[songs_count]);
}

int main(void){
    int songs_count = 0;
    int choise;
    char buffer[100];
    while (1){
        printf("1) Crear una cancion\n2)Buscar una cancion\n3)Mostrar el nombre de todas las canciones\n");
        scanf("%d",&choise);
        getchar();
        switch (choise)
        {
        case 1:
        if(songs_count <= 100){
            create_song(songs_count);
            songs_count++;
        } else printf("Se llego al maximo de canciones\n");

            break;
        case 2:
            printf("Ingrese el nombre del artista o la cancion a buscar\n");
            fgets(buffer,100,stdin);
            search_song(songs_count,buffer);
            break;
        case 3:
            print_all_songs(songs_count);
            break;
        default:
            printf("Opccion invalida\n");
            break;
        }
    }
    return 0;
}