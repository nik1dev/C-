/* задача: 
Сформировать матрицу В путем вычеркивания строки и столбца
матрицы А, на пересечении которых находится максимальный элемент
матрицы А. Определить количество строк, в которых есть нули, и 
записать в обратном порядке главную диагональ матрицы.*/

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{   setlocale(0, "rus");
    int i, j, a, b, s;
    i=0;
float A[5][5];
float M[25];
cout<<"Выберите сбособ ввода матрицы А."<<endl;
cout<<"Для ввода матрицы случайными числами введите 1"<<endl;
cout<<"Для ввода матрицы самостоятельно введите 2"<<endl;
cout<<"Для ввода матрицы из файла введите 3"<<endl;
int p;
cin>>p;

if ((p!=1) && (p!=2) && (p!=3)) {cout<<"Выбрано невозможное действие."<<endl; exit(1);}

if (p==1) { for (i=0; i<5; i++)
 { for (j=0; j<5; j++)
  { A[i][j]=rand()/100;
  
  }
  }
}

   if (p==2) {
   for (i=0; i<5; i++)
 { for (j=0; j<5; j++)
  { cin>>A[i][j];
  
  }
 }
 
}    
 
    int r=0;

    if (p==3) 
    {   ifstream file;
     file.open ("text.txt");
    if (!file)  { cout<<"Не удалось открыть файл.";}
    
    
   for(file>>s; !file.eof(); file>>s)
   { M[i]=s; i++; }



for (i=0; i<5; i++)
 { for (j=0; j<5; j++)
  {  A[i][j]=M[r]; r++;
    }
 } 

}


cout<<"Данные матрицы А:"<<endl;
for (i=0; i<5; i++)
 { for (j=0; j<5; j++)
  { cout<<A[i][j]<<"        ";
  
  }
  cout<<" "<<endl;
  }
 
float max=-100000;  
for (i=0; i<5; i++)
 { for (j=0; j<5; j++)
  { if (A[i][j]>max) { max=A[i][j]; }
  }
  
  }
  
cout<<"Максимальный элемент матрицы А:  "<<max;    
for (i=0; i<5; i++)
 { for (j=0; j<5; j++)
  { if (A[i][j]==max) {a=i; b=j;}
 }
 } 
 cout<<"  "<<endl; 
 cout<<"Номера максимального элемента матрицы А: "<<"("<<a<<";"<<b<<")"<<endl;
 
 
int k=0; 
      int m=0; 
for (i=0; i<5; i++)
 { for (j=0; j<5; j++)
  { if (A[i][j]==0) { k++; }
      
  }
  if(k!=0) {m++;} 
  k=0;
  }
  
cout<<"Количество строк, в которых есть нули:  "<<m<<endl;  
 
float B[5][5];

for (i=0; i<5; i++)
 { for (j=0; j<5; j++)
  { if ((i==a) || (j==b)) {B[i][j]=0;}
      else { B[i][j]=A[i][j]; }
 }
 }
 
 cout<<"Данные матрицы Б:"<<endl;
 for(i=0; i<5; i++)
 { for (j=0; j<5; j++)
  { cout<<B[i][j]<<"     ";
  
  }
  cout<<" "<<endl;
  }
int q;  
   for (i=0; i<3; i++)
       { q=A[i][i];
     A[i][i]=A[4-i][4-i];
 A[4-i][4-i]=q;
   }
        
cout<<"Данные матрицы А с обратной диагональю:"<<endl;
    
for (i=0; i<5; i++)
 { for (j=0; j<5; j++)
  { cout<<A[i][j]<<"        ";
    }
  cout<<" "<<endl;
  }  
return 0;

}