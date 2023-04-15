#include "src/abb.h"
#include <stdio.h>
#include <stdlib.h>
#include "pa2m.h"

bool son_iguales(void *elemento1, void *elemento2)
{
	return(*(int*)elemento1 != *(int*)elemento2);
}

int comparador(void *elemento1, void *elemento2)
{
	if(elemento1 == NULL || elemento2 == NULL)
		return 1;

	if(*(int*)elemento1 == *(int*)elemento2)
		return 0;
	else if(*(int*)elemento1 > *(int*)elemento2)
		return 1;
	else if(*(int*)elemento1 < *(int*)elemento2)
		return -1;

	return 0;
}

void creacion_de_ABB()
{

	abb_t *abb_creado = abb_crear(NULL);
	pa2m_afirmar( abb_creado == NULL, "No puedo crear un arbol sin un comparador.");
	
	abb_creado = abb_crear(comparador);
	pa2m_afirmar( abb_creado != NULL, "Se puede crear un ABB.");
	pa2m_afirmar( abb_tamanio(abb_creado) == 0, "El tamaño de un ABB recien creado es cero.");
	pa2m_afirmar( abb_creado->nodo_raiz == NULL, "Al crear un ABB, su raiz apunta a NULL.");

	abb_destruir_todo(abb_creado, NULL);
}

void insertar_en_ABB()
{
	abb_t *abb_creado = abb_crear(comparador);
	abb_t *aux = NULL;

	int elemento1 = 10;
	aux = abb_insertar(abb_creado, &elemento1);

	pa2m_afirmar( aux != NULL,"Puedo agregar un elemento correctamente.");
	pa2m_afirmar( *(int*)(abb_creado->nodo_raiz->elemento) == elemento1,"El primer elemento se inserta en el nodo raiz.");
	pa2m_afirmar( abb_creado->tamanio == 1, "Al agregar un elemento, el ABB aumenta de tamaño en uno.");

	int elemento0 = 5;
	abb_insertar(abb_creado, &elemento0);
	pa2m_afirmar( *(int*)(abb_creado->nodo_raiz->izquierda->elemento) == elemento0, "Un elemento menor se agrega a la izquierda correctamente.");

	int elemento2 = 20;
	abb_insertar(abb_creado, &elemento2);
	pa2m_afirmar( *(int*)(abb_creado->nodo_raiz->derecha->elemento) == elemento2,"Un elemento mayor se agrega a la derecha correctamente.");

	int elemento3 = 30;
	abb_insertar(abb_creado, &elemento3);
	pa2m_afirmar( *(int*)(abb_creado->nodo_raiz->derecha->derecha->elemento) == elemento3,"Se agrega un tercer elemento mayor a los otros dos y queda a la derecha de ambos.");

	int elemento4 = 2;
	abb_insertar(abb_creado, &elemento4);
	pa2m_afirmar( *(int*)(abb_creado->nodo_raiz->izquierda->izquierda->elemento) == elemento4,"Se agrega un cuarto elemento menor a los otros tres y queda a la izquierda de todos.");

	abb_insertar(abb_creado, &elemento1);
	pa2m_afirmar( *(int*)(abb_creado->nodo_raiz->izquierda->elemento) == elemento1 && abb_creado->nodo_raiz->izquierda->derecha == NULL &&  
		*(int*)(abb_creado->nodo_raiz->izquierda->izquierda->elemento) == elemento0, "Al agregar un elemento repetido, este se posicion a la izquierda del original.");

	pa2m_afirmar( *(int*)(abb_creado->nodo_raiz->izquierda->izquierda->elemento) == elemento0, "Al agregar un elemento repetido, no se pierde la referencia al siguiente nodo.");

	abb_destruir(abb_creado);
}

