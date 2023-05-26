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
  change_color(5);
  cout<<"enter a title"<<endl;
  (*taski).title = new char[100];
  cin.getline((*taski).title, 100); //delete kon
  cin.getline((*taski).title, 100);
  clear_screen();
  cout<<"enter description"<<endl;
  (*taski).desc = new char[400];
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
  reset_color();
  clear_screen();
return taski;
}

void deltask(task** &tasks,int tasknum,int &osize) {
    --osize;
    task** a;
    a = new task*[osize];
    for(int i=0 ; i < osize ; ++i) {
      if(i==tasknum)
      {
       for(int j = i ; j < osize ; ++j)
          { a[j] = tasks[j + 1];}
          break;
      }
      else
       {a[i] = tasks[i];}
    }
    delete[] tasks;
    tasks = a;
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

 void showt(task* tas) {
   change_color(7);
   cout<<tas->dedline.year<<"/"<<tas->dedline.month<<"/"<<tas->dedline.day<<"  "<<tas->title<<"  "<<tas->prior<<endl;
   reset_color();
 }

task** sort(task** &tasks,int size) {
  for(int i = 0 ; i < size ; ++i) {
   for(int j = 0; j < (size - i - 1) ; ++j)
     if((*tasks[j+1]).prior > (*tasks[j]).prior)
        swap(tasks[j], tasks[j+1]);
 }
 return tasks;
}

char returnshow(task** tasks,int sizet) {
  for(int i = 0 ; i < sizet ; ++i) {
    showt(tasks[i]);
   }
  cout<<"a)sort tasks"<<endl<<"b)see a task"<<endl<<"c)delete a task"<<endl;
  char d;
  cin >> d;
  return d;
}

void showmenu() {
 change_color(6);
 cout<<"M : make new task"<<endl<<"S : show tasks"<<endl;
 reset_color();
}

int main()
{
  init_clui();
  change_color(3);
  cout << "HELLO WELCOME TO TASK MANAGER"<<endl;
  reset_color();
  char x;
  cout<<"choose a letter:"<<endl;
  showmenu();
  delay(3000);
  cin >> x;
  int sizet = 0;
  task** tasks;
  tasks = new task*[1000];
  clear_screen();
  while(x == 'M')
  {
    newtasks(tasks,newtask(),sizet);
    clear_screen();
    showmenu();
    cin >> x;
    clear_screen();
  }
  if(x == 'S')
  {
    for(int i = 0 ; i < sizet ; ++i) {
      change_color(6);
      showt(tasks[i]);
      reset_color();
     }
    cout<<"a)sort tasks"<<endl<<"b)see a task"<<endl<<"c)delete a task"<<endl;
    char d;
    cin >> d;

    if(d == 'a')
    {
      delay(2000);
      clear_screen();
      sort(tasks,sizet);
      for(int i = 0 ; i < sizet ; ++i) {
        change_color(5);
        showt(tasks[i]);
        reset_color();
       }
    }

    if(d == 'b')
    {
      int tasknum;
      change_color(6);
      cout<<"enter your task number"<<endl;
      reset_color();
      cin>>tasknum;
      clear_screen();
      change_color(3);
      cout << tasks[tasknum]->prior <<"  "<< tasks[tasknum]->title <<"  "<< tasks[tasknum]->desc<<endl<<endl;
      reset_color();
      delay(2000);
      cout<<"Do you want to return? 1)yes  2)no"<<endl;
      int ask;
      cin>>ask;
      clear_screen();
      if(ask == 1)
       {if(returnshow(tasks,sizet) == 'a')
         {
          delay(2000);
          clear_screen();
          sort(tasks,sizet);
          for(int i = 0 ; i < sizet ; ++i) {
          showt(tasks[i]);
           }
          }
        if(returnshow(tasks,sizet) == 'b')
        {
         int tasknum;
         change_color(6);
         cout<<"enter your task number"<<endl;
         reset_color();
         cin>>tasknum;
         delay(2000);
         clear_screen();
         cout << tasks[tasknum]->prior <<"  "<< tasks[tasknum]->title <<"  "<< tasks[tasknum]->desc;
        }
        if(returnshow(tasks,sizet) == 'c')
        {
         int tasknum;
         cout<<"enter your task number"<<endl;
         cin>>tasknum;
         deltask(tasks,tasknum,sizet);
         for(int i = 0 ; i < sizet ; ++i) {
           showt(tasks[i]);
          }
         }
       }
      }
    if(d == 'c')
    {
      int tasknum;
      change_color(1);
      cout<<"enter your task number"<<endl;
      reset_color();
      cin>>tasknum;
      deltask(tasks,tasknum,sizet);
        delete[] tasks[tasknum]->title;
        delete[] tasks[tasknum]->desc;
      for(int i = 0 ; i < sizet ; ++i) {
        showt(tasks[i]);
       }
    }
  }
  for(int i = 0 ; i < sizet ; ++i) {
      delete[] tasks[i]->title;
      delete[] tasks[i]->desc;
  }
  delete[] tasks;
return 0;
}
