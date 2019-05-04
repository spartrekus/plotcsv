



//////////////////////////////////////////
#include <stdio.h>
#if defined(__linux__) //linux
#define MYOS 1
#elif defined(_WIN32)
#define MYOS 2
#elif defined(_WIN64)
#define MYOS 3
#elif defined(__unix__) 
#define MYOS 4  // freebsd
#define PATH_MAX 2500
#else
#define MYOS 0
#endif

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>



////////////////////////////////////////
int main( int argc, char *argv[])
{
   int i ; 
   if ( argc >= 2)
   {
          for( i = 1 ; i < argc ; i++) 
	    printf( "%d/%d: %s\n", i, argc-1 ,  argv[ i ] );
   }

   char cmdi[PATH_MAX];
   if ( argc >= 2)
   {
       for( i = 1 ; i < argc ; i++) 
       {
	 printf( "Plot %d/%d: %s\n", i, argc-1 ,  argv[ i ] );
         strncpy( cmdi , "  " , PATH_MAX );
         strncat( cmdi , " gnuplot -p -e " , PATH_MAX - strlen( cmdi ) -1 );
         strncat( cmdi , " \"" , PATH_MAX - strlen( cmdi ) -1 );
         strncat( cmdi , " plot '" , PATH_MAX - strlen( cmdi ) -1 );
         strncat( cmdi , argv[ i ] , PATH_MAX - strlen( cmdi ) -1 );
         strncat( cmdi , "'  using 1:2 with points lt 1 pt 1 " , PATH_MAX - strlen( cmdi ) -1 );
         strncat( cmdi , "\"  " , PATH_MAX - strlen( cmdi ) -1 );
         printf( "CMD: %s\n", cmdi );
         system( cmdi );
       }
    }

    return 0;
}