void quitar_en_abb(){



	abb_t *abb_creado = abb_crear(comparador);

	int elemento0 = 2, elemento1 = 5, elemento2 = 10, elemento3 = 20; 
	int elemento4 = 30, elemento5 = 15, elemento6 = 7, elemento7 = 40;
	int elemento8 = 16, elemento9 = 8, elemento10 = 18, elemento11 = 14;

	abb_insertar(abb_creado, &elemento2); abb_insertar(abb_creado, &elemento1); 
	abb_insertar(abb_creado, &elemento3); abb_insertar(abb_creado, &elemento0); 
	abb_insertar(abb_creado, &elemento4); abb_insertar(abb_creado, &elemento5);
	abb_insertar(abb_creado, &elemento6); abb_insertar(abb_creado, &elemento7);
	abb_insertar(abb_creado, &elemento8); abb_insertar(abb_creado, &elemento9);
	abb_insertar(abb_creado, &elemento10); abb_insertar(abb_creado, &elemento11);

	pa2m_afirmar( abb_quitar(NULL, &elemento0) == NULL,"No puedo quitar un elemento de un arbol inexistente");

	int elemento15 = 55;
	abb_quitar(abb_creado, &elemento15);
	pa2m_afirmar(abb_tamanio(abb_creado) == 12,"Al intentar eliminar un elemento que no se encuentra en el arbol el tamaño no se reduce.");

	abb_quitar(abb_creado, &elemento7);
	pa2m_afirmar( abb_tamanio(abb_creado) == 11,"Al eliminar un elemento cualquiera, el tamaño del abb se reduce en uno.");

	abb_quitar(abb_creado, &elemento0);
	pa2m_afirmar( abb_tamanio(abb_creado) == 10 && abb_creado->nodo_raiz->izquierda->izquierda == NULL,
	 "Al eliminar un elemento que se encuentra el final del arbol (nodo_hoja), el tamaño del abb se reduce y se borra correctamente.");

	abb_quitar( abb_creado, &elemento1);
	pa2m_afirmar(abb_tamanio(abb_creado) == 9 && *(int*)abb_creado->nodo_raiz->izquierda->elemento == elemento6, 
		"Al eliminar un elemento que tenga un subarbol (en una de sus ramas y la otra sea nula), el tamaño del abb se reduce y se borra correctamente.");

	abb_quitar( abb_creado, &elemento3);
	pa2m_afirmar(abb_tamanio(abb_creado) == 8 && *(int*)abb_creado->nodo_raiz->derecha->elemento == elemento10 , 
		"Al eliminar un elemento que tenga un subarbol (en ambas ramas), el tamaño del abb se reduce y se borra correctamente.");

	abb_quitar(abb_creado, &elemento2);
	pa2m_afirmar(abb_tamanio(abb_creado) == 7 && *(int*)abb_creado->nodo_raiz->elemento == elemento9, 
		"Puedo borrar la raiz y su reemplazo es su predecesor inorden.");

	abb_quitar(abb_creado, &elemento9);
	pa2m_afirmar(abb_tamanio(abb_creado) == 6 && *(int*)abb_creado->nodo_raiz->elemento == elemento6, 
		"Puedo borrar la raiz si solo tiene un nodo a la izquierda y su reemplazo es su predecesor inorden.");

	abb_quitar(abb_creado, &elemento6);
	pa2m_afirmar(abb_tamanio(abb_creado) == 5 && *(int*)abb_creado->nodo_raiz->elemento == elemento10, 
		"Puedo borrar la raiz si no tiene nodos a su izquierda y su reemplazo es el nodo derecho.");

	abb_quitar(abb_creado, &elemento8);
	abb_quitar(abb_creado, &elemento5);
	abb_quitar(abb_creado, &elemento11);
	abb_quitar(abb_creado, &elemento4);
	abb_quitar(abb_creado, &elemento10);
	pa2m_afirmar(abb_tamanio(abb_creado) == 0 && abb_creado->nodo_raiz == NULL, "Puedo borrar todo el arbol a base de quitar la raiz una por una.");

	free(abb_creado);
}

