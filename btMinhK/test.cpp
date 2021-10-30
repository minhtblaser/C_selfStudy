#include <string.h>
#include <stdio.h>

char string1[] = "21/4/1975";
char string2[] = "21/4/2002";

int main( void )
{
   char tmp[20];
   int result;

   printf( "Compare strings:\n   %s\n   %s\n\n\n", string1, string2 );
   result = strcmp( string1, string2 );

   if( result > 0 )        strcpy( tmp, "greater than" );
   else if( result < 0 )   strcpy( tmp, "less than" );
   else    strcpy( tmp, "equal to" );

   printf( "   strcmp:   String 1 is %s string 2\n\n", tmp );

   return 0;
}