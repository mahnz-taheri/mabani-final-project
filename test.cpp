#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "clui.h"
using namespace std;

struct date {
   int year;
   int month;
   int day;
};

struct task {
   char* title;
   char* desc;
   int prior;
   date dedline;
};

task* newtask() {
  task* taski;
  taski = new task;
  cout<<"enter a title"<<endl;
  (*taski).title = new char[100];
  cin.getline((*taski).title, 100); //delete kon
  cin.getline((*taski).title, 100);
  clear_screen();
  cout<<"enter description"<<endl;
  cin.getline((*taski).desc, 400);
  clear_screen();
  cout<<"enter prior"<<endl;
  cin>>(*taski).prior;
  clear_screen();
  cout<<"enter dedline year"<<endl;
  cin>>(*taski).dedline.year;
  clear_screen();
  cout<<"enter dedline month"<<endl;
  cin>>(*taski).dedline.month;
  clear_screen();
  cout<<"enter dedline day"<<endl;
  cin>>(*taski).dedline.day;
  clear_screen();
return taski;
}

void newtasks(task** &tasks,task* taski,int &osize) {
     task** a;
     a = new task*[osize+1];
     for(int i=0 ; i < osize + 1 ; ++i) {
       if(i == osize)
         {a[i] = taski;}
       else
         {a[i] = tasks[i];}
     }
     delete[] tasks;
     osize = osize + 1;
     tasks = a;
}

void deltask(task** &tasks,int tasknum,int &osize) {
    --osize;
    task** a;
    a = new task*[osize];
    for(int i=0 ; i < osize ; ++i) {
      if(i==tasknum)
      {
        a[i] = tasks[i + 1];
        ++i;
      }
      else
       {a[i] = tasks[i];}
    }
    delete[] tasks;
    tasks = a;
}
void showt(task* tas) {
  cout<<tas->dedline.year<<"/"<<tas->dedline.month<<"/"<<tas->dedline.day<<" "<<tas->title<<" "<<tas->prior;
}

int main()
{
int sizet = 0;
task** tasks;
tasks = new task*[1000];
newtasks(tasks,newtask(),sizet);
newtasks(tasks,newtask(),sizet);
newtasks(tasks,newtask(),sizet);
deltask(tasks,1,sizet);
for(int i = 0 ; i < sizet ; ++i) {
  showt(tasks[i]);
 }

}