void buscar_en_abb(){

	abb_t *abb_creado = abb_crear(comparador);

	int elemento0 = 2, elemento1 = 5, elemento2 = 10, elemento3 = 20; 
	int elemento4 = 30, elemento5 = 15, elemento6 = 7, elemento7 = 40;
	int elemento8 = 16, elemento9 = 8, elemento10 = 18, elemento11 = 14;

	abb_insertar(abb_creado, &elemento2); abb_insertar(abb_creado, &elemento1); 
	abb_insertar(abb_creado, &elemento3); abb_insertar(abb_creado, &elemento0); 
	abb_insertar(abb_creado, &elemento4); abb_insertar(abb_creado, &elemento5);
	abb_insertar(abb_creado, &elemento6); abb_insertar(abb_creado, &elemento7);
	abb_insertar(abb_creado, &elemento8); abb_insertar(abb_creado, &elemento9);
	abb_insertar(abb_creado, &elemento10); abb_insertar(abb_creado, &elemento11);

	void *elemento_buscado = NULL;

	elemento_buscado = abb_buscar( NULL, &elemento1);
	pa2m_afirmar( elemento_buscado == NULL, "No puedo buscar elementos en un arbol inexsistente.");

	elemento_buscado = abb_buscar(abb_creado, &elemento0);
	pa2m_afirmar( *(int*)elemento_buscado == elemento0, "Puedo buscar un elemento correctamente.");

	elemento_buscado = abb_buscar(abb_creado, &elemento4);
	pa2m_afirmar( *(int*)elemento_buscado == elemento4, "Puedo buscar un elemento correctamente.");

	elemento_buscado = abb_buscar(abb_creado, &elemento1);
	pa2m_afirmar( *(int*)elemento_buscado == elemento1, "Puedo buscar un elemento correctamente.");

	elemento_buscado = abb_buscar(abb_creado, &elemento2);
	pa2m_afirmar( *(int*)elemento_buscado == elemento2, "Puedo buscar el elemento de la raiz correctamente.");

	abb_destruir(abb_creado);

}

