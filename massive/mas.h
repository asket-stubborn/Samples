#include <ostream>
#include <istream>
#include <iostream>

class Darrbuf {
public :
    int *arr;
    int n;
    Darrbuf(int n1, bool flag) {
        arr = (int *) (malloc(sizeof(int) * n));
        for (int i = 0; i < n; i++) {
            arr[i] = *((int *) malloc(sizeof(int *)));
            n=n1;
        };
    }; //выделяем память

    Darrbuf(int mem,char flag) {
        arr = (int *) malloc(sizeof(int) * mem);
        for (int i = 0; i < sizeof(*arr); i++)
            arr[i] = *((int *) malloc(sizeof(int)));
     n=*arr/sizeof(int);
    };

    explicit Darrbuf(int mem = 1, int n = 10) //параметры по умолчанию. Выделяем память путём Си, так веселее
    {
        arr = (int *) malloc(sizeof(int) * mem * 10);
        for (int i = 0; i < n; i++)
            arr[i] = *((int *) malloc(sizeof(int)));
        n=10;
    };

    int return_mas() {
        return *arr;
    };

    ~Darrbuf() {
        free(arr);
    }

    Darrbuf &operator=(const Darrbuf &rhs) {
        if (this != &rhs) {
            free(arr);
            int n1 = rhs.n;
            *arr = *((int*)malloc(sizeof(int) * n1)); //в стиле с++

            for (int i = 0; i != rhs.n; ++i)
                arr[i] = rhs.arr[i];
        }
        return *this;
    };
    bool operator==(const Darrbuf &rhs) const
    {
        if( n != rhs.n ) return false;
        for (int i=0; i < n; i++){
            if ( arr[i] != rhs.arr[i] ) return false;
        }
        return true;
    }
};



class DArray{
private:
    int *mas;
    int n;
public :
    Darrbuf *d = new Darrbuf();
    DArray(int n1, bool flag){
        d = new Darrbuf(n,flag);
        *mas=(d->return_mas());
        n=n1;
    };
    DArray(int mem,char buf){
        d= new Darrbuf(mem,'2');
        *mas=(d->return_mas());
        n=*mas/sizeof(int);
    }
   explicit DArray(){
        d = new Darrbuf();
        *mas=(d->return_mas()); // эта звездочка разыменование
        n=10;
    }
    ~DArray();
    DArray(const DArray&){
         *mas= *mas;
    };
    int findkey(int val){
      for(int i=0;i<sizeof(mas);i++){
         if (mas[i]==val)
         { return i;};
      }
    return -1;};

    Mas(int* arr,int n1){
        for(int i=0;i<n;++i){
            mas[i]=arr[i]; }
        n1=n;
    };
    void Sort(){ //выпендриваемся и делаем сортировку пузырьком
        int temp;
        for (int i = 0; i < sizeof(mas) - 1; i++) {
            for (int j = 0; j < sizeof(mas) - i - 1; j++) {
                if (mas[j] > mas[j + 1]) {
                    // меняем элементы местами
                    temp = mas[j];
                    mas[j] = mas[j + 1];
                    mas[j + 1] = temp;
                }
            }
        }
        for (int i = 0; i < sizeof(mas); i++) {
            std::cout << mas[i] << " ";
        }
        std::cout << std::endl;

    };
    void addkkey (int ix,int key){
      if (ix <=n)
        mas[ix]=key;
    };

    DArray operator - (const int j) {
        int tmp=0;
        for (int i = 0; i < n; ++i) tmp = mas[i];
        for (int i = 0; i < n-1; ++i) if (mas[i]==j) tmp = mas[i+1];
        for (int i=0;i<n-1;++i) mas[i]=tmp;

        };
    void Update(int minRange, int maxRange, int oder){
         d= new Darrbuf(n,true);
         *mas = d->return_mas();
         if (oder==0)
             for (int i = 0; i < n; ++i)
             {
                 mas[i] = rand();

             }
         if (oder==1)
             for (int i=0;i<n;++i) {
                 int j = rand();
                 if (i==0) mas[i]=j;
                 if (mas[i-1]<j)  mas[i]=j;
             }
         if (oder==-1)
             for (int i=0;i<n;++i) {
                 int j = rand();
                 if (i=0) mas[i]=j;
                 if (mas[i-1]>j)  mas[i]=j;
             }
     };


    DArray& operator=(const DArray &rhs)
{
    if (this != &rhs)
    {
        free(mas);
        int size = rhs.n;
        mas =((int*)malloc(sizeof(int)*size)); //в стиле с

        for (int i = 0; i != rhs.n; ++i)
            mas[i] = rhs.mas[i];
    }
    return *this;
}
DArray& operator+(const int a)
{
    *mas=*((int*)realloc((void*)(*mas),sizeof(int)*(n+1)));//сложная структура релокации памяти, но она нужна.
    n=n+1;
    mas[n]=a;

    return *this;
}
DArray& operator+=(const int a)
{
    *mas=*((int*)realloc((void*)(*mas),sizeof(int)*(n+1)));
    n=n+1;
    mas[n]=a;

    return *this;
}
bool operator==(const DArray &rhs) const
{
    if( n != rhs.n ) return false;
    for (int i=0; i < n; i++){
        if ( mas[i] != rhs.mas[i] ) return false;
    }
    return true;
}

int max (){
    int max=0;
    for(int i=0;i<n;i++){
        if (mas[i]>max)  max=mas[i];
    }
}

int min (){
    int min=99999999;
    for(int i=0;i<n;i++){
        if (mas[i]<min)  min=mas[i];
    }
}
friend std::ostream& operator << (std::ostream& output,  const DArray rhs){
    int i;

    for (i=0; i<rhs.n; i++)
    {
        output<<rhs.mas[i]<<" ";
        if ((i+1)%10==0)
            output<<std::endl;
    }
    if (i%10==0)
        output<<std::endl;
    return output;
};


friend std::istream& operator >> (std::istream& input, DArray& rhs){

for (int i=0; i<rhs.n; i++)
input>>rhs.mas[i]; // !!!здесь добавил [i]
return input;
};




};


