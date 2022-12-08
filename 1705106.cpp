# include <iostream>
using namespace std;

class Stack{
    int *stck;
    int Top;
    int Size;

public:
    Stack();
    Stack(int size);
    void push_num(int num);
    void push_array(int num[],int n);
    void push_stack(Stack& obj);
    int pop();
    bool isEmpty();
    Stack(const Stack &obj);
    int Exit();
    int getTop();
    int getSize();
    double Similarity(Stack &obj);
    ~Stack();
};

Stack::Stack(){
    stck = new int[10];
    Top = 0;
    Size = 10;
}

Stack::Stack(int size){
    stck = new int[size];
    Top = 0;
    Size = size;
}

bool Stack::isEmpty(){
    return (!Top);
}

void Stack::push_num(int num){
    if (Top == Size) {

        int a[Size],t,i;
        t=Size;
        for(i=0;i<Size;i++) a[i]=stck[i];
        delete []stck;
        Size+=10;

        stck= new int[Size];
        for(i=0;i<t;i++) stck[i]=a[i];
        stck[Top++] = num;
    }
    else stck[Top++] = num;
}

void Stack::push_array(int num[],int n){

    int i,j;
    for(i=0;i<n;i++){

         if (Top == Size) {
            int a[Size],t;
            t=Size;
            for(j=0;j<Size;j++) a[j]=stck[j];
            delete []stck;
            Size+=10;

            stck= new int[Size];
            for(j=0;j<t;j++) stck[j]=a[j];
            stck[Top++] = num[i];
         }
        else stck[Top++] = num[i];
    }
}

void Stack::push_stack(Stack& obj){

    while(obj.getSize()){
        if (Top == Size) {
            int a[Size],t,i;
             t=Size;
             for(i=0;i<Size;i++) a[i]=stck[i];
             delete []stck;
             Size+=10;

            stck= new int[Size];
            for(i=0;i<t;i++) stck[i]=a[i];
            stck[Top++] = obj.pop();

        }
        else stck[Top++] = obj.pop();
    }

}

int Stack::pop(){
    static int t=0;
    int val = -1;
    if (Top == t){
        cout << "Stack is empty" << endl;
    }
    else{
        val = stck[t++];
    }
    return val;
}

int Stack::getTop(){
    int t;
    t=Top-1;
    return stck[t];
}

int Stack::getSize()
{
    return Top;
}

double Stack::Similarity( Stack &obj)
{
    double avgsize,sscore;
    int c=0,t;
    avgsize=(this->getSize()+obj.getSize())/2.0;
    t=this->Top;
    while(this->getSize()&&obj.getSize())
    {
        if(this->stck[--t]==obj.pop()) c++;
    }

    sscore=c*1.0/avgsize;
    return sscore;
}

Stack::Stack(const Stack &obj)
{
    stck=new int[Size];
    *stck=*obj.stck;
}
int Stack::Exit(){
    while(this->getSize()){
        cout<<this->pop()<<" ";
    }
    return 1;
}

Stack::~Stack(){
    delete[] stck;
}

int main(){

   int c,n,i,t=0,m;
   Stack mainStack;

   while(!t){

    cout<<"1:	Push an element"<<endl;
    cout<<"2:	Push an array"<<endl;
    cout<<"3:	Push a stack"<<endl;
    cout<<"4:	Pop"<<endl;
    cout<<"5:	Top"<<endl;
    cout<<"6:	Size"<<endl;
    cout<<"7:	Similarity"<<endl;
    cout<<"8:	Exit"<<endl;

    cin>>c;

    if(c==1){
        cin>>n;
        mainStack.push_num(n);

    }
    else if(c==2){
        cout<<"Enter the number of elements of the array:";
        cin>>n;
        int array[n];
        cout<<"Enter the elements of the array:";
        for(i=0;i<n;i++) cin>>array[i];
        mainStack.push_array(array,n);
    }
    else if(c==3){
        cout<<"Enter the number of elements of the stack:"<<endl;
        cin>>n;
        Stack S;
        cout<<"Enter the elements of the stack:";
        for(i=0;i<n;i++)
        {
            cin>>m;
            S.push_num(m);
        }
        mainStack.push_stack(S);
    }
    else if(c==4){
       cout<<mainStack.pop()<<endl;

    }
    else if(c==5){
        cout<<mainStack.getTop()<<endl;
    }
    else if(c==6){
        cout<<mainStack.getSize()<<endl;
    }
    else if(c==7){
        Stack istack;
        cout<<"Enter the number of elements of the stack:";
        cin>>n;

        cout<<"Enter the elements of the stack:";
        for(i=0;i<n;i++)
        {
            cin>>m;
            istack.push_num(m);
        }
        cout<<"Similarity Score :"<<mainStack.Similarity(istack)<<endl;


    }
    else if(c==8){
        t= mainStack.Exit();
    }


   }
    return 0;
}
