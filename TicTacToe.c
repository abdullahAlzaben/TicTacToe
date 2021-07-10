#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define R 5

void print(char map[R][R]); // print the map
void userinput(int a , char map[R][R]); // place user input
void cpuinput( char map[R][R] ); // place CPU input
void checkwinner(char map[R][R] , char a); // to know the winer
void out(char a); // end program and print winner
void check(int a , int *b,char map[R][R]); // check if user input is valid or not
void draw(char map[R][R]); // check if there is a draw
int place(int a,char map[R][R]); // check if place is taken or not for the user

int moves[8]; // to record player and cpu mvoies
int mov=0; // counter for array

int main() {
   

   char map[R][R]= {  {'1','|','2','|','3'},
                      {'-','-','-','-','-'},
                      {'4','|','5','|','6'},
                      {'-','-','-','-','-'},
                      {'7','|','8','|','9'}  };
int num;
 printf("\n");
print(map); 

  while(1){
     
  printf("User turn: ");
  check(scanf("%d",&num),&num,map);
  userinput(num,map);
  print(map);
  checkwinner(map,'X');
  draw(map);
   printf("CPU turn: ");
  cpuinput(map);
  print(map); 
  checkwinner(map,'O'); 
  draw(map);
   }

   return 0;
}


void print(char map[R][R] ){
    printf("\n");
   for (int i = 0; i <R; ++i){
      for (int b = 0; b <R; b++){
	  printf("%c ", map[i][b]);
  
   }
     printf("\n");
   }
   printf("\n");
}


void userinput(int a , char map[R][R] ){

   for (int i = 0; i <R; ++i){
      for (int b = 0; b <R; b++){

      if (map[i][b]==a+'0' && map[i][b]!='X' && map[i][b]!='O') { 
      map[i][b]='X';  moves[mov++]=a; return; }
      
      }
   }
 
}

void cpuinput( char map[R][R] ){

srand (time(NULL)); // get new number every time the program runs

   int out=1;
   while(out){
int a =rand() % (9 + 1 - 0) + 0;

   for (int i = 0; i <R; ++i){
      for (int b = 0; b <R; b++){

      if (map[i][b]==a+'0' && map[i][b]!='X' && map[i][b]!='O'){

      map[i][b]='O'; 
      moves[mov++]=a;
      printf("%d\n",a); // to show the cpu move 
           out=0;    
      }
      }
   }
    
   }
  
}

void checkwinner(char map[R][R] , char a){
  
  if(map[0][0] == map[0][2] && map[0][2]== map[0][4] ){ // row 1
      out(a);}

    else if(map[2][0] == map[2][2] && map[2][2] == map[2][4] ) // row 2
         out(a);

      else if(map[4][0] == map[4][2] && map[4][2] == map[4][4] ) // row 3
           out(a);

  else if(map[0][0] == map[2][0] && map[2][0] == map[4][0] ) // Column 1
       out(a);

    else if(map[0][2] == map[2][2] && map[2][2] == map[4][2] ) // Column 2
           out(a);

      else if(map[0][4] == map[2][4] && map[2][4] == map[4][4] ) // Column 3
             out(a);



      else if(map[0][0] == map[2][2] && map[2][2] == map[4][4] ) 
          out(a);
      else if(map[0][4] == map[2][2] && map[2][2] == map[4][0] ) 
             out(a);


      
     
      

}

void out(char a){
   printf(" %c is the winner ",a);
   exit(0);
   
}

void check(int a, int *b,char map[R][R]){
   while(getchar() != '\n'); // to clean the buffer
  char buffer[100];
       
   while (1)
   {

      if(a==0 || *b>9 || *b<=0){
         
         printf("please Enter a valed number \n");
    
          fgets(buffer, 99, stdin);
       a=sscanf(buffer, "%d", b); 
        
      }
        
      else if(place(*b,map)){
          if(a!=0)
         printf("this place is taken \n");
       
         fgets(buffer, 99, stdin);
       a=sscanf(buffer, "%d", b);
        
        
         

      }
      else 
      return; 
        

     
}}

void draw(char map[R][R]){
   int num=0;
 for (int i = 0; i <R; ++i){
      for (int b = 0; b <R; b++){

      if (map[i][b]=='X' || map[i][b]=='O' )
      num++;

      if(num == 9){
printf("------- Draw -------");
  exit(0);
      }
      }
   }

}

int place(int a,char map[R][R] ){
int i=0;
   while(moves[i]!='\0'){
   if(moves[i]==a)
   return 1;

   i++;
   }
   return 0;
}