void recorrer_abb(){

	abb_t *abb_creado = abb_crear(comparador);

	int *vector[10];
	size_t cantidad_de_recorridos = 0;

	int elemento0 = 2, elemento1 = 5, elemento2 = 10, elemento3 = 20; 
	int elemento4 = 30, elemento5 = 15, elemento6 = 7, elemento8 = 16;
	int elemento10 = 18, elemento12 = 14;

	pa2m_afirmar(abb_recorrer( NULL, PREORDEN, (void**)vector, 10) == 0, "No puedo recorrer si no existe el arbol.");
	pa2m_afirmar(abb_recorrer(abb_creado, -1, (void**)vector, 10) == 0, "No puedo recorrer si no le envio un recorrido valido.");
	pa2m_afirmar(abb_recorrer(abb_creado, PREORDEN, NULL, 10) == 0, "No puedo recorrer si no le envio un vector.");
	pa2m_afirmar(abb_recorrer(abb_creado, PREORDEN, (void**)vector, 0) == 0, "Si le envio que recorrer hasta 0, no aplica el recorrido.");

	abb_insertar(abb_creado, &elemento2); abb_insertar(abb_creado, &elemento1); 
	abb_insertar(abb_creado, &elemento3); abb_insertar(abb_creado, &elemento0); 
	abb_insertar(abb_creado, &elemento4); abb_insertar(abb_creado, &elemento5);
	abb_insertar(abb_creado, &elemento6); abb_insertar(abb_creado, &elemento12);
	abb_insertar(abb_creado, &elemento8); abb_insertar(abb_creado, &elemento10);

	pa2m_nuevo_grupo("Recorrido INORDEN");
	cantidad_de_recorridos = abb_recorrer(abb_creado, INORDEN, (void**)vector, 10);
	pa2m_afirmar( *vector[0] == elemento0, "El elemento esperado se guarda en el vector correctamente.");
	pa2m_afirmar( *vector[1] == elemento1, "El elemento esperado se guarda en el vector correctamente.");
	pa2m_afirmar( *vector[2] == elemento6, "El elemento esperado se guarda en el vector correctamente.");
	pa2m_afirmar( *vector[3] == elemento2, "El elemento esperado se guarda en el vector correctamente.");
	pa2m_afirmar( *vector[4] == elemento12, "El elemento esperado se guarda en el vector correctamente.");
	pa2m_afirmar( cantidad_de_recorridos == 10, "El recorrido devuelve la cantidad correcta de elementos almacenados");

	pa2m_nuevo_grupo("Recorrido PREORDEN");
	cantidad_de_recorridos = abb_recorrer(abb_creado, PREORDEN, (void**)vector, 9);
	pa2m_afirmar( *vector[0] == elemento2, "El elemento esperado se guarda en el vector correctamente.");
	pa2m_afirmar( *vector[1] == elemento1, "El elemento esperado se guarda en el vector correctamente.");
	pa2m_afirmar( *vector[2] == elemento0, "El elemento esperado se guarda en el vector correctamente.");
	pa2m_afirmar( *vector[3] == elemento6, "El elemento esperado se guarda en el vector correctamente.");
	pa2m_afirmar( *vector[4] == elemento3, "El elemento esperado se guarda en el vector correctamente.");
	pa2m_afirmar( cantidad_de_recorridos == 9, "El recorrido devuelve la cantidad correcta de elementos almacenados");

	pa2m_nuevo_grupo("Recorrido POSTORDEN");
	cantidad_de_recorridos = abb_recorrer(abb_creado, POSTORDEN, (void**)vector, 8);
	pa2m_afirmar( *vector[0] == elemento0, "El elemento esperado se guarda en el vector correctamente.");
	pa2m_afirmar( *vector[1] == elemento6, "El elemento esperado se guarda en el vector correctamente.");
	pa2m_afirmar( *vector[2] == elemento1, "El elemento esperado se guarda en el vector correctamente.");
	pa2m_afirmar( *vector[3] == elemento12, "El elemento esperado se guarda en el vector correctamente.");
	pa2m_afirmar( *vector[4] == elemento10, "El elemento esperado se guarda en el vector correctamente.");
	pa2m_afirmar( cantidad_de_recorridos == 8, "El recorrido devuelve la cantidad correcta de elementos almacenados");

	abb_destruir_todo(abb_creado, NULL);

}

