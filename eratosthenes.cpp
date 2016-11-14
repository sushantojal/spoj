
#include<stdio.h>
//#include<cmath>


int main()
{
    int tests;
    scanf("%d",&tests);
    int num1;
    int num2;
    int *arr;
    while(tests--)
    {
       // cin>>num1>>num2;
        scanf("%d",&num1);
        scanf("%d",&num2);
       // int arr[num2];
        arr=new int[num2];
        for(int var5=0; var5<num2; var5++)
        arr[var5]=1;

        arr[0]=0;
        arr[1]=0;

     //   int var2= pow(num2,0.5);
        for(int var2=2; (var2*var2)<num2; var2++)
        {
            if(arr[var2]==1)
            {
                int var3=2;
                while((var2*var3)<num2)
                {
                    arr[var2*var3]=0;
                    var3++;
                }
            }
        }
        for(int var4=num1; var4<=num2; var4++)
        {
            if(arr[var4]==1)
            printf("%d\n",var4);
        }
        //delete arr;
        printf("\n");
    }

}
