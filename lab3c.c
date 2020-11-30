#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

#define LENI sizeof(int)


// Znahodjenna medianu
float fmedian(int *a,int len)
{
  int min;

for (int j=0;j<len;j++)
  {
    for (int i=j;i<len;i++)
      {
        if (*(a+j*LENI) < *(a+i*LENI))
        {
          min=*(a+j*LENI);
          
          *(a+j*LENI)=*(a+i*LENI);

          *(a+i*LENI)=min;  
        }
      }
    /*  printf("\n");
     for (int i=j;i<len;i++)
      {
       // printf("%i - %i \n",i+1,*(a+i*LENI));

      } */
  }
    float m = *(a+((len-1)/2 )*LENI);
    printf("Median: %.4f\n",m);
    return m;
}


// Znahodjenna cepednbogo znachenna
float favarage(int a[],int len)
    {
      float S= 0;
      for (int i = 0 ; i<len; i++)
        {
          //S+= *(a+i*LENI);
          S+= a[i*LENI];
        }
      printf("Avarage: %.4f\n",S/len);
      return (S/len);
    }


void main()
  {
    //Setting the coefficient for the array's elements(for random) 
        float n = 100;
        int len;
     
        printf("Введіть довжину масиву l:\n");
        scanf("%i",&len);
    
    if (len%2==1) 
      {

            srand(time( NULL ));    
            
        // Zapovnennja
        int *ptr  =(int*)malloc(len*LENI);
        int elem;
        
        for (int i = 0; i < len; i++) 
            {
              elem = ((float)rand()/(float)(RAND_MAX) * n);
              *(ptr+i*LENI)= elem;
              printf("%i - %i \n",i+1,elem);
            }   

        float med = fmedian(ptr,len);
        float av = favarage(ptr,len);

            if (av > med) 
                {
                  printf("Середнє значення більше за Медіану\n");
                }
            
            else if (med >av) 
                {
                  printf("Медіанa більшa за Середнє значення\n");
                }
            
            else if (med == av) 
                {
                  printf("Same\n");
                }   
            free(ptr);
      }
        else 
         EXIT_FAILURE;
  }
//empty 