void iterador_interno_abb()
{
	abb_t *abb_creado = abb_crear(comparador);

	int elemento0 = 2, elemento1 = 5, elemento2 = 10, elemento3 = 20; 
	int elemento4 = 30, elemento5 = 15, elemento6 = 7, elemento7 = 40;
	int elemento8 = 16, elemento9 = 8, elemento10 = 18, elemento11 = 14;

	pa2m_afirmar( abb_con_cada_elemento(NULL, INORDEN, son_iguales, &elemento0) == 0, "No puedo aplicar el iterador interno si no existe el arbol.");
	pa2m_afirmar( abb_con_cada_elemento(abb_creado, -1, son_iguales, &elemento0) == 0, "No puedo aplicar el iterador interno si no le envio un recorrido valido.");
	pa2m_afirmar( abb_con_cada_elemento(abb_creado, INORDEN, NULL, &elemento0) == 0, "No puedo aplicar el iterador interno si no le envio una funcion.");

	abb_insertar(abb_creado, &elemento2); abb_insertar(abb_creado, &elemento1); 
	abb_insertar(abb_creado, &elemento3); abb_insertar(abb_creado, &elemento0); 
	abb_insertar(abb_creado, &elemento4); abb_insertar(abb_creado, &elemento5);
	abb_insertar(abb_creado, &elemento6); abb_insertar(abb_creado, &elemento7);
	abb_insertar(abb_creado, &elemento8); abb_insertar(abb_creado, &elemento9);
	abb_insertar(abb_creado, &elemento10); abb_insertar(abb_creado, &elemento11);

	size_t cantidad_de_iteraciones = 0;

	pa2m_nuevo_grupo("Iterando INORDEN");

	cantidad_de_iteraciones = abb_con_cada_elemento(abb_creado, INORDEN, son_iguales, &elemento10);
	pa2m_afirmar( cantidad_de_iteraciones == 9, "Utilizo el iterador interno para recorrer INORDEN y me devuelve la cantidad correcta de invocaciones a funcion.");

	cantidad_de_iteraciones = abb_con_cada_elemento(abb_creado, INORDEN, son_iguales, &elemento2);
	pa2m_afirmar( cantidad_de_iteraciones == 5, "Utilizo el iterador interno para recorrer INORDEN y me devuelve la cantidad correcta de invocaciones a funcion.");

	cantidad_de_iteraciones = abb_con_cada_elemento(abb_creado, INORDEN, son_iguales, &elemento7);
	pa2m_afirmar( cantidad_de_iteraciones == 12, "Utilizo el iterador interno para recorrer INORDEN y me devuelve la cantidad correcta de invocaciones a funcion.");

	pa2m_nuevo_grupo("Iterando PREORDEN");

	cantidad_de_iteraciones = abb_con_cada_elemento(abb_creado, PREORDEN, son_iguales, &elemento1);
	pa2m_afirmar( cantidad_de_iteraciones == 2, "Utilizo el iterador interno para recorrer PREORDEN y me devuelve la cantidad correcta de invocaciones a funcion.");

	cantidad_de_iteraciones = abb_con_cada_elemento(abb_creado, PREORDEN, son_iguales, &elemento2);
	pa2m_afirmar( cantidad_de_iteraciones == 1, "Utilizo el iterador interno para recorrer PREORDEN y me devuelve la cantidad correcta de invocaciones a funcion.");

	cantidad_de_iteraciones = abb_con_cada_elemento(abb_creado, PREORDEN, son_iguales, &elemento11);
	pa2m_afirmar( cantidad_de_iteraciones == 8, "Utilizo el iterador interno para recorrer PREORDEN y me devuelve la cantidad correcta de invocaciones a funcion.");

	pa2m_nuevo_grupo("Iterando POSTORDEN");

	cantidad_de_iteraciones = abb_con_cada_elemento(abb_creado, POSTORDEN, son_iguales, &elemento10);
	pa2m_afirmar( cantidad_de_iteraciones == 6, "Utilizo el iterador interno para recorrer POSTORDEN y me devuelve la cantidad correcta de invocaciones a funcion.");

	cantidad_de_iteraciones = abb_con_cada_elemento(abb_creado, POSTORDEN, son_iguales, &elemento2);
	pa2m_afirmar( cantidad_de_iteraciones == 12, "Utilizo el iterador interno para recorrer POSTORDEN y me devuelve la cantidad correcta de invocaciones a funcion.");

	cantidad_de_iteraciones = abb_con_cada_elemento(abb_creado, POSTORDEN, son_iguales, &elemento7);
	pa2m_afirmar( cantidad_de_iteraciones == 9, "Utilizo el iterador interno para recorrer POSTORDEN y me devuelve la cantidad correcta de invocaciones a funcion.");

	abb_destruir(abb_creado);
}

int main()
{
	pa2m_nuevo_grupo("Pruebas de creación de abb");
	creacion_de_ABB();

	pa2m_nuevo_grupo("Pruebas de insercion de abb");
	insertar_en_ABB();

	pa2m_nuevo_grupo("Pruebas de quitar de abb");
	quitar_en_abb();

	pa2m_nuevo_grupo("Pruebas de buscar elementos de un abb");
	buscar_en_abb();

	pa2m_nuevo_grupo("Pruebas de recorrer abb:");
	recorrer_abb();

	pa2m_nuevo_grupo("Pruebas de iterador interno abb:");
	iterador_interno_abb();

	return pa2m_mostrar_reporte();
}
