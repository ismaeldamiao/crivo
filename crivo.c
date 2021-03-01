/* *****************************************************************************
   Programa para calcular os numeros primos ate um dado valor p>0 usando
   o crivo de Eratostenes.

   clang crivo.c -lm -o crivo && ./crivo 8
   gcc crivo.c -lm -o crivo && ./crivo 8
   *****************************************************************************
   E-mail: ismaellxd@gmail.com
   Site: https://ismaeldamiao.github.io/
   *****************************************************************************
   Copyright © 2020 Ismael Damião

   Permission is hereby granted, free of charge, to any person obtaining a copy 
   of this software and associated documentation files (the “Software”), to 
   deal in the Software without restriction, including without limitation the 
   rights to use, copy, modify, merge, publish, distribute, sublicense, and/or 
   sell copies of the Software, and to permit persons to whom the Software is 
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in 
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
   IN THE SOFTWARE.
***************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

//#define OUTPUT TRUE
#define OUTPUT FALSE

#define BENCHMARK TRUE
//#define BENCHMARK FALSE

int main(int argc, char **argv){
   long int i, j, p, *v;
   #if BENCHMARK
   clock_t tempo;
   #endif

   if(argc == 1){
      fprintf(stderr, "Informe o limite maximo como argumento\n");
      return 1;
   }else{
      #if BENCHMARK
      p = (long int)pow(1.0e1, atol(argv[1]));
      #else
      p = (long int)atoi(argv[1]);
      #endif
      /* Alocar memoria para a array */
      v = (long int*)malloc((size_t)((p+1) * sizeof(long int)));
   }

   /* ***
      A array eh uma lista-verdade, todas as posicoes marcadas com TRUE
      sao numeros primos em potencial
   *** */
   for(i = 1; i <= p; i++) v[i] = TRUE;

   #if OUTPUT
   fprintf(stdout, "Os primos ate %ld sao:\n1 ", p);
   #endif

   #if BENCHMARK
   tempo = clock();
   #endif

   /* ***
      A rotina a seguir se trata de um algoritmo para eliminar todos os numeros
      que nao sao primos da lista-verdade marcando-os com FALSE.
      Se trata do Crivo de Eratostenes.
   *** */
   for(i = 2; i <= p; ++i){
      /* i eh primo? */
      if(v[i]){
         /* Se sim, */

         #if OUTPUT
         /* escreva ele */
         fprintf(stdout, "%ld ", i);
         #endif

         /* e remova os multiplos dele da lista-verdade pois nao sao primos */
         for(j = i; j <= p; j += i) v[j] = FALSE;
      }
   }

   #if OUTPUT
   fprintf(stdout, "\n");
   #endif

   #if BENCHMARK
   tempo = (clock() - tempo)/CLOCKS_PER_SEC * (clock_t)1.0e3;
   fprintf(stdout, "Tempo para executar o crivo: %.3e ms\n", (double)tempo);
   #endif

   return 0;
}
