#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<signal.h>
#include<sys/types.h>
#include<unistd.h>
#include<ctype.h>
#include<string.h>

void histogramcalculator(char string[100]){
        int count=0;
        int frequency[26]={0};
        int index;

        if(!strcmp(string, "")) {
                return;
        }

        while(string[count]!='\0'){
                //if(string[count]>='A' && string[count]<='Z'){
                        //tolower(string[count]);
                        //index=string[count]-'a';
                        //frequency[index]++;
                //}
                if((string[count]>='a' && string[count]<='z')){
                        index=string[count]-'a';                                  //GENERATION OF HISTOGRAM LINE BY LINE AND ELEMINATING TESTCASES FOR GETTING OUTPUT.
                        frequency[index]++;
                }
                if((string[count]>='A' && string[count]<='Z')){
                        index=string[count]-'A';
                        frequency[index]++;
                }
                count++;
        }
        printf("{");
        for(int i=0;i<26;i++){
                if(i!=25){
                        printf("%c:%d, ",i+'a',frequency[i]);
                }
                else{
                        printf("%c:%d",i+'a',frequency[i]);
                }
        }
        printf("}");
}
FILE*filepointer=NULL;
void *filereading(){
        //FILE *filepointer=NULL;
        char linewise[100];
        //filepointer=fopen("sample1.txt","r+");
        if(filepointer==NULL){
                printf("Error,Can't open file\n");
                return 0;
        }
        fgets(linewise,sizeof(linewise),filepointer);                                                                       //IDEA IS USING GLOBAL FILE POINTER AND JUST READING LINE BY LINE BY USING FGETS WHICH AUTOMATICALLY                                                                            //INCREMENTS FILEPOINTER. AFTER READING A LINE THAT LINE IS MADE INTO CHARACTER ARRAY AND SENT TO HISTOGRAMCALCULATOR FUNCTION.
        printf("%s", linewise);
        //tolower(linewise[0]);
        //int i=0;
        //while(linewise[i]!='\0'){
                //tolower(linewise[i]);
                //i++;
        //}
        histogramcalculator(linewise);
}

int main(int argc,char * argv[]){
       filepointer=fopen("test","r+");
       pthread_t th[3];
       int k;
       //int numberofthreads;
      // printf("How many threads you want to have for generating histogram?\n ");
      // scanf("%d", &numberofthreads);
       if (argc!=2){
               printf(" You must enter number of threads beside ./a.out\n");
               return 0;                                                                //CHECKING VALIDITY OF NUMBER OF THREADS BASED ON THE GIVEN COMMAND INPUT.
       }
       int noofthreads= atoi(argv[1]);
       if(noofthreads!=3){
            printf("Enter number of threads in range 2 to 4\n");
         return 0;
       }

       while(!feof(filepointer)) {
       for(int i=0;i<3;i++){
              k = i;
             // printf("%d", feof(filepointer));
              if(!feof(filepointer))
               pthread_create(th+i,NULL,&filereading,NULL);                            //3 THREADS ARE CREATED SIMULTANEOUSLY TO READ 3 LINES AT A TIME AND 3 THREADS MULTI THREADINGLY GENERATES HISTOGRAM FOR EACH LINE.
                else {
                     break;


              }
              // printf("}");

                printf("\n");
               sleep(0.00001);

       }
       for(int i=0;i<3;i++){
               if(k--)
                       break;                                                         //STOPS MAIN UNTIL THREADS MULTI THREADINGLY DONE THEIR PURPOSES.
               pthread_join(th[i],NULL);
       }
       }

       return 0;

}
