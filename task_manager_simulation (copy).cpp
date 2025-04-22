#include<bits/stdc++.h>
using namespace std;


class process{

public:
// static int global_id;
// This tells the compiler "This class has a static variable named global_id".
// It does not allocate memory for global_id.
// Why is static shared across all instances?

// When you declare a variable as static in a class, it is not stored inside each object. Instead:

//     It is stored in a single memory location shared by all instances.
//     All objects access the same copy of the static variable.
//     It persists for the entire program execution
static inline int global_id=0;//this command is for c++17 and later to make the declaration and give it a value in the same line
int id;
string name;
int priority;
process (){

};

process(string n,int p){

   id=  global_id++;
     this->name=n;
     this->priority=p;
}
};


class TaskManager{
public:
queue<process>q;
stack<process>s;

bool operator()(process p1,process p2){
    return p1.priority>p2.priority;
}

void add_queue(process p){
q.push(p);
cout<<"added successfully\n";
}



void remove_queue(process p){
cout<<"process with id: "<<p.id<<"and name: "<<p.name<<"and priority : "<<p.priority<<"is executed\n";
q.pop();
cout<<"removed successfully\n";
}

void view_next_process_queue(){
    process next=q.front();
   cout<<"the next process is with id: "<<next.id<<"and name: "<<next.name<<"and priority : "<<next.priority<<"is executed\n";

   
    }


void view_next_process_stack(){
    auto next1=s.top();
   cout<<"the next process is with id: "<<next1.id<<"and name: "<<next1.name<<"and priority : "<<next1.priority<<"is executed\n";

   
    }

void add_stack(process p){
s.push(p);

cout<<"added successfully\n";
}

void remove_stack(process p){
cout<<"process with id: "<<p.id<<"and name: "<<p.name<<"and priority : "<<p.priority<<"is executed\n";
s.pop();
cout<<"removed successfully\n";
}


void display(){
    int num1=1;
    int num2=1;
while(!q.empty()){
    process p1=q.front();
    cout<<"process number "<< num1<<" in queue is with id: "<<p1.id<<"and name: "<<p1.name<<"and priority : "<<p1.priority<<"\n";
    q.pop();
    num1++;
}

while(!s.empty()){
    process p2=s.top();
    cout<<"process number "<< num2<<"in stack is with id: "<<p2.id<<"and name: "<<p2.name<<"and priority : "<<p2.priority<<"\n";
s.pop();
num2++;
}
}

private:

};
// int process ::global_id=0;// This actually allocates memory and initializes the variable

int main(){
int num;
string name;
int priority;
process *p;
TaskManager task;
while(1){
cout<<"to create new process press 1\n to Add created process to stack press 2\n to add created process to queue press 3\n to show process press 4\n to view next process in stack press 5\n to view next process in queue press 6 :";
cin>>num;

//declaration of variables must be before switch or the compiler will give me error

switch(num){
case 1:
cout<<"to create new process enter its name and priority\n";
cout<<"enter its name : ";
cin>>name;
cout<<"\n";
cout<<"enter its priority\n";
cin>>priority;

p=new process(name,priority);//without new the new process will override the created processes
cout<<"process created successfully\n";
break;

case 2:

task.add_stack(*p);


break;

case 3:
task.add_queue(*p);

break;

case 4:
task.display();

break;
case 5:
task.view_next_process_stack();

break;

case 6:
task.view_next_process_queue();


break;

}

}
}
